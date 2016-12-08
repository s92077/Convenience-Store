#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
#include<string>
#include<windows.h>


class Product
{
public:
	Product();
	Product(uint32_t, std::string);
	~Product();

private:
	uint32_t id;
	std::string productname;
	int price; //price of the product
	uint8_t status; //[on shelf][][][][][][][]
#pragma managed(push, off)
	SYSTEMTIME arval_date;
	SYSTEMTIME onshelf_date;
#pragma managed(pop)
	time_t a;
};

Product::Product(uint32_t id, std::string name)
{
	this->id = id;
	this->productname = name;



}
Product::Product()
{
	this->id = -1;
	this->productname = "";
	


}
Product::~Product()
{
}
#endif
