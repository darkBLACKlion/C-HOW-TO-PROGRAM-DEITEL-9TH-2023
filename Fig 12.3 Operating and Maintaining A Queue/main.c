#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

enum command {ENQUEUE = 1, DEQUEUE, END};
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

ItemType getItemType(void);
void instructions(void);
Command getCommand(void);
bool isNodeNull(NodePtr nodePtr);
void printItemType(ItemType value);
void printLinkedStructure(NodePtr nodePtr);
void enqueue(QueuePtr queuePtr, ItemType value);
ItemType dequeue(QueuePtr queuePtr);

int main(void) {
    instructions();
    Command option = getCommand();
    ItemType value;
    Queue myQueue = {NULL, NULL};
    
    while (option != END) {
        switch (option) {
            case ENQUEUE:
                printf("%s", "Enter a character: ");
                value = getItemType();
                enqueue(&myQueue, value);
                break;
            case DEQUEUE:
                if (!isNodeNull(myQueue.headPtr)) {
                    value = dequeue(&myQueue);
                    printf("%s", "The value dequeued is ");
                    printItemType(value);
                    puts("");
                }
                break;
            default:
                break;
        }
        
        printLinkedStructure(myQueue.headPtr);
        option = getCommand();
    }
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
