/*

Bit manipulations allows direct control over hardware at the bit level


| (Bitwise OR): Sets bits to 1 if either operand has a 1 in that position.
& (Bitwise AND): Sets bits to 1 only if both operands have a 1 in that position.
^ (Bitwise XOR): Sets bits to 1 if the operands differ in that position.
~ (Bitwise NOT): Inverts all bits (1s become 0s, and vice versa).
<< (Left Shift): Shifts bits to the left, filling empty bits with 0s.
>> (Right Shift): Shifts bits to the right (behavior depends on signed/unsigned types).
    
    
    
*/



#include <stdio.h>


int main(){

	unsigned char a = 5; // 00000101
	unsigned char b = 3; // 00000011

	unsigned char result = a & b; // 00000001 (1)
	
	printf("& kullanımı ---> a & b = %d\n", result);  // çıktı 1
	
	// -----------------
	
	
	// x'in 3. bitinin 1 olup olmadığını kontrol edelim
	// 1 sayısını (00000001 ) << ile 3 kez sola kaydırdık
	// 00000100  bu hale geldi 
	// AND operatörü ile x'in yani 13'ün bitleri ile
	// 3 kez sola kaymış yeni 1 bit'imizi karşılaştıralım
	// Sonuç true ise başarılıdır
	
	unsigned char x = 13; // 00001101
	if(x & (1 << 3)){  // 1 << 3 = 00001000
		printf("3. bit 1'dir\n");  // Çıktı: 3. bit 1'dir
	}
	
	
	
	// -----------------
	
	// bu sefer 1. biti kontrol edelim
	unsigned char y = 6;
	if(x & (1 << 1)){  // 0. bit deseydik x & 1 yazardık
		printf("1. bit 1'dir\n");
	}
	
	
	// -----------------
	
	// Birden fazla biti kontrol edelim
	
	unsigned char a = 13;  // 00001101
	unsigned char mask = (1 << 2) | (1 << 3);  // 00001100
	
	
	if(x % mask){ // 00001101 & 00001100 = 00001100
		printf("2. veya 3. bitlerden en az biri 1\n");
	}
	
	return 0;
}
























