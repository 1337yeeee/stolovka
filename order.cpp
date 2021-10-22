#include <iostream>
#include <vector>
#include <ctime>
#include "product.cpp"
#include <string>
#include <fstream>
using namespace std;



class Order : public Product {
public:
	tm* timeinfo;
	int id_order;
public:
	//dlya <typeOfClass>
	Order();
	
	//konstruktor bez exampler Product
	Order(string name, int price, int id_product, int id_order = 0, time_t seconds = time(NULL)) :  Product(name, price, id) {
		this->timeinfo = localtime(&seconds);
		this->id_order = id_order;
	}

	//konstruktor with exampler Product
	Order(Product a, int id_order, time_t seconds = time(NULL)) : Product(a.name, a.price, a.id) {
		this->timeinfo = localtime(&seconds);
		this->id_order = id_order;
	}

	
	//dobavit this exampler 
	void addOrder(vector<Order>& massive) {
		massive.push_back(*this);
	}
	//dobavit chuzhoi exampler s gotovim Product
	static void addOrder(vector<Order>& massive, Product object, time_t seconds = time(NULL)){
		massive.push_back(Order(object.name, object.price, object.id, seconds));
	}
	//dobavit chuzhoi exampler Order
	static void addOrder(vector<Order>& massive, Order object){
		object.addOrder(massive);
	}

	//udalit this exampler
	void deleteOrder(vector<Order>& massive){
		for(int i = 0; i<massive.size(); i++){
			if(massive[i]==*this){
				massive.erase(massive.cbegin()+i);
			}
		}
	}
	//udalit chuzhoi exampler
	static void deleteOrder(vector<Order>& massive, Order object){
		object.deleteOrder(massive);
	}


	int operator== (Order object){
		if(object.id_order==id_order){
			return 1;
		}
		else {
			return 0;
		}

	}

	
	//return string with date and time
	string timeOrder(){
		return asctime(timeinfo);
	}

	//return string with date and time dlya chuvogo exampler
	static string timeOrder(Order object){
		return object.timeOrder();
	}


	//return string with info about this exampler
	string infoboutOrder(){
		return name+' '+to_string(price)+' '+to_string(id)+' '+to_string(id_order);
	}
	//return string with info about chuzhom exampler
	static string infoboutOrder(Order object){
		return object.infoboutOrder();
	}

	static void infotoDB(vector<Order>& massive){
		ofstream out;
		out.open("Data/orders.dbase");
		for(int i = 0; i<massive.size(); i++){
			out << massive[i].infoboutOrder() << endl;
		}
		out.close();
	}
	/*
	static void infofromDB(vector<Order>& massive){
		ifstream in;
		string line;
		in.open("Data/orders.dbase");
		while(getline(in, line)){

		}
	}
	*/

};
int main(){
	Order a("sosiska", 150, 1, 1);
	Order b("sardelka", 200, 3,2);
	Order c("kotleta", 100,2,3);
	vector<Order> massive;
	massive.push_back(a);
	massive.push_back(b);
	massive.push_back(c);
	Order::infotoDB(massive);
}
