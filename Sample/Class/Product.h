#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
#include<string>

class Product
{
public:
	Product();
	~Product();

private:
	uint32_t id;
	std::string productname;
	int price; //price of the product
	uint8_t status; //[on shelf][][][][][][][]
	struct tm arval_date;
	struct tm onshelf_date;
};

Product::Product()
{
}

Product::~Product()
{
}
#endif
