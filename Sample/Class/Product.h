#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
#include"Stdafx.h"
using namespace std;

class Product
{
public:
	Product();
	~Product();

private:
	uint32_t id;
	System::String ^productname;
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
