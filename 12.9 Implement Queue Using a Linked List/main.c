#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ItemType;

enum command {ENQUEUE = 1, DEQUEUE, END};
typedef enum command Command;

enum comparisonResult {SMALLER = -1, EQUAL, BIGGER};
typedef enum comparisonResult ComparisonResult;

struct node {
    ItemType data;
    struct node* nextPtr;
};

typedef struct node Node;
typedef Node* NodePtr;

struct list {
    NodePtr headPtr;
};
typedef struct list List;
typedef List* ListPtr;

struct queue {
    List list;
    NodePtr tailPtr;
};
typedef struct queue Queue;
typedef Queue* QueuePtr;

bool isEmpty(NodePtr nodePtr);
void printItemType(ItemType value);
ItemType getItemType(void);
ItemType getItemTypeRandomly(void);
void printList(ListPtr listPtr);
void instructions(void);
Command getCommand(void);
bool enqueue(QueuePtr queuePtr, ItemType value);
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
                if (!isEmpty(myQueue.list.headPtr)) {
                    value = dequeue(&myQueue);
                    printf("%s", "The value dequeued is ");
                    printItemType(value);
                    puts("");
                }
                break;
            default:
                break;
        }
        
        printList(&myQueue.list);
        option = getCommand();
    }
}

ComparisonResult compare(NodePtr nodePtr, ItemType value);
NodePtr findPrevLocation(ListPtr listPtr, ItemType value);
bool insert(ListPtr listPtr, ItemType value);
bool delete(ListPtr listPtr, ItemType value);
List initializeList(void);

// There are list function definitions below
bool enqueue(QueuePtr queuePtr, ItemType value) {
    if (insert(&queuePtr->list, value)) {
        if (isEmpty(queuePtr->tailPtr)) {
            queuePtr->tailPtr = queuePtr->list.headPtr;
        }
        return true;
    }
    
    return false;
}

ItemType dequeue(QueuePtr queuePtr) {
    ItemType value = queuePtr->tailPtr->data;
    delete(&queuePtr->list, queuePtr->tailPtr->data);
    
    if (isEmpty(queuePtr->list.headPtr)) {
        queuePtr->tailPtr = NULL;
    }
    else {
        NodePtr nodePtr = queuePtr->list.headPtr;
        while (!isEmpty(nodePtr->nextPtr)) {
            nodePtr = nodePtr->nextPtr;
        }
        queuePtr->tailPtr = nodePtr;
    }
    
    return value;
}

List initializeList(void) {
    List myList = {NULL};
    return myList;
}

bool isEmpty(NodePtr nodePtr) {
    return nodePtr == NULL;
}

bool insert(ListPtr listPtr, ItemType value) {
    NodePtr nodePtr = malloc(sizeof(Node));
    
    if(!isEmpty(nodePtr)) {
        nodePtr->data = value;
        nodePtr->nextPtr = listPtr->headPtr;
        listPtr->headPtr = nodePtr;
        return true;
    }
    else {
        return false;
    }
}

bool delete(ListPtr listPtr, ItemType value) {
    NodePtr nodePtr = findPrevLocation(listPtr, value);
    NodePtr tempPtr = NULL;
    
    if (isEmpty(nodePtr) && !isEmpty(listPtr->headPtr)) {
        if (compare(listPtr->headPtr, value) == EQUAL) {
            tempPtr = listPtr->headPtr;
            listPtr->headPtr = tempPtr->nextPtr;
            free(tempPtr);
            return true;
        }
    }
    else if (!isEmpty(nodePtr) && !isEmpty(nodePtr->nextPtr)){
        tempPtr = nodePtr->nextPtr;
        nodePtr->nextPtr = tempPtr->nextPtr;
        free(tempPtr);
        return true;
    }
    
    return false;
}

NodePtr findPrevLocation(ListPtr listPtr, ItemType value) {
    if (isEmpty(listPtr->headPtr) || compare(listPtr->headPtr, value) == EQUAL) {
        return NULL;
    }
    else {
        NodePtr nodePtr = listPtr->headPtr;
        
        while (!isEmpty(nodePtr->nextPtr) && compare(nodePtr->nextPtr, value) != EQUAL) {
            nodePtr = nodePtr->nextPtr;
        }
        
        return nodePtr;
    }
}


ComparisonResult compare(NodePtr nodePtr, ItemType value) {
    if (isEmpty(nodePtr) || nodePtr->data > value) {
        return BIGGER;
    }
    else if (nodePtr->data == value){
        return EQUAL;
    }
    else {
        return SMALLER;
    }
}

void printItemType(ItemType value) {
    printf("%d", value);
}

ItemType getItemType(void) {
    ItemType value;
    scanf("%d", &value);
    return value;
}

ItemType getItemTypeRandomly(void) {
    return rand() % 10;
}

void printList(ListPtr listPtr) {
    NodePtr nodePtr = listPtr->headPtr;
    
    puts("The list is: ");
    
    while (!isEmpty(nodePtr)) {
        printItemType(nodePtr->data);
        printf("%s", " --> ");
        nodePtr = nodePtr->nextPtr;
    }
    
    puts("NULL\n");
}

void swap(NodePtr* nodePtrPtr, NodePtr* nodePtrPtr2) {
    NodePtr tempPtr = *nodePtrPtr;
    *nodePtrPtr = *nodePtrPtr2;
    *nodePtrPtr2 = tempPtr;
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
