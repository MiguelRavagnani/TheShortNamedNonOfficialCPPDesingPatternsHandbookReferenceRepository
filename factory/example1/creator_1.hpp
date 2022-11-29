#ifndef _CREATOR_1_
#define _CREATOR_1_

#include "i_creator.hpp"
#include "product_1.hpp"

/**
 * @brief Overrides the interface creator
 */
class Creator1 : public ICreator {

public:
    IProduct* FactoryMethod() const override {
        return new Product1();
    }
};


#endif // _CREATOR_1_