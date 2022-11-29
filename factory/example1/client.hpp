#include "i_creator.hpp"

void Client(const ICreator& creator) {
    std::cout << "Client: Independent from creator class" << creator.Operation() << std::endl;
}