#include <stdio.h>

#define MAX_NODES 100

typedef struct Node {
    int data;
    int next;
} Node;

Node pool[MAX_NODES];
int head = -1;
int freeList = 0;

void initPool() {
    for (int i = 0; i < MAX_NODES - 1; i++) {
        pool[i].next = i + 1;
    }
    pool[MAX_NODES - 1].next = -1;
}

void push(int data) {
    if (freeList == -1) {
        printf("Error: Memory pool is full\n");
        return;
    }
    int newNode = freeList;
    pool[newNode].data = data;
    freeList = pool[newNode].next;
    pool[newNode].next = head;
    head = newNode;
}

void printList() {
    printf("List: ");
    int currentNode = head;
    while (currentNode != -1) {
        printf("%d ", pool[currentNode].data);
        currentNode = pool[currentNode].next;
    }
    printf("\n");
}

int main() {
    initPool();

    push(5);
    push(10);
    push(15);
    push(20);

    printList();

    return 0;
}
