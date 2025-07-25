#include <stdio.h>


struct Book{
	char name[50];
	char author[50];	
};


int main(){
	
	struct Book Books[5];
	
	for(int i = 0; i < 5; i++){
		printf("Book no[%d], please enter book name: ", i);
		scanf("%s", Books[i].name);
		
		printf("Book no[%d], please enter the author: ", i);
		scanf("%s", Books[i].author);
	}
	
	return 0;
}
