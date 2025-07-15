#include <stdio.h>


void degeriArttir(int *ptr){
	// *ptr, ptr'nin gösterdiği adresteki değeri ifade eder
	*ptr = *ptr+1;
}

int main(){

	int sayi = 10;
	int *ptr;
	ptr = &sayi;
	
	printf("Degiskenin degeri	: %d\n", sayi);
	printf("Degiskenin adresi	: %p\n", &sayi);
	printf("Pointer'in tuttugu adres: %p\n", ptr);
	printf("Pointer'dan erisilen deger: %d\n", *ptr);
	
	
	// Pointer ile degeri degistirelim
	*ptr = 20;
	printf("\nPointer ile degeri degistirdik: %d\n", sayi);
	
	
	// Fonksiyon ile pointer kullanarak sayıyı arttır
	degeriArttir(&sayi);  // Sayı'nın adresini gönderdik
	printf("Fonk ile arttirilan sayi: %d", sayi);
	
	
	return 0;

}
