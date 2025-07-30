/*
Bit-field struct içinde tanımlanan değişkenlerin kaç bitlik alan kaplayacağını
doğrudan belirlemene olanak sağlar


	struct {
		unsigned int a : 3;  // a, 3 bit yer kaplar
	}


	// normalde bir int 4 byte (32 bit) yer kaplar. Ama burada biz diyoruz ki:
		"Ben a için sadece 3 bitlik alan istiyorum"
		
		
		
		
====================================================================
		
		
	--- BİT SAYISI NE DEMEK? ---

	1 bit --> maksimum değer 0-1
	2 bit --> maksimum değer 0-3
	3 bit --> maksimum değer 0-7
	4 bit --> maksimum değer 0-15
	.
	.
	.
	
	yani 
	unsigned int a : 3; --> durum.a = 7; başarılı
		durum.a = 8; taşma olabilir...
		

====================================================================

	struct Normal{
		unsigned int a;
		unsigned int b;
	}
	// bu struct bellekte 2x4 byte = 8 byte yer kaplar


	struct Bitli{
		unsigned int a : 4;
		unsigned int b : 4;	
	}
	// bu struct ise 1 byte = 8 bit yer kaplar

*/


struct Bayraklar {
	unsigned int motorAcik 	: 1;
	unsigned int hataVar 	: 1;
	unsigned int sistemHazir: 1;
	unsigned int rezerve 	: 5; // toplam 8 bit = 1 byte
};



#include <stdio.h>


int main(){
	
	struct Bayraklar durum = {1, 0, 1, 0};
	
	printf("Motor acik mi? %d\n", durum.motorAcik);		// 1
	printf("Hata var mi? %d\n", durum.hataVar);		// 0
	printf("Sistem hazir mi? %d\n", durum.sistemHazir);	// 1

	return 0;
}
