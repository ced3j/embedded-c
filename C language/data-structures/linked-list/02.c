// Bağlı listeden düğüm silme

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



// Bu sefer silme fonksiyonu ekleyelim
void delete_node_from_linkedList(struct Node** linkedList, int data){

    Node* temp;
    Node* iter = *linkedList;
    

    // Liste boş mu onu kontrol edelim first

    if(*linkedList == NULL){
        printf("LinkedList boş\n");

    }else if((*linkedList)->data == data){ // Silinmesini istediğimiz eleman ilk sıradaysa
        temp = (*linkedList)->next; // linkedList'i kaybetmemek için temp'i nextine eşitledik
        free(*linkedList); // *linkedList'i yani ilk elemanı yok et
        *linkedList = temp; // şimdi linkedList'i temp'e eşitle ordan devam etsin
    
    }else{  // ilk iki özel durumu kontrol ettik şimdi listenin geri kalanına bakalım

        while(iter->data != data && iter != NULL){
            temp = iter;
            iter = iter->next;
        }
        
        if(iter == NULL){
            // iter NULL'a ulaşmışsa demek ki silmek istediğimiz data döngüde yok
            printf("Silmek istediğiniz veri bu listede mevcut değil.");
        }else{ // data'nın bulunduğu durum

            temp->next = iter->next;
            free(iter);
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


    delete_node_from_linkedList(&n, 51);
    writeLinkedList(n);


    delete_node_from_linkedList(&n, 5);
    writeLinkedList(n);

    return 0;
}