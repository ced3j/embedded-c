/*

Veri güvenliğini sağlamak ve yanlışlıkla yapılabilecek
Değişiklikleri engellemek için çok önemlidir

3 farklı senaryo vardır 


	const int *ptr ---> işaret edilen veri sabittir
	int *const ptr ---> pointer sabit(başka adres gösteremez)
	const int *const ptr ---> hem veri hem pointer sabit

*/


#include <stdio.h>

int main(){


	int x = 10;
	int y = 20;
	
	const int *ptr = &x;  // ptr x'in adresini tutar
	
	printf("ptr'nin işaret ettiği değer: %d\n", *ptr); // 10
	
	// *ptr = 15 ---> Hata verir, değeri değiştiremezsin.
	ptr = &y;   // adresi değiştirebiliriz
	
	printf("\nYeni adrese geçildi, değer: %d\n", *ptr);

	return 0;
}
