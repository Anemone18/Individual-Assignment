#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int score;
    Node *next; 
} *head, *tail, *temp = NULL;

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

void pushMid(int value) {
    Node* temp = createNode(value);
    if (!head) {
        head = tail = temp;
    }
    else if (head->score < value) {
        pushHead(value);
    }
    else if (tail->score >= value) {
        pushTail(value);
    }
    else {
        Node* curr = head;
        while (curr->next && curr->next->score > value) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}
void reverse() {
    Node* curr = head;
    while (curr) {
        Node* newNode = createNode(curr->score);
        newNode->next = temp;
        temp = newNode;
        curr = curr->next;
    }
    while (temp) {
        if (!temp->next) {
            printf("%d\n", temp->score);
        }
        else {
            printf("%d -> ", temp->score);
        }
        temp = temp->next;
    }
    puts("");
}

void printList(){
    if (!head) {
        return;
    }
    Node* temp = head;
    while (temp) {
        if (!temp->next) {
            printf("%d\n", temp->score);
        }
        else {
            printf("%d -> ", temp->score);
        }
        temp = temp->next;
    }
}

int main (){
    int index;
    pushHead(100);
    pushHead(90);
    pushHead(80);
    pushHead(70);
    pushHead(120);
    printList();
    reverse();
    return 0;
}