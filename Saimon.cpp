#include <iostream>
#include <vector>
#include <string>
#include<fstream>

using namespace std;

class CartOfClass {
private:
    int _positionOfVar, _foodamountOfVar, _priceOfVar;
    string _foodnameOfVar;
public:
    CartOfClass(int _positionOfVar, int _foodamountOfVar, int _priceOfVar, string _foodnameOfVar) {
        string foodnameOfVar = _foodnameOfVar;
        int positionOfVar = _positionOfVar, foodamountOfVar = _foodamountOfVar, priceOfVar = _priceOfVar;
    }
    void addposOfFunc() {

    }

    void withdrawOfFunc() {
        cout <<
    }
};

void choice(); //Choice menu
void cart(vector<CartOfClass>&); //Add to cart
void showmenu(); //Show menu(DB of goods)
void orderhistory(); //Show history of orders(order history DB)
void paymentOfFunc(vector<CartOfClass>&); //Function for paying
void showcart(vector<CartOfClass>&); //Show what is in cart
void issue(); //Funtion for issueing of order


int main()
{
    choice();
    return 0;
}

void choice() {
    int decicionOfVar = 0;
    bool flagOfVar = true;
    vector<CartOfClass> cartOfVar;
    while (flagOfVar) {
        cout << "What would you like to do?\n1.Show menu\n2.Add to cart\n3.Show cart\n4.Show order history\n5.Exit\n";
        cin >> decicionOfVar;
        switch (decicionOfVar) {
        case 1: {
            showmenu();
            break;
        }
        case 2: {
            showmenu();
            cart(cartOfVar);
            break;

        }
        case 3: {
            showcart(cartOfVar);
            break;
        }
        case 4: {
            orderhistory();
            break;
        }
        case 5: {
            flagOfVar = false;
            break;
        }
        }
    }
}

void cart(vector<CartOfClass>& cartOfVar) {
    int posnumberOfVar = 0, anwserOfVar = 0, amountOfVar = 0, decicionOfVar = 0;
    showmenu();
    cout << "What position would you like to add at cart?\n";
    cin >> posnumberOfVar;
    cout << "How many portions?\n";
    cin >> amountOfVar;
    //Here information goes to DB of goods and decreases amount
    ifstream foodfileOfVar("food.dbase");
    while (foodfileOfVar) {

    }
    //Here information goes to cart vector

    while (anwserOfVar != 2) {
        cout << "Would you like to add something else?\n1.Yes\n2.No\n";
        cin >> anwserOfVar;
        if (anwserOfVar == 1) {
            cart(cartOfVar);
        }
    }

    cout << "Whould you like to pay the order or to do something else?\n1.Pay\n2.Something else\n";
    cin >> decicionOfVar;
    switch (decicionOfVar) {
    case 1: {
        paymentOfFunc(cartOfVar);
        break;
    }
    case 2: {
        break;
    }
    }
}

void showmenu() {
    //Here goods from DB of goods are withdrawn
}

void orderhistory() {
    //Here order from order history DB are withdrawn
}

void paymentOfFunc(vector<CartOfClass>& cartOfVar) {
    int sum = 0;
    //Here all goods in cart are withdrawn
    cout << "Amount to pay: " << sum << endl;;
    //Here goes payment
    issue();
    //Here information from cart goes to DB of orders
}

void showcart(vector<CartOfClass>& cartOfVar) {
    int pay;
    //Here information from cart is withdrawn
    cout << "Whould you like to pay the order?\n1.Yes\n2.No\n";
    cin >> pay;
    switch (pay) {
    case1: {
        paymentOfFunc(cartOfVar);
        break;
        }
case2: {
    break;
    }
    }

}

void issue() {
    //Function of issueing an order
}