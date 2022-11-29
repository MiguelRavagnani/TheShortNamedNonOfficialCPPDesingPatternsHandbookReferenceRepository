#include "creator_1.hpp"
#include "creator_2.hpp"
#include "client.hpp"

int main(void) {
    std::cout << "App: Creating with creator 1" << std::endl;
    ICreator* creator_1 = new Creator1();
    Client(*creator_1);

    std::cout << "App: Creating with creator 2" << std::endl;
    ICreator* creator_2 = new Creator1();
    Client(*creator_2);

    delete creator_1;
    delete creator_2;

    return 0;
}