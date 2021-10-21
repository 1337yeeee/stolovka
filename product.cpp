#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;



class Product {
public:
	string name;
	int price;
	int id;


	Product(string _name, int _price, int _id=0) {
		name = _name;
		price = _price;
		id = _id;
	}

//dobavlyaet object klassa Product v konets massiva
	void addProduct(vector<Product> &massive, Product object) {
		massive.push_back(object);
	}

//sozdaet object klassa Product i dobavlyaet v konec massiva
	void addProduct(vector<Product> &massive, string _name, int _price, int _id=0) {
		Product object(_name, _price, _id);
		massive.push_back(object);
	}

//udalyaet product po ego id
	void deleteProduct(vector<Product> &massive, Product object) {
		for(int i=0; i<massive.size(); i++)
			if(massive[i] == object)
				massive.erase(massive.cbegin()+i);
	}

//if object a is equal to object b returns 1 else 0
	int operator == (Product object) {
		if(this->id == object.id) return 1;
		else return 0;
	}
};


int main() {
	//there is nothing
	return 0;
}