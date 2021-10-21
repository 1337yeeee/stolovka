#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;



class Menu {
public:
	string name;
	int price;
	int id;


	Menu(string _name, int _price, int _id=0) {
		name = _name;
		price = _price;
		id = _id;
	}

//dobavlyaet object klassa Menu v konets massiva
	void addProduct(vector<Menu> &massive, Menu object) {
		massive.push_back(object);
	}

//sozdaet object klassa Menu i dobavlyaet v konec massiva
	void addProduct(vector<Menu> &massive, string _name, int _price, int _id=0) {
		Menu object(_name, _price, _id);
		massive.push_back(object);
	}

//udalyaet product po ego id
	void deleteProduct(vector<Menu> &massive, Menu object) {
		for(int i=0; i<massive.size(); i++)
			if(massive[i] == object)
				massive.erase(massive.cbegin()+i);
	}

/*	void get(vector<Menu> &massive) {
		string count;
		string input;
		string _name;
		int _price, _id;
		ofstream fMenu;
		fMenu.open("Menu.dbase");

		cin>>cout;

		if(cout!=EOF) {
			for(int i; i<count; i++) {
				cin>>input
			}
		}
	}

	void save(vector<Menu> massive) {
		ofstream fMenu;
		fMenu.open("Menu.dbase");

		cout<<massive.size()<<endl;
		for(Menu i : massive) {
			cout<<"\""<<i.name<<"\""<<" ";
			cout<<"|"<<i.price<<"|"<<" ";
			cout<<"{"<<i.id<<"}"<<endl;
		}

		fMenu.close();
	}*/

//if object a is equal to object b returns 1 else 0
	int operator == (Menu object) {
		if(this->id == object.id) return 1;
		else return 0;
	}
};


int main() {
	//there is nothing
	return 0;
}