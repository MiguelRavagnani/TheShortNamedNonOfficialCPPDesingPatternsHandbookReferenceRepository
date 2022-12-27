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

class Component: public virtual AbstractComponent{
public:

    Component() : AbstractComponent(){;}

    virtual void Format(std::string& param_message)=0;

};

/* ----------------------------------------------------------------------------------------------------- */

class DefaultComponent: public virtual Component{
public:

    DefaultComponent() : Component(){;}

    virtual void Format(std::string& param_message) {}

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

    virtual void Format(std::string& param_message){
        param_message = "[decorator_a] " + param_message;
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

    virtual void Format(std::string& param_message){
        param_message = "[decorator_b] " + param_message;
        this->m_component.Format(param_message);
    }

};

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

template <template <typename> class E, typename A>
std::shared_ptr <result<decorate_impl<E>(A)>>
decorate(A&& a)
{
	return std::make_shared <result<decorate_impl<E>(A)>>
		(decorate_impl<E>()(std::forward<A>(a)));
}

/* ----------------------------------------------------------------------------------------------------- */

int main ()
{
	DefaultComponent component;
    
	auto ptr_1 = decorate<ConcreteDecorator_A>(component);

	auto temp = decorate<ConcreteDecorator_B>(*ptr_1);

    std::string raw_message_1 = "raw_1";
    
    std::cout << raw_message_1 << std::endl;

    ptr_1->Format(raw_message_1);

    std::cout << raw_message_1 << std::endl;

}
