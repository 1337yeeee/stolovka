#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include<product.cpp>
#include<choice.cpp>
#include<cart.cpp>
#include<payment.cpp>
#include<showcart.cpp>
void paymen(vector<Product>& cart) {
    int sum = 0;
    //Here all goods in cart are withdrawn
    cout << "Amount to pay: " << sum << endl;;
    //Here goes payment
    //Here information from cart goes to DB of orders
    ofstream orderfile;
    orderfile.open("order.dbase", ofstream::app);
    orderfile.write((char*)&cart, cart.size());
}