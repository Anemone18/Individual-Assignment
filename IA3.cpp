#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int score;
    Node *next; 
} *head, *tail;

Node *createNode (int score){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

void pushHead(int score){
    Node *temp = createNode (score);
    if (!head){ 
        head = tail = temp;
    } else {
        temp->next = head; 
        head = temp; 
    }
}

void pushTail(int score){
    Node *temp = createNode (score);
    if (!head){ 
        head = tail = temp; 
    } else {
        tail->next = temp;
        tail = temp; 
    }
}


void pushMid(int score) {
    Node* temp = createNode (score);
    if (!head) {
        head = tail = temp;
    }else if (score > head->score) {
        pushHead(score);
    }else if (score <= tail->score) {
        pushTail(score);
    }else {
        Node* curr = head;
        while (curr->next && curr->next->score > score) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

void find() {
    int panjang = 1;
    Node* temp = head;
    if (!head) {
        return;
    }
    while (temp->next) {
        panjang++;
        temp = temp->next;
    }
    panjang = (panjang) / 2;
    Node* temp2 = head;
    while (panjang > 0) {
        temp2 = temp2->next;
        panjang--;
    }
    printf("Nilai dari Node Tengah adalah: %d\n", temp2->score);
}

void printList(){
    Node *curr = head;

    while (curr){ 
        printf ("%d -> ",curr->score);
        curr = curr->next;
    }
    puts("NULL");
}

int main (){
    pushHead(100);
    pushTail(90);
    pushHead(80);
    pushHead(70);
    printList();
    find();
    return 0;
}