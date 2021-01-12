#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int score;
    Node *next; 
} *head, *tail; 

int LargestElemenet(Node *curr){
    int max = 0;
    Node* temp = curr;
    while (temp){
        if (max < temp->score){
            max = temp->score; 
        }
        temp = temp->next; 
    } 
    return max; 
} 
int SmallestElement(Node *curr) { 
    int min = curr->score;
    Node* temp = curr;
    while (temp) { 
        if (min > temp->score){
            min = temp->score; 
        }  
        temp = temp->next; 
    } 
    return min; 
} 

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

void popHead (){
    if (!head){ 
        return; 
    } else if (head==tail){ 
        free(head);
        head = tail = NULL;
    } else { 
        Node *temp = head->next;
        head->next = NULL;
        free(head); 
        head = temp;
    }

}

void popTail (){
    if (!head){
        return;
    } else if (head==tail){
        free(head);
        head = tail = NULL;
    } else { 
        Node *temp = head; 
        while(temp->next != tail){
            temp = temp->next; 
        }
        temp->next = NULL;
        free(tail);
        tail = temp;
    }
}

void printList(){
    Node *curr = head; 

    while (curr){ 
        printf ("%d -> ", curr->score);
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

    int minScore = SmallestElement(head);
    printf ("Min Score: %d\n", minScore);
    int maxScore = LargestElemenet(head);
     printf ("Max Score: %d\n", maxScore);
    return 0;
}