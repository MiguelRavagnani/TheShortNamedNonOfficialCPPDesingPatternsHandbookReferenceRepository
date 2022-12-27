#include <iostream>
#include <string>
#include <memory>

template <typename PolicyA, typename PolicyB>
class Messageria : private PolicyA, private PolicyB {
    public:
    void Format(std::string& param_message) const {
        PolicyA::A(param_message);
        PolicyB::B(param_message);
    }
};

class Default {
protected:
    virtual void A(std::string& param_message) const = 0;
};

class ADefault : public virtual Default {
protected:
    void A(std::string& param_message) const { param_message = "[] " + param_message; }
};

class AExplicit : public virtual Default {
protected:
    void A(std::string& param_message) const { param_message = "[A] " + param_message; }
};

class BDefault : public virtual Default {
protected:
    void B(std::string& param_message) const { param_message = "[] " + param_message; }
};

class BExplicit : public virtual Default {
protected:
    void B(std::string& param_message) const { param_message = "[B] " + param_message; }
};

int main() {
    std::string message_1 = "message_1";
    std::string message_2 = "message_2";

    Messageria<ADefault, BDefault> default_message;
    Messageria<AExplicit, BExplicit> explicit_message;
    
    default_message.Format(message_1);
    explicit_message.Format(message_2);
    std::cout << message_1 << std::endl;
    std::cout << message_2 << std::endl;
}