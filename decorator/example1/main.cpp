#include <iostream>
#include <memory>

/* ----------------------------------------------------------------------------------------------------- */

class Component {
public:
    virtual ~Component() {}

    virtual void Format(std::string& param_message) const = 0;
};

/* ----------------------------------------------------------------------------------------------------- */

class ConcreteComponent : public Component {
public:
    void Format(std::string& param_message) const override {}
};

/* ----------------------------------------------------------------------------------------------------- */

class Decorator : public Component {
protected:
    std::shared_ptr<Component> m_decorator;

public:
    Decorator(std::shared_ptr<Component> param_formatter) : m_decorator(param_formatter) {}

    void Format(std::string& param_message) const override {
        this->m_decorator->Format(param_message);
    }
};

/* ----------------------------------------------------------------------------------------------------- */

class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(std::shared_ptr<Component> param_component) : Decorator(param_component) {}

    void Format(std::string& param_message) const override {
        param_message = "[decorator_a] " + param_message;
        Decorator::Format(param_message);
    }
};

/* ----------------------------------------------------------------------------------------------------- */

class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(std::shared_ptr<Component> param_component) : Decorator(param_component) {}

    void Format(std::string& param_message) const override {
        param_message = "[decorator_b] " + param_message;
        Decorator::Format(param_message);
    }
};

/* ----------------------------------------------------------------------------------------------------- */

int main() {
    auto default_component = std::shared_ptr<Component>(new ConcreteComponent);

    default_component = std::shared_ptr<Decorator>(new ConcreteDecoratorA(default_component));
    default_component = std::shared_ptr<Decorator>(new ConcreteDecoratorB(default_component));

    std::string message = "raw";

    default_component->Format(message);

    std::cout << message << std::endl;

    return 0;
}