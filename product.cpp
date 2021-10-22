#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Product {
protected:
	string name;
	int price;
	int id;
public:
	Product() {
		;
	}

	Product(string _name, int _price, int _id=0) {
		this->name = _name;
		this->price = _price;
		this->id = _id;
	}

//udalyaet product po ego id
	void deleteProduct(vector<Product> &massive) {
		for(int i=0; i<massive.size(); i++)
			if(massive[i].id == this->id)
				massive.erase(massive.cbegin()+i);
	}

//if object a.id is equal to object b.id returns 1 else 0
	int operator == (Product object) {
		if(this->id == object.id) return 1;
		else return 0;
	}

	void debugPrint() {
		cout<<this->name;
		cout<<" "<<this->price;
		cout<<" "<<this->id<<endl;
	}
};
