#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

enum command {ENQUEUE = 1, DEQUEUE, END};
typedef enum command Command;

typedef int ItemType;

struct node {
    ItemType data;
    struct node* nextPtr;
};
typedef struct node Node;
typedef Node* NodePtr;

struct stack {
    NodePtr topPtr;
};
typedef struct stack Stack;
typedef Stack* StackPtr;

struct queue {
    Stack myStack;
};
typedef struct queue Queue;
typedef Queue* QueuePtr;

ItemType getItem(void);
void instructions(void);
Command getCommand(void);
void push(Stack* stackPtr, ItemType value);
bool isNodeEmpty(NodePtr nodePtr);
ItemType pop(StackPtr stackPtr);
void printItem(ItemType value);
void printLinkedStructure(NodePtr nodePtr);
ItemType dequeue(QueuePtr queuePtr);
void enqueue(QueuePtr queuePtr, ItemType value);

int main(void) {
    instructions();
    Command option = getCommand();
    ItemType value;
    Queue myQueue = {NULL};
    
    while (option != END) {
        switch (option) {
            case ENQUEUE:
                printf("%s", "Enter a number: ");
                value = getItem();
                enqueue(&myQueue, value);
                break;
            case DEQUEUE:
                if (!isNodeEmpty(myQueue.myStack.topPtr)) {
                    value = dequeue(&myQueue);
                    printf("%s", "The value dequeued is ");
                    printItem(value);
                    puts("");
                }
                break;
            default:
                break;
        }
        
        printLinkedStructure(myQueue.myStack.topPtr);
        option = getCommand();
    }
}

ItemType dequeue(QueuePtr queuePtr) {
    return pop(&queuePtr->myStack);
}

void enqueue(QueuePtr queuePtr, ItemType value) {
    Stack tempStack = {NULL};
    
    while (!isNodeEmpty(queuePtr->myStack.topPtr)) {
        push(&tempStack, dequeue(queuePtr));
    }
    
    push(&queuePtr->myStack, value);
    
    while (!isNodeEmpty(tempStack.topPtr)) {
        push(&queuePtr->myStack, pop(&tempStack));
    }
}

ItemType pop(StackPtr stackPtr) {
    NodePtr nodePtr = stackPtr->topPtr;
    stackPtr->topPtr = nodePtr->nextPtr;
    ItemType value = nodePtr->data;
    free(nodePtr);
    return value;
}

void push(StackPtr stackPtr, ItemType value) {
    NodePtr nodePtr = malloc(sizeof(Node));
    
    if (!isNodeEmpty(nodePtr)) {
        nodePtr->data = value;
        nodePtr->nextPtr = stackPtr->topPtr;
        stackPtr->topPtr = nodePtr;
    }
    else {
        puts("There is no space in memory");
    }
}

bool isNodeEmpty(NodePtr nodePtr) {
    return nodePtr == NULL;
}

void printLinkedStructure(NodePtr nodePtr) {
    while (nodePtr != NULL) {
        printItem(nodePtr->data);
        printf("%s", " --> ");
        nodePtr = nodePtr->nextPtr;
    }
    
    puts("NULL\n");
}

void printItem(ItemType value) {
    printf("%d", value);
}

ItemType getItem(void) {
    ItemType value;
    scanf("%d", &value);
    return value;
}

void instructions(void) {
    puts("Enter choice:");
    puts("1 to push a value on the stack");
    puts("2 to pop a value off the stack");
    puts("3 to end program");
}

Command getCommand(void) {
    printf("%s ", "?");
    Command option;
    scanf("%d", &option);
    return option;
}
