// C program to get intersection point of two linked list
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node *getIntesectionNode(Node* head1,Node* head2){
    while(head2){
        Node *temp = head1;
        while(temp){
            if(temp == head2){
                return temp;
            }
            temp = temp->next;
        }
        head2 = head2->next;
    }
    return NULL;
}

int main(){
    Node* newNode;
    //initialize linked list 1
    Node* head1 = (Node*)malloc(sizeof(Node));
    head1->data = 10;

    newNode = (Node*)malloc(sizeof(Node));
    head1->next = newNode;
    newNode->data = 15;

    newNode = (Node*)malloc(sizeof(Node));
    head1->next->next = newNode;
    newNode->data = 30;

    newNode->next = NULL;

    //initialize linked list 2
    Node* head2 = (Node*)malloc(sizeof(Node));
    head2->data = 3;

    newNode = (Node*)malloc(sizeof(Node));
    head2->next = newNode;
    newNode->data = 6;

    newNode = (Node*)malloc(sizeof(Node));
    head2->next->next = newNode;
    newNode->data = 9;

    newNode = head1->next;  //the intersection point
    head2->next->next->next = newNode;


    Node* intersectionPoint = getIntesectionNode(head1,head2);
    if(!intersectionPoint){
        printf("no intersection point!\n");
    }
    else{
        printf("Intersection at: %d", intersectionPoint->data);
    }

    return 0;
}
