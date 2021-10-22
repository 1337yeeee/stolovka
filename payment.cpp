#include <iostream>
#include <vector>
#include <string>
#include<fstream>
using namespace std;
class Payment {
private:
	string username;
	int cardbalance;

public:
	Payment() {
		username = cardbalance = 0;
	}

	Payment(string _username, int _cardbalance) {
		username = _username;
		cardbalance = _cardbalance;
	}
	bool checkbalance(string _username, int sum) {
		int i = 0;
		ifstream paymentfile;
		paymentfile.open("Data/payment.dbase");
		Payment test;
		vector<Payment> testarr;
		while (paymentfile.read((char*)&test, sizeof(test))) {
			testarr.push_back(test);
		}
		paymentfile.close();
		while (testarr[i].username != _username) {
			i++;
		}
		if (testarr[i].cardbalance >= sum)
			return true;
		else
			return false;
	}


};