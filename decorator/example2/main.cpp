#include <type_traits>
#include <memory>
#include <string>
#include <iostream>

/* ----------------------------------------------------------------------------------------------------- */

struct AbstractComponent
{
	AbstractComponent(...) {}

	int m_level;

	void SetLevel(...) {}
};

/* ----------------------------------------------------------------------------------------------------- */

struct MessageData { std::string& m_message; };

/* ----------------------------------------------------------------------------------------------------- */

class Component: public virtual AbstractComponent{
public:

    Component() : AbstractComponent(){;}

    virtual void Format(MessageData param_message)=0;

};

/* ----------------------------------------------------------------------------------------------------- */

class DefaultComponent: public virtual Component{
public:

    DefaultComponent() : Component(){;}

    virtual void Format(MessageData param_message) {}

};

/* ----------------------------------------------------------------------------------------------------- */

template <typename Comp>
class Decorator: public virtual Component{

protected:
    Comp m_component;
public:
    Decorator(Comp m_component): Component(), m_component(m_component){;}
    virtual ~Decorator(){}

    virtual void SetLevel(int param_level){
        m_component.SetLevel(param_level);
    }
};

/* ----------------------------------------------------------------------------------------------------- */

template <typename Comp>
class ConcreteDecorator_A: public virtual Decorator<Comp>{
private:
/**/
public:

    ConcreteDecorator_A(Comp m_component) : Decorator<Comp>(m_component) {}

    virtual ~ConcreteDecorator_A(){}

    virtual void Format(MessageData param_message){
        param_message.m_message = "[decorator_a] " + param_message.m_message;
        this->m_component.Format(param_message);
    }

};

/* ----------------------------------------------------------------------------------------------------- */

template<typename Comp>
class ConcreteDecorator_B: public virtual Decorator<Comp>{
private:
/**/
public:
    ConcreteDecorator_B(Comp m_component) : Decorator<Comp>(m_component) {}

    virtual ~ConcreteDecorator_B(){}

    virtual void Format(MessageData param_message){
        param_message.m_message = "[decorator_b] " + param_message.m_message;
        this->m_component.Format(param_message);
    }

};

/* ----------------------------------------------------------------------------------------------------- */

template<typename Comp>
std::shared_ptr<Component> InitializeAnyComponent(
        std::string param_format, Comp m_component){



    std::shared_ptr<Component> result_scorer;
    if (/* Choose formatter param_format */ true){
        result_scorer = std::shared_ptr<ConcreteDecorator_B<Comp>>(
                 new ConcreteDecorator_B<Comp>(
                         m_component
                 )
             );
    }else{
        result_scorer = std::shared_ptr<ConcreteDecorator_A<ConcreteDecorator_B<Comp>>>(
                new ConcreteDecorator_A<ConcreteDecorator_B<Comp>>(
                    ConcreteDecorator_B<Comp>(
                            m_component
                )
            )
        );
    }

    return result_scorer;
}

/* ----------------------------------------------------------------------------------------------------- */

template <typename S>
using result = typename std::result_of<S>::type;

/* ----------------------------------------------------------------------------------------------------- */

template <template <typename> class E, template <typename> class... D>
struct decorate_impl
{
    template <typename A, typename N = result<decorate_impl<D...>(A)>>
	E<N> operator()(A&& a) const
	{
		return E<N>(decorate_impl<D...>()(std::forward<A>(a)));
	}
};

/* ----------------------------------------------------------------------------------------------------- */

template <template <typename> class E>
struct decorate_impl <E>
{
	template <typename A, typename N = typename std::decay<A>::type>
	E<N> operator()(A&& a) const { return E<N>(std::forward<A>(a)); }
};

/* ----------------------------------------------------------------------------------------------------- */

template <template <typename> class E, template <typename> class... D, typename A>
std::shared_ptr <E<result<decorate_impl<D...>(A)>>>
decorate(A&& a)
{
	return std::make_shared <E<result<decorate_impl<D...>(A)>>>
		(decorate_impl<D...>()(std::forward<A>(a)));
}

/* ----------------------------------------------------------------------------------------------------- */

int main ()
{
	DefaultComponent component;
	std::shared_ptr<Component> ptr =
		decorate<ConcreteDecorator_A, ConcreteDecorator_B>(component);

    std::string raw_message = "raw";
    std::cout << raw_message << std::endl;

    MessageData message_buffer = {raw_message};

    ptr->Format(message_buffer);

    std::cout << raw_message << std::endl;

}
