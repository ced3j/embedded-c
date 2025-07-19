#include <stdio.h>

struct Item{
	int quantity;
	char name[50];
};


void updateItem(struct Item *i, int q){
	i->quantity = q;
}

void printItem(struct Item i){
	printf("Item name: %s\n", i.name);
	printf("Item quantity: %d\n", i.quantity);
}

int main(){

	struct Item newItem = {10, "First Item"};
	printItem(newItem);
	
	updateItem(&newItem, 20);
	printItem(newItem);

	return 0;
}
