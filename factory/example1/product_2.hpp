#ifndef _PRODUCT_2_HPP_
#define _PRODUCT_2_HPP_

#include "i_product.hpp"

class Product2 : public IProduct {

public:
    virtual std::string Operation() const override {
        return "{Result of the Product2}";
    }
};


#endif // _PRODUCT_2_HPP_