#include "user.cpp"
#include "product.cpp"
#include "order.cpp"
#include "payment.cpp"
using namespace std;



extern vector<User> userBase;
extern vector<Product> productBase;
extern vector<Order> orderBase;
extern vector<Payment> paymentBase;


int _send() {
	return 0;
}


int _get() {
	return 0;
}


bool addMenu(Product product) {
	for(Product object:productBase)
		if(object==product) return false;

	productBase.push_back(product);

	return true;
}


bool deleteMenu(Product product) {
	bool flag = false;

	for(Product object:productBase)
		if(object==product) {
			flag=true;
			break
		}

	if(flag) productBase.deleteProdact(product);
	
	return flag;
}


bool checkPayment(int userID, int total) {
	return checkbalanceFromVector(paymentBase, total);
}


bool getOrder(Order order) {
	for(Order object:orderBase)
		if (order == object) return false;

	orderBase.push_back(object);

	return true;
}


bool updateOrder(Order &order, string status) {
	for(Order object:orderBase)
		if (order == object) return false;

	order.status = status;
}
