#ifndef BILL_H
#define BILL_H

// libraries to include
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

// function prototypes
void billFormat(char userName[50], char currentDate[20]);

void billBody(char userItem[30], int quantity, double price);

void billNote(double total);

// structs

typedef struct menuItem{
	char item[30];
	double itemPrice;
	int itemQty;
} menuItem;

typedef struct orders{
	char customer[50];
	char date[50];
	int numOfItems;
	menuItem obj[50];
} menuOrder;



#endif