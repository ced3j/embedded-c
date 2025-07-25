// const int *const ptr --> hem değer hem pointer sabit

#include <stdio.h>


int main(){

	int x = 10;
	
	const int *const ptr = &x;
	
	// *ptr = 20;   // hata! değer değişmez
	// ptr = NULL;  // hata! başka adres gösteremezsin
	
	printf("ptr'nin işaret ettiği değer: %d\n", *ptr);   // 10
	
	return 0;
}
