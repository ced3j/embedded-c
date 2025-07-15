/*

C dilinde string aslında null karakter '\0' ile 
sonlandırılmış bir char dizisidir

*/


#include <stdio.h>


int main(){
	
	char *str = "Merhaba";
	
	printf("str: %s\n", str);   // Merhaba
	printf("İlk karakter: %c\n", *str);  // M
	printf("3. karakter: %c\n", *(str + 2));  
	
	
	while(*str != '\0'){
		printf("%c-", *str);
		str++; // sonraki harfe geç
	}
	
	
	return 0;
	
}
