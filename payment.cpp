#include <iostream>
#include <vector>
#include <string>
#include<fstream>
using namespace std;



class Payment {
private:
	string username;
	int cardbalance, userID;

public:
	//constructor w/out parametrs
	Payment() {
		username = cardbalance = userID = 0;
	};

	//constructor with parametrs
	Payment(string _username, int _cardbalance, int _userID) {
		username = _username;
		cardbalance = _cardbalance;
		userID = _userID;
	}

	//deleting object from vector
	void deleteFromVector(vector<Payment>& testarr) {
		for (int i = 0; i < testarr.size(); i++)
			if (testarr[i].username == this->username)
				testarr.erase(testarr.cbegin() + i);
	}

	//checking if user has enough money from DB
	static void checkbalanceFromDB(Payment test, int sum) {
		int i;
		string _username;
		int _cardbalance, _userID;
		bool flag = false;
		ifstream _paymentfile;

		_paymentfile.open("Data/payment.dbase");
		_username = test.username;
		_cardbalance = test.cardbalance;
		_userID = test.userID;
		vector<Payment> testarr;
		while (_paymentfile.read((char*)&test, sizeof(Payment))) {
			testarr.push_back(test);
		}
		_paymentfile.close();
		for (i = 0; i < testarr.size(); i++) {
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

	//check if user has enough money from vector
	static void checkbalanceFromVector(vector<Payment>& testarr, Payment test, int sum) {
		int i;
		string _username;
		int _cardbalance, _userID;
		bool flag = false;

		_username = test.username;
		_cardbalance = test.cardbalance;
		_userID = test.userID;
		for (i = 0; i < testarr.size(); i++) {
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

	//add object to DB
	void addObjectToDB() {
		Payment obj;
		obj.username = this->username;
		obj.cardbalance = this->cardbalance;
		obj.userID = this->userID;
		ofstream paymentfile;
		paymentfile.open("Data/payment.dbase", ofstream::app);
		paymentfile.write((char*)&obj, sizeof(Payment));
		paymentfile.close();
	}

	//write vector to DB
	static void writeVectortoDB(vector<Payment>& testarr) {
		ofstream paymentfile;
		paymentfile.open("Data/payment.dbase");
		for (int i = 0; i < testarr.size(); i++) {
			paymentfile.write((char*)&testarr[i], sizeof(Payment));
		}
		paymentfile.close();
	}

	void print() {
		cout << username << " " << cardbalance << " " << userID << endl;
	}
};