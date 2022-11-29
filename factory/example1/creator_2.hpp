#ifndef _CREATOR_2_
#define _CREATOR_2_

#include "i_creator.hpp"
#include "product_2.hpp"

/**
 * @brief Overrides the interface creator
 */
class Creator2 : public ICreator {

public:
    IProduct* FactoryMethod() const override {
        return new Product2();
    }
};


#endif // _CREATOR_2_