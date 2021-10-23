#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;



class User {
private:
	string login;
	string password;
public:
	int userID;
	int phoneNumber;
	string userName;

	User(vector<User> base, string _userName, string _login, string _password, int _phoneNumber) {
		int tempID = 0;
		this->userName = _userName;
		this->login = _login;
		this->password = _password;
		this->phoneNumber = _phoneNumber;
		for(User i:base) tempID = max(tempID, i.userID);

		//new userID is the largest ID in the base +1
		if(tempID) this->userID = tempID+1;
		else this->userID = 101;
	}

	User(){;}

	bool changeName(string _password, string _userName) {
		if(_password==password) {
			userName = _userName;
			return true;
		} else return false;
	}

	bool changePassword(string _login, string _password, int _phoneNumber) {
		if(_login==login && _phoneNumber==phoneNumber) {
			password = _password;
			return true;
		} else return false;
	}

	bool changePhoneNumber(string _login, string _password, int _phoneNumber) {
		if(_login==login && _password==password) {
			phoneNumber = _phoneNumber;
			return true;
		} else return false;
	}

	bool changeLogin(string _login, string _password, int _phoneNumber) {
		if(_phoneNumber==phoneNumber && _password==password) {
			login = _login;
			return true;
		} else return false;
	}

	bool deleteUser(vector<User> &base,string _login, string _password, int _phoneNumber) {
		if(_phoneNumber==phoneNumber && _password==password\
		&& _login==login) {
			for(int i=0; i<base.size(); i++)
			if(base[i].userID == userID)
				base.erase(base.cbegin()+i);
			return true;
		} else return false;
	}

	int operator == (User object) {
		if(userID == object.userID) return 1;
		else return 0;
	}

	void debugPrint() {
		cout<<this->userName<<"|";
		cout<<this->login<<"|";
		cout<<this->password<<"|";
		cout<<this->phoneNumber<<"|";
		cout<<this->userID<<endl;
	}

	static void writeVectortoDB(vector<User>& base) {
		ofstream userBase;
		userBase.open("Data/accounts.dbase");
		for (int i = 0; i < base.size(); i++) {
			userBase.write((char*)&base[i], sizeof(User));
		}
		userBase.close();
	}
};
