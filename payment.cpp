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
	};
	Payment(string _username, int _cardbalance) {
		username = _username;
		cardbalance = _cardbalance;
	}

	static void checkbalance(Payment obj, int sum) {
		int i = 0;
		string _username;
		int _cardbalance;
		bool flag = false;
		ifstream _paymentfile;
		_paymentfile.open("Data/payment.dbase");
		_username = obj.username;
		_cardbalance = obj.cardbalance;
		vector<Payment> testarr;
		while (_paymentfile.read((char*)&obj, sizeof(Payment))) {
			testarr.push_back(obj);
		}
		_paymentfile.close();
		for (int i = 0; i < testarr.size(); i++) {
			if (testarr[i].username == _username) {
				testarr[i].username = _username;
				flag = true;
				break;
			}
		}
		if (flag) {
			if (testarr[i].cardbalance >= sum)
				cout << "Deneg dostato4no\n";
			else
				cout << "Deneg net ili vas net v sisteme\n";
		}
		else
			cout << "Deneg net ili vas net v sisteme\n";
	}

	void addtodb() {
		Payment obj;
		obj.username = username;
		obj.cardbalance = cardbalance;
		ofstream paymentfile;
		paymentfile.open("Data/payment.dbase", ofstream::app);
		paymentfile.write((char*)&obj, sizeof(Payment));
		paymentfile.close();
	}

	void print() {
		cout << username << " " << cardbalance << endl;
	}
};