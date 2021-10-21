#include <iostream>
void choice(); //Choice menu
void cart(); //Add to cart
void showmenu(); //Show menu(DB of goods)
void orderhistory(); //Show history of orders(order history DB)
void payment(); //Function for paying
void showcart(); //Show what is in cart
void issue(); //Funtion for issueing of order

void main()
{
    choice();
}
void choice() {
    int d = 0;
    bool flag = true;
    while (flag) {
        std::cout << "What would you like to do?\n1.Show menu\n2.Add to cart\n3.Show cart\n4.Show order history\n5.Exit\n";
        std::cin >> d;
        switch (d) {
        case 1: {
            showmenu();
            break;
        }
        case 2: {
            showmenu();
            cart();
            break;

        }
        case 3: {
            showcart();
            break;
        }
        case 4: {
            orderhistory();
            break;
        }
        case 5: {
            flag = false;
            break;
        }
        }
    }
}

void cart() {
    int p = 0, c = 0, a = 0, d = 0;
    showmenu();
    std::cout << "What position would you like to add at cart?\n";
    std::cin >> p;
    std::cout << "How many portions?\n";
    std::cin >> a;
    //Here information goes to DB of goods and decreases amount
    //Here information goes to cart DB
    while (c != 2) {
        std::cout << "Would you like to add something else?\n1.Yes\n2.No\n";
        std::cin >> c;
        if (c == 1) {
            cart();
        }
    }
    std::cout << "Whould you like to pay the order or to do something else?\n1.Pay\n2.Something else\n";
    std::cin >> d;
    switch (d) {
    case 1: {
        payment();
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

void payment() {
    int sum = 0;
    //Here all goods in cart are withdrawn
    std::cout << "Amount to pay: " << sum;
    //Here goes payment
    issue();
    //Here information from cart goes to DB of orders
}

void showcart() {
    int pay;
    //Here information from cart is withdrawn
    std::cout << "Whould you like to pay the order?\n1.Yes\n2.No\n";
    std::cin >> pay;
    switch (pay) {
    case1: {
        payment();
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