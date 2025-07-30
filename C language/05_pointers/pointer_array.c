#include <stdio.h>


int main(){

	int sayilar[] = {10,20,30,40,50};
	int *ptr = sayilar;  // Yani ptr = &sayilar[0]
	
	
	printf("Dizinin ilk elemani (sayilar[0])	:%d\n", sayilar[0]);
	printf("Pointer ile ilk eleman (*ptr)		:%d\n", *ptr);
	printf("Sayilar dizisinin adresi		:%p\n", sayilar);
	printf("ptr pointer'inin tuttugu adres		:%p\n", ptr);
	
	
	//--------------------------------
	printf("pointer ile dizi elemanlarini gezelim: \n");
	
	for(int i = 0; i < 5; i++){
		printf("*(ptr + %d) = %d\n", i, *(ptr + i));
	}
	
	
	//--------------------------------
	printf("Dizi ismiyle pointer gibi erişim: \n");
	for(int i = 0; i < 5; i++){
		printf("*(sayilar + %d) = %d\n", i, *(sayilar + i));
	}
	
	return 0;

}
