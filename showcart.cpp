void showcart(vector<Menu>& cart) {
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