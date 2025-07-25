#include <stdio.h>


int main(){

	int age = 25;  // tamsayı 16,32,64 bit olabilir platforma bağlı
	char grade = 'A';  // genelde 8bit(1 byte)
	float pi = 3.14; 
	double precise_pi = 3.1415926535;
	
	short int kisaTamsayi; // kısa tamsayı, 16 bitten büyüktür
	long int uzunTamsayi;  // uzun tamsayı, 32 bitten büyüktür
	unsigned int test;  // negatif olmayan int, aynı boyutta ama sadece pozitif değer
	
	
	// Burada şöyle bir sorun var: int, short, long gibi türlerin bit uzunluğu
	// derleyiciye ve mimariye göre değişebilir, bizim sabit genişlikli tiplere ihtiyacımız var
	
	/*
	
	Tür		Açıklama		Bit genişliği
	uint8_t		unsigned integer, 	8 bit	0 - 255
	int8_t		signed integer, 	8 bit	-128 to 127
	uint16_t	unsigned integer, 	16 bit	0 - 65535
	(int16_t)
	uint32_t	unsigned integer, 	32 bit	0 - 4.29 milyar
	(int32_t)
	int64_t		signed integer, 	64 bit	Çok büyük
	uintptr_t	Pointer'ların adresini tutmak için
	
	*/


	// Print the values
	printf("Age (int): %d\n", age);
	printf("Grade (char): %c\n", grade);
	printf("Pi (float): %f\n", pi);
	printf("Precise pi (double): %lf\n", precise_pi);


	// Show sizes of data types
	printf("Size of int: %zu bytes\n", sizeof(int));
	printf("Siez of char: %zu bytes\n", sizeof(char));
	return 0;

}
