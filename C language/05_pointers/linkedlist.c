// linked_list_demo.c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create_node(int value) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) { perror("malloc failed"); exit(EXIT_FAILURE); }
    n->data = value;
    n->next = NULL;
    return n;
}

void print_list(const Node *head) {
    printf("head");
    while (head) {
        printf(" -> %d", head->data);
        head = head->next;
    }
    printf(" -> NULL\n");
}

void free_list(Node **head) {
    Node *cur = *head;
    while (cur) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    *head = NULL;
}

void push_front(Node **head, int value) {
    Node *n = create_node(value);
    n->next = *head;
    *head = n;
}

void push_back(Node **head, int value) {
    Node *n = create_node(value);
    if (*head == NULL) { *head = n; return; }
    Node *cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

int pop_front(Node **head, int *out_value) {
    if (*head == NULL) return 0;
    Node *old = *head;
    if (out_value) *out_value = old->data;
    *head = old->next;
    free(old);
    return 1;
}

int main(void) {
    Node *head = NULL;

    // 1) Başa eklemeler
    push_front(&head, 20);
    push_front(&head, 10); // 10 -> 20
    print_list(head);

    // 2) Sona eklemeler
    push_back(&head, 30);
    push_back(&head, 40);  // 10 -> 20 -> 30 -> 40
    print_list(head);

    // 3) Baştan sil
    int removed;
    if (pop_front(&head, &removed)) {
        printf("Baştan silindi: %d\n", removed); // 10
    }
    print_list(head); // 20 -> 30 -> 40

    free_list(&head);
    return 0;
}

