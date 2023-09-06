#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

struct listNode {
    char data;
    struct listNode* nextPtr;
};

enum command {INSERT = 1, DELETE, END};

typedef struct listNode ListNode;
typedef ListNode* List;
typedef enum command Command;

bool isEmpty(const List list);
void delete(List* listPtr, char value);
void insert(List* listPtr, char value);
void printList(const List list);
void instructions(void);
Command getCommand(void);
int compare(ListNode* nodePtr, char value);
ListNode* findPrevLocation(const List list, char value);

int main(void) {
    instructions();
    Command option = getCommand();
    char c;
    List myList = NULL;
    
    while (option != END) {
        printf("%s", "Enter a character: ");
        while (!isgraph(c = getchar()));
        
        switch (option) {
            case INSERT:
                insert(&myList, c);
                break;
            case DELETE:
                delete(&myList, c);
                break;
            default:
                break;
        }
        
        printList(myList);
        option = getCommand();
    }
}

void delete(List* listPtr, char value) {
    ListNode* nodePtr = findPrevLocation(*listPtr, value);
    
    if (isEmpty(nodePtr)) {
        if (compare(*listPtr, value) == 0) {
            nodePtr = *listPtr;
            *listPtr = nodePtr->nextPtr;
            free(nodePtr);
        }
    }
    else if (compare(nodePtr->nextPtr, value) == 0) {
        ListNode* tempPtr = nodePtr->nextPtr;
        nodePtr->nextPtr = tempPtr->nextPtr;
        free(tempPtr);
    }
}

void insert(List* listPtr, char value) {
    ListNode* createNodePtr(char c, ListNode* nextPtr);
    
    ListNode* nodePtr = findPrevLocation(*listPtr, value);
    
    if (isEmpty(nodePtr)) {
        if (compare(*listPtr, value) > 0) {
            nodePtr = createNodePtr(value, *listPtr);
            *listPtr = nodePtr;
        }
    }
    else if (compare(nodePtr->nextPtr, value) > 0) {
        ListNode* tempPtr = createNodePtr(value, nodePtr->nextPtr);
        nodePtr->nextPtr = tempPtr;
    }
}

ListNode* createNodePtr(char c, ListNode* nextPtr) {
    ListNode* nodePtr = malloc(sizeof(ListNode));
    nodePtr->data = c;
    nodePtr->nextPtr = nextPtr;
    return nodePtr;
}

bool isEmpty(const List list) {
    return list == NULL;
}

void printList(const List list) {
    for (ListNode* nodePtr = list; nodePtr != NULL; nodePtr = nodePtr->nextPtr) {
        printf("%c --> ", nodePtr->data);
    }
    printf("NULL\n");
}

void instructions(void) {
    puts("Enter your choice:");
    puts("1 to insert an element into the list.");
    puts("2 to delete an element from the list.");
    puts("3 to end.");
}

Command getCommand(void) {
    Command option;
    printf("%s", "? ");
    scanf("%d", &option);
    return option;
}

ListNode* findPrevLocation(List list, char value) {
    if (isEmpty(list) || list->data >= value) {
        return NULL;
    }
    else {
        while (list->nextPtr != NULL && list->nextPtr->data < value) {
            list = list->nextPtr;
        }
        
        return list;
    }
}

int compare(ListNode* nodePtr, char value) {
    if (nodePtr == NULL || nodePtr->data > value) {
        return 1;
    }
    else if (nodePtr->data == value) {
        return 0;
    }
    else {
        return -1;
    }
}
