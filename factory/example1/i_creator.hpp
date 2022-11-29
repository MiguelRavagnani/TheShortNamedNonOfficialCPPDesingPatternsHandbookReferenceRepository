#ifndef _I_CREATOR_
#define _I_CREATOR_

#include "i_product.hpp"

/**
 * @brief Interface creator class. Has some default implementation
 *        Won't have a lot core implementations.
 */
class ICreator {

public:
    virtual ~ICreator() {}
    virtual IProduct* FactoryMethod() const = 0;

    /**
     * @brief Method that must be implemented by the concrete classes
     */
    virtual std::string Operation() const {
        /* Creates a Product instance */
        IProduct* product = this->FactoryMethod();

        /* Uses it */
        std::string result = "In conjunction with " + product->Operation();
        delete product;
        return result;
    }
};


#endif // _I_CREATOR_