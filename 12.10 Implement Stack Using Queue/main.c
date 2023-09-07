#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

enum command {PUSH = 1, POP, END};
typedef enum command Command;

typedef char ItemType;

struct node {
    ItemType data;
    struct node* nextPtr;
};
typedef struct node Node;
typedef Node* NodePtr;

struct queue {
    NodePtr headPtr;
    NodePtr tailPtr;
};

typedef struct queue Queue;
typedef Queue* QueuePtr;

struct stack {
    Queue queue;
};
typedef struct stack Stack;
typedef Stack* StackPtr;

ItemType getItemType(void);
void instructions(void);
Command getCommand(void);
bool isNodeNull(NodePtr nodePtr);
void printItemType(ItemType value);
void printLinkedStructure(NodePtr nodePtr);
void enqueue(QueuePtr queuePtr, ItemType value);
ItemType dequeue(QueuePtr queuePtr);
ItemType pop(StackPtr stackPtr);
void push(StackPtr stackPtr, ItemType value);

int main(void) {
    instructions();
    Command option = getCommand();
    ItemType value;
    Stack myStack;
    myStack.queue.headPtr = NULL;
    myStack.queue.tailPtr = NULL;
    
    while (option != END) {
        switch (option) {
            case PUSH:
                printf("%s ", "Enter an item:");
                value = getItemType();
                push(&myStack, value);
                break;
            case POP:
                if (!isNodeNull(myStack.queue.headPtr)) {
                    value = pop(&myStack);
                    printf("%s", "The popoed value is ");
                    printItemType(value);
                    puts("");
                }
                break;
            default:
                break;
        }
        
        printLinkedStructure(myStack.queue.headPtr);
        option = getCommand();
    }
}

void push(StackPtr stackPtr, ItemType value) {
    Queue tempQueue = {NULL, NULL};
    
    while (!isNodeNull(stackPtr->queue.headPtr)) {
        enqueue(&tempQueue, pop(stackPtr));
    }
    
    enqueue(&stackPtr->queue, value);
    
    while (!isNodeNull(tempQueue.headPtr)) {
        enqueue(&stackPtr->queue, dequeue(&tempQueue));
    }
}

ItemType pop(StackPtr stackPtr) {
    ItemType value = stackPtr->queue.headPtr->data;
    dequeue(&stackPtr->queue);
    return value;
}

void enqueue(QueuePtr queuePtr, ItemType value) {
    NodePtr nodePtr = malloc(sizeof(Node));
    
    if (!isNodeNull(nodePtr)) {
        nodePtr->data = value;
        nodePtr->nextPtr = NULL;
        
        if (isNodeNull(queuePtr->headPtr)) {
            queuePtr->headPtr = nodePtr;
        }
        else {
            queuePtr->tailPtr->nextPtr = nodePtr;
        }
        
        queuePtr->tailPtr = nodePtr;
    }
    else {
        puts("There is no empty space in memory");
    }
}

ItemType dequeue(QueuePtr queuePtr) {
    NodePtr tempNode = queuePtr->headPtr;
    ItemType value = tempNode->data;
    queuePtr->headPtr = tempNode->nextPtr;
    
    if (isNodeNull(queuePtr->headPtr)) {
        queuePtr->tailPtr = NULL;
    }
    
    free(tempNode);
    return value;
}

bool isNodeNull(NodePtr nodePtr) {
    return nodePtr == NULL;
}

void printLinkedStructure(NodePtr nodePtr) {
    while (nodePtr != NULL) {
        printItemType(nodePtr->data);
        printf("%s", " --> ");
        nodePtr = nodePtr->nextPtr;
    }
    
    puts("NULL\n");
}

void printItemType(ItemType value) {
    printf("%c", value);
}

ItemType getItemType(void) {
    ItemType value;
    while (!isgraph(value = getchar()));
    return value;
}

void instructions(void) {
    puts("Enter choice:");
    puts("1 to enqueue a value to the queue");
    puts("2 to dequeue a value from the queue");
    puts("3 to end program");
}

Command getCommand(void) {
    printf("%s ", "?");
    Command option;
    scanf("%d", &option);
    return option;
}
