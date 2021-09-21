/* 	Billing System
	Purpose: Generate a billing format for restaurants that easy to use and manage */

#include "bills.h"

int main(void) {
	int userChoice; // user preferred operation
	int num; // the number of items
	menuOrder order; // user order variable
	menuOrder orderCheck; // check existing orders
	char saveBill = 'y'; // user choice to save data
	char contFlag = 'y';
	char name[50]; // name of the customer
	FILE *file; // file ptr to hold data

	// dashboard
	while(contFlag == 'y') {
		system("clear");
		float totalPrice = 0; // the total price of bill
		int invoiceFound = 0;
		printf("\t==============Restuaurant==============\n");
		printf("\n1.Generate Invoice");
		printf("\n2.Show all Invoices");
		printf("\n3.Search Invoice");
		printf("\n4.Exit");

		printf("\n\nSelect your preffered operation: ");
		scanf("%d", &userChoice);
		fgetc(stdin); // get rid of trailing newline

		switch(userChoice) {

			case 1:
				system("clear");
				printf("\nPlease enter the name of the customer:\t");
				fgets(order.customer,50,stdin);
				order.customer[strlen(order.customer)-1] = 0; // get rid of newline char
				strcpy(order.date,__DATE__);
				printf("\nEnter the number of items:\t");
				scanf("%d", &num);

				order.numOfItems = num;

				// for loop
				for (int i = 0; i < num; ++i) {
					fgetc(stdin);
					printf("\n\n");
					printf("Enter item number %d:\t", i + 1);
					fgets(order.obj[i].item, 20, stdin);
					order.obj[i].item[strlen(order.obj[i].item)-1] = 0;
					printf("Enter the quantity:\t");
					scanf("%d", &order.obj[i].itemQty);
					printf("Enter the unit price:\t");
					scanf("%lf", &order.obj[i].itemPrice);
					totalPrice += order.obj[i].itemQty * order.obj[i].itemPrice;
				}

				billFormat(order.customer, order.date);
				for (int i = 0; i < order.numOfItems; ++i) {
					billBody(order.obj[i].item, order.obj[i].itemQty, order.obj[i].itemPrice);
				}
				billNote(totalPrice);

				printf("\nSave the Invoice [y/n]: ");
				scanf("%s", &saveBill);

				if(saveBill == 'y') {
					file = fopen("RestaurantBill.pdf","a+");
					size_t return_val = fwrite(&order,sizeof(menuOrder), 1,file);
					if(return_val != 0)
						printf("\nSuccessfully saved\n");
					else
						printf("\nError saving\n");
					fclose(file);
				}
				break;

			case 2:
				system("clear");
				file = fopen("RestaurantBill.pdf", "r");
				printf("\n  *******Previous Invoices*******\n");
				while(fread(&orderCheck, sizeof(menuOrder), 1, file)) {
					float totalCheck = 0; // variable for checking total price
					billFormat(orderCheck.customer, orderCheck.date);
					for (int i = 0; i < orderCheck.numOfItems; i++) {
						billBody(orderCheck.obj[i].item,orderCheck.obj[i].itemQty,orderCheck.obj[i].itemPrice);
						totalCheck += orderCheck.obj[i].itemQty * orderCheck.obj[i].itemPrice;
					}
					billNote(totalCheck);
				}

				fclose(file);
				break;

			case 3:

				printf("\nEnter the name of the customer:\t");
				fgets(name, 50, stdin);
				name[strlen(name) - 1] = 0; // get rid of newline

				system("clear");
				file = fopen("RestaurantBill.pdf", "r");
				printf("\t*******Invoice of %s*******", name);
				while(fread(&orderCheck, sizeof(menuOrder), 1, file)) {
					float totalCheck = 0; // variable for checking total price
					
					// check for name match in data
					if(!strcmp(order.customer, name)) {
						billFormat(orderCheck.customer, orderCheck.date);
						for (int i = 0; i < orderCheck.numOfItems; i++) {
							billBody(orderCheck.obj[i].item,orderCheck.obj[i].itemQty,orderCheck.obj[i].itemPrice);
							totalCheck += orderCheck.obj[i].itemQty * orderCheck.obj[i].itemPrice;
					}
					billNote(totalCheck);
					invoiceFound = 1;
					}
				}

				if(!invoiceFound) {
					printf("\nThe invoice for %s does not exist.\n", name);
				}
				fclose(file);
				break;

			case 4:
				printf("\n\t\t Thank you!\n");
				exit(0);
				break;

			default:
				printf("Sorry that's an invalid operation\n");
				break;
		}

		printf("\nDo you want to perfom another operation? [y/n] :\t");
		scanf("%s", &contFlag);
	}
	
	printf("\n\n");


}