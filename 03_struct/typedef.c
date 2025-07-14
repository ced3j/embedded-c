/*

typedef C dilinde var olan bir veri tipine yeni bir isim (takma ad) vermek için kullanılır
Yani uzun veya karmaşık bir tipi daha kısa ve okunabilir hale getirir.


Mesela:

typedef unsigned int uint;

Bu örnekte unsigned int C'de var olan bir veri tipi
Bu tipe uint takma adını veriyoruz

uint sayi = 10;   // unsigned int demek ile aynı şey oluyor




Veya structlar üzerinden bir örnek:

Normalde:
	struct Nokta {
		int x;
		int y;
	};
	
	struct Nokta n;
	
	
Ama typedef ile:
	typedef struct{
		int x;
		int y;
	} Nokta;
	
	
	Nokta n;


*/













