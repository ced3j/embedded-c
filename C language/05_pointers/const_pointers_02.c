#include <stdio.h>

int main(){

	int x = 10;
	int y = 20;
	
	int *const ptr = &x; // ptr sabittir, hep x'i gösterecek
	// Pointer'ın sabit olduğu, değerin değişebildiği örnek
	
	*ptr = 15;
	
	printf("X'in yeni degeri: %d\n", *ptr);  // 15


	return 0;
}
