#include "bills.h"

// function definitions

// function generates the format of the bill
void billFormat(char userName[50], char currentDate[20]) {
	printf("\n\n");
	printf("\t==============Restuaurant==============\n");
	printf("\nDate:%s", currentDate);
	printf("\nInvoice To: %s", userName);
	printf("\n");
	printf("---------------------------------------------\n");
	printf("Menu Items\t\t");
	printf("Qty\t\t");
	printf("Total\t\t");
	printf("\n---------------------------------------------");
	printf("\n\n");
}

// function generates the user data onto the bill, such as items and price
void billBody(char userItem[30], int quantity, double price) {
	printf("%s\t\t\t ", userItem);
	printf("%d\t\t", quantity);
	printf("%.2lf\t\t", price * quantity);
	printf("\n");
}

// function generates additional data based on user data, such as total price
void billNote(double total) {
	printf("\n");
	float salesTax = 0.06 * total; // sales tax in South Carolina
	float discount = 0.1 * total;
	float netTotal = total - discount;
	float grossTotal = netTotal + salesTax;
	printf("---------------------------------------------\n");
	printf("Sub Total\t\t\t\t%.2f", total);
	printf("\nDiscount @10%s\t\t\t\t%.2f","%",discount);
	printf("\n\t\t\t\t\t------");
	printf("\nNet Total\t\t\t\t%.2f", netTotal);
	printf("\nSales Tax @6%s\t\t\t\t%.2f","%",salesTax);
	printf("\n---------------------------------------------\n");
	printf("\nGross Total\t\t\t\t%.2f", grossTotal);
	printf("\n---------------------------------------------\n");
}