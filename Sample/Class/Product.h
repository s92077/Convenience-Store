#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
using namespace std;

class Product
{
public:
	Product();
	~Product();

private:
	int price; //price of the product
	uint8_t status; //[on shelf][][][][][][][]
	time_t arval_date;
	
};

Product::Product()
{
}

Product::~Product()
{
}
#endif
