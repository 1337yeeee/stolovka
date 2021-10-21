#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include<product.cpp>
#include<choice.cpp>
#include<cart.cpp>
#include<payment.cpp>
#include<showcart.cpp>
void choice() {
    int decicion = 0;
    bool flagOfVar = true;
    vector<Product> cartOfVar;
    while (flagOfVar) {
        cout << "What would you like to do?\n1.Show menu\n2.Add to cart\n3.Show cart\n4.Show order history\n5.Exit\n";
        cin >> decicion;
        switch (decicion) {
        case 1: {
            //Here list of products is withdrawn
            break;
        }
        case 2: {
            //Here list of products is withdrawn
            cart(cart);
            break;

        }
        case 3: {
            //Here list of products in cart is withdrawn;
            break;
        }
        case 4: {
            //Here hostory of orders is withdrawn
            break;
        }
        case 5: {
            flagOfVar = false;
            break;
        }
        }
    }
}