// Bağlı listenin başına ve sonuna düğüm ekleme

#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;
} Node;


// bu sefer liste oluşturma işini bir fonksiyon üzerinden yapalım
struct Node* createLinkedList(int data){
    Node* n = (Node*)malloc(sizeof(Node)); // Node kadar yer ayırdık
    n->data = data; // parametreden gelen datayı atadık
    n->next = NULL;
    return n;
};



void writeLinkedList(struct Node* head){
    Node* iter = head;
    while(iter != NULL){
        printf("Data: %d\n", iter->data);
        iter = iter->next;
    }
}


void add_node_head_of_linkedList(struct Node** linkedList, int data){
    Node* newLinkedList = createLinkedList(data);
    newLinkedList->next = *linkedList;
    *linkedList = newLinkedList;
}


void add_node_end_of_linkedList(struct Node** linkedList, int data){
    Node* iter = *linkedList;
    while(iter->next != NULL){
        iter = iter->next;
    }
    Node* newLinkedList = createLinkedList(data);
    iter->next = newLinkedList;
    newLinkedList->next = NULL;
}


int main(){

    Node* n = createLinkedList(10);
    add_node_head_of_linkedList(&n, 5); 
    add_node_head_of_linkedList(&n, 11);
    add_node_end_of_linkedList(&n, 21);
    add_node_end_of_linkedList(&n, 51);
    
    writeLinkedList(n);
    return 0;
}