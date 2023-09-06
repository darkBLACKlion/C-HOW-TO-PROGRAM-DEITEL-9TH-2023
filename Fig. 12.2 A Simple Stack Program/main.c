#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

enum command {PUSH = 1, POP, END};
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

ItemType getItem(void);
void instructions(void);
Command getCommand(void);
void push(Stack* stackPtr, ItemType value);
bool isNodeEmpty(NodePtr nodePtr);
ItemType pop(StackPtr stackPtr);
void printItem(ItemType value);
void printLinkedStructure(NodePtr nodePtr);

int main(void) {
    instructions();
    Command option = getCommand();
    ItemType value;
    Stack myStack = {NULL};
    
    while (option != END) {
        switch (option) {
            case PUSH:
                printf("%s ", "Enter an item:");
                value = getItem();
                push(&myStack, value);
                break;
            case POP:
                if (!isNodeEmpty(myStack.topPtr)) {
                    value = pop(&myStack);
                    printf("%s", "The popoed value is ");
                    printItem(value);
                    puts("");
                }
                break;
            default:
                break;
        }
        
        printLinkedStructure(myStack.topPtr);
        option = getCommand();
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
