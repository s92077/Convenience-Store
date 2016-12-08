#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
#include<string>
#include<windows.h>


class Product
{
public:
	Product();
	Product(uint32_t,std::string);
	~Product();

private:
	uint32_t id;
	std::string productname;
	int price; //price of the product
	uint8_t status; //[on shelf][][][][][][][]
	SYSTEMTIME arval_date;
	SYSTEMTIME onshelf_date;
};

Product::Product(uint32_t id,std::string name)
{
	this->id = id;
	this->productname = name;



}
Product::Product()
{
	this->id = -1;
	this->productname = "";
	 st = { 0 };


}
Product::~Product()
{
}
#endif
