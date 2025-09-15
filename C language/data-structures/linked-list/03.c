// Bağlı listeyi sıralama



#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;
} Node;


struct Node* createLinkedList(int data){
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
};



void writeLinkedList(struct Node* head){
    Node* iter = head;
    while(iter != NULL){
        printf("Data: %d\n", iter->data);
        iter = iter->next;
    }

    printf("\n------------\n");
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



void delete_node_from_linkedList(struct Node** linkedList, int data){

    Node* temp;
    Node* iter = *linkedList;
    

    if(*linkedList == NULL){
        printf("LinkedList boş\n");

    }else if((*linkedList)->data == data){ 
        temp = (*linkedList)->next; 
        free(*linkedList); 
        *linkedList = temp; 
    
    }else{
        while(iter->data != data && iter != NULL){
            temp = iter;
            iter = iter->next;
        }
        
        if(iter == NULL){
            
            printf("Silmek istediğiniz veri bu listede mevcut değil.");
        }else{ 

            temp->next = iter->next;
            free(iter);
        }

    }


}



// Bu sefer de listeyi sıralayalım

void liste_sirala(struct Node** liste_basi){
    struct Node *a, *b, *c, *d;

    if(*liste_basi == NULL || (*liste_basi)->next == NULL) return;
    d = (*liste_basi)->next;

    (*liste_basi)->next = NULL;
    while(d != NULL){
        c = d;
        d = d->next;
        b = *liste_basi;

        while(b != NULL && b->data < c->data){
            a = b;
            b = b->next;
        }

        if(b == *liste_basi){
            c->next = *liste_basi;
            *liste_basi = c;

        }else{
            a->next = c;
            c->next = b;
        }
    }
}


int main(){

    Node* n = createLinkedList(10);
    add_node_head_of_linkedList(&n, 5); 
    add_node_head_of_linkedList(&n, 11);
    add_node_end_of_linkedList(&n, 21);
    add_node_end_of_linkedList(&n, 51);
    writeLinkedList(n);
    delete_node_from_linkedList(&n, 11);
    
    writeLinkedList(n);

    liste_sirala(&n);


    delete_node_from_linkedList(&n, 51);
    writeLinkedList(n);


    delete_node_from_linkedList(&n, 5);
    writeLinkedList(n);

    return 0;
}