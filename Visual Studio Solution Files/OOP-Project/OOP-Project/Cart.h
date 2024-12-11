#pragma once

#include <vector>
#include "OnlineCourse.h"

using namespace std;

class Cart {
private:
    vector<OnlineCourse*> cart;
    vector<OnlineCourse*> purchasedCourses;

public:
    void addToCart(OnlineCourse* course);
    void displayCart();
    void checkout();
    void displayPurchasedCourses();
    void rateCourse();
};