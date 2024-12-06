#ifndef CART_H
#define CART_H

#include <vector>
#include "OnlineCourse.h"

class Cart {
private:
    vector<OnlineCourse*> cart;
    vector<OnlineCourse*> purchasedCourses;

public:
    void addToCart(OnlineCourse* course);
    void displayCart();
    void checkout();
    void displayPurchasedCourses();
};

#endif // CART_H