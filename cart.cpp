#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include"product.cpp"
#include"choice.cpp"
#include"payment.cpp"
#include"showcart.cpp"
void cart(vector<Product>& cart) {
    int posnumberr = 0, anwser = 0, amount = 0, decicion = 0;
    showmenu();
    cout << "What position would you like to add at cart?\n";
    cin >> posnumber;
    cout << "How many portions?\n";
    cin >> amount;
    //Here information goes to DB of goods and decreases amount
    //Here information goes to cart vector

    while (anwser != 2) {
        cout << "Would you like to add something else?\n1.Yes\n2.No\n";
        cin >> anwser;
        if (anwser == 1) {
            cart(cart);
        }
    }

    cout << "Whould you like to pay the order or to do something else?\n1.Pay\n2.Something else\n";
    cin >> decicion;
    switch (decicion) {
    case 1: {
        payment(cart);
        break;
    }
    case 2: {
        break;
    }
    }
}