#ifndef _I_PRODUCT_HPP_
#define _I_PRODUCT_HPP_

#include <iostream>

/**
 * @brief Product interface class. Define methos that must
 *        be implemented
 */
class IProduct {

public:
    virtual ~IProduct() {}

    /**
     * @brief Method that must be implemented by the concrete classes
     */
    virtual std::string Operation() const = 0;
};


#endif // _I_PRODUCT_HPP_