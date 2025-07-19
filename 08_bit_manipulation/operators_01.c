#include <stdio.h>


#define READ (1 << 0)  // 00000001  --> read sabiti 1 << 0 işleminin sonucudur
					// 1'i 0 kez sola kaydırır (yani değişmez)
#define WRITE (1 << 1) // 00000010  --> write sabiti 1 << 1 işleminin sonucudur
		
// Bunları neden yaptık? read ve write birer flag. her biri belirli bir biti 1 yaparak
// bir izni ifade eder,   read: 0. bit 1 ise okuma izni var
			// write: 1. bit 1 ise yazma izni var

int main(){

	// OR operator
	
	unsigned char a = 5; // 00000101
	unsigned char b = 3; // 00000011
	unsigned char result = a | b;  // 00000111 (7) 
	
	
	
	// ---------------
	
	unsigned char permissions = 0; // 00000000
		// yani başlangıçta hiçbir izin bayrağı ayarlı değil
	
	permissions |= READ | WRITE; // Okuma ve yazma izni ekle
		// hem read'ı hem write'ı ekliyor
		// 00000001 READ
		// 00000010 WRITE
		
		// 00000011 Sonuç, yani 0. ve 1. bitler 1 oldu 
		
	printf("Permissions: %d\n", permissions);  // Çıktı: 3  (00000011)
	
	
	
	
	
	
	// ---------- Bitwise XOR ^ 
	// Farklı olanların 1 yapılması
	
	unsigned char m = 5; // 00000101
	unsigned char n = 3; // 00000011
	unsigned char result2 = a ^ b;  // 00000110  (6)
	
	
	
	
	
	
	
	// --------- Bitwise NOT ~ 
	
	unsigned char o = 5; // 00000101
	unsigned char result3 = ~o;  // 11111010 (250)
	
	 
	
	
	

	return 0;
}
