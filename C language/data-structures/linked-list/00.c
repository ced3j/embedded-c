#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;


void writeLinkedList(struct Node* head){
    
    // eğer iter oluşturmayıp doğrudan parametreden gelen head
    // üzerinden işlem yapmaya kalkarsak
    // fonk bittikten sonra head artık listenin başını göstermiyor olur
    // ve işler karışır, başlangıç adresini kaybederiz :)
    
    Node* iter = head;
    while(iter != NULL){
        printf("Data: %d\n", iter->data);
        iter = iter->next;
    }
}


int main(){

    Node* n = (Node*)malloc(sizeof(Node));  // Bellekte 1 adet nodeluk boşluk ayırdık
    n->data = 10;
    n->next = (Node*)malloc(sizeof(Node)); // next'i yeni bir Node'a bağladık

    n->next->data = 20;
    n->next->next = NULL; // Son node bu olsun


    printf("%d\n", n->data);
    printf("%d\n", n->next->data);

    printf("\n---\n");

    printf("Adres1 : %p\n", &(n->data));
    // veya (void*)&(n->data)
    printf("Adres2: %p\n", (void*)&(n->next->data));


    printf("\n-------------\n");

    writeLinkedList(n);



    return 0;
}