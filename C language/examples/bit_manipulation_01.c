/*

& --> iki bit de 1 ise 1 döner
| --> iki bitten birisi 1 ise 1 döner
^ --> (XOR) sadece bir bit 1 ise 1 döner
~ --> (NOT) bitleri tersine çevirir
<< --> sola kaydırır
>> --> sağa kaydırır


*/

#include <stdio.h>


int main(){

	int num = 5; // Binary: 0101
	int bit_position = 1; // 3 2 1 0  ---> index pozisyonu olarak düşün, 1 numaralı 
					// biti kontrol etmek istiyoruz
					
	if(num & (1 << bit_position)){ 
		// 1'in binary değeri : 0001
		// << operatörü 1'in yani 0001'in bitlerini
		// bit_position kadar (yani 1)
		// sola kaydırır
		// 1 << 1  ----> 0001 değerini 1 sola kaydır demektir
		// 0001 << 1    ==  0010
		// Şimdi sadece 1. indexi 1 olan diğerleri sıfır olan bir maske oluşturduk
		// num & (1 << bit_position) 
		// num = 5  yani 0101 ve 0010'ı & operatörü ile karşılaştıralım
		
		// num    0101
		// mask   0010
		// result 0000  yani 0
		
		printf("Bit %d is set\n", bit_position);
	}else{
		printf("Bit %d is not set\n", bit_position);
	}




	// -------------------- Bit ayarlama
	
	
	
	
	
	int num2 = 4; // 0100
	int bit_position2 = 0; // 3 2 1 0   --> 0. index
	num2 |= (1 << bit_position);
		// önce 1'i yani 0001'i bit_position2 kadar sola kaydır (<<)
		// bit_position2 = 0 olduğuna göre 1 yani 0001 sabit kaldı
		// maskemiz 0001
		// şimdi num ile | işlemine alalım
		// num2 = 0100
		// mask = 0001
		// şimdi num2 |= mask
		// result = 0101 oldu
	printf("%d\n", num);  // 0101 yani 5 çıktısını verir
	
	
	
	

	// -------------------- Bit temizleme



	int num3 = 5;  // Binary : 0101
	int bit_position3 = 1;  
	num3 &= ~(1 << bit_position);  // 0101 & ~0010 = 
				      // 0101 &  1101
				      // sonuç = 0101
	printf("%d\n", num3);  // Çıktı 5 olacak çünkü sonuç 0101 oldu
	





	// -------------------- Bit değiştirme
	
	
	
	int num4 = 5;  // Binary: 0101
	int bit_position4 = 1;
	num4 ^= (1 << bit_position4);  // öncelikle 1'in bit karşılığı: 0001
				// 1 << bit_position == sonuç == 0010
				// şimdi 0101(num4) ^ 0010
				// 0101 ^ 0010   ==  0111  (sadece bir bit 1 ise 1 döner)
	printf("%d\n", num4); // Çıktı 7(0111)






	// -------------------- Bir bit çıkarma işlemi:
	
	
	int num5 = 5; // 0101
	int bit_position5 = 1;
	int bit_value = (num5 >> bit_position5) & 1; 
		// num5(0101)'i bit_position kadar (1) sağa kaydır
		// num5 == 0010 oldu
		// 0010 & 1 (0001)  === 0000 oldu yani 0
	
	printf("Bit %d is %d\n", bit_position5, bit_value);  // Bit 1 is 0
	
	
	
	
	
	
	
	
	// -------------------- Kaç tane 1 bit var?
	
	
	int num6 = 13; // Binary 1101 (3 bits set)
	int count = 0;
	while(num){
		count += num & 1;
		num >>= 1;  // shift right
	}
	
	printf("Set bits: %d\n", count); 

	// mantığı şu: 
	// 0001 maskemiz bu 
	// Biz num6'nın her seferinde 0. indexini 0001 ile & işlemine sokuyoruz
	// sonucu da count'ta tutuyoruz
	// her seferinde num6'yı sağa kaydırdık
	// günün sonunda 0. indexten 3 kez 1 biti geçti
	// count 3 oldu 





	return 0;
}












