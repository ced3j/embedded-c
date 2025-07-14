#include <stdio.h>
#include <string.h>


int main(){

	int sayilar[5];
	char harfler[3];
	float ondaliklar[4];
	
	
	int sayilar2[5] = {10,20,30,40,50};  // initialization
	
	printf("First num: %d\n", sayilar2[0]);
	printf("Second num: %d\n", sayilar2[1]);
	
	sayilar2[2] = 300;
	printf("New number: %d\n", sayilar2[2]);
	
	
	
	// ------------- 
	printf("\n--------------------------\n");
	
	
	int notlar[5] = {85, 90, 78, 92, 88};
    
	    // For döngüsüyle yazdırma
	printf("Öğrenci notları:\n");
	for (int i = 0; i < 5; i++) {
		printf("Not %d: %d\n", i + 1, notlar[i]);
	}
	
	
	// ------------- 
	printf("\n--------------------------\n");
	
	
	
	char name[5] = "Betel";
	for(int i = 0; i < 5; i++){
		printf("%c-", name[i]);
	}
	
	
	// ------------- 
	printf("\n--------------------------\n");
	
	char isim[50];
	printf("Enter your name: ");
	fgets(isim, sizeof(isim), stdin);
	
	printf("Hello, %s", isim);
	
		
	return 0;
}
