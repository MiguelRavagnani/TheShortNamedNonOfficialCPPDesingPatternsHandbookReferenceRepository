#ifndef _PRODUCT_1_HPP_
#define _PRODUCT_1_HPP_

#include "i_product.hpp"

class Product1 : public IProduct {

public:
    virtual std::string Operation() const override {
        return "{Result of the Product1}";
    }
};


#endif // _PRODUCT_1_HPP_