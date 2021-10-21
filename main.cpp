#include <iostream>
#include <vector>
#include <string>
#include<fstream>

using namespace std;

class Product {
public:
    string name;
    int price;
    int id;


    Product(string _name, int _price, int _id = 0) {
        name = _name;
        price = _price;
        id = _id;
    }

    //dobavlyaet object klassa Product v konets massiva
    void addProduct(vector<Product>& massive, Product object) {
        massive.push_back(object);
    }

    //sozdaet object klassa Product i dobavlyaet v konec massiva
    void addProduct(vector<Product>& massive, string _name, int _price, int _id = 0) {
        Product object(_name, _price, _id);
        massive.push_back(object);
    }

    /*udalyaet product po ego id
    void deleteProduct(vector<Product>& massive, Product object) {
        for (int i = 0; i < massive.size(); i++)
            if (massive[i] == object)
                massive.erase(massive.cbegin() + i);
    }*/

    //if object a is equal to object b returns 1 else 0
    int operator == (Product object) {
        if (this->id == object.id) return 1;
        else return 0;
    }
};


void payment(vector<Product>& cart) {
    int sum = 0;
    //Here all goods in cart are withdrawn
    cout << "Amount to pay: " << sum << endl;;
    //Here goes payment
    //Here information from cart goes to DB of orders
    ofstream orderfile;
    orderfile.open("order.dbase", ofstream::app);
    orderfile.write((char*)&cart, cart.size());
}

void showcart(vector<Product>& cart) {
    int pay;
    //Here information from cart is withdrawn
    cout << "Whould you like to pay the order?\n1.Yes\n2.No\n";
    cin >> pay;
    switch (pay) {
    case1: {
        payment(cart);
        break;
        }
case2: {
    break;
    }
    }

}

void _cart(vector<Product>& cart) {
    int posnumber = 0, anwser = 0, amount = 0, decicion = 0;
    //Here list of Product is withdrawn
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
            _cart(cart);
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


void choice() {
    int decicion = 0;
    bool flag = true;
    vector<Product> cart;
    while (flag) {
        cout << "What would you like to do?\n1.Show menu\n2.Add to cart\n3.Show cart\n4.Show order history\n5.Exit\n";
        cin >> decicion;
        switch (decicion) {
        case 1: {
            //Here list of products is withdrawn
            break;
        }
        case 2: {
            //Here list of products is withdrawn
            _cart(cart);
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
            flag = false;
            break;
        }
        }
    }
}
int main()
{
    choice();
    return 0;
}