#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef int ItemType;

enum command {INSERT = 1, DELETE, END};
typedef enum command Command;

struct node {
    struct node* leftPtr;
    ItemType data;
    struct node* rightPtr;
};
typedef struct node Node;
typedef Node* NodePtr;

struct tree {
    NodePtr rootPtr;
};
typedef struct tree Tree;
typedef Tree* TreePtr;

bool isEmpty(NodePtr nodePtr);
void updateNode(NodePtr nodePtr, NodePtr left, ItemType value, NodePtr right);
void insert(TreePtr treePtr, ItemType value);
void delete(TreePtr treePtr, ItemType value);
void inOrderTraversal(NodePtr nodePtr);
ItemType getItemTypeRandomly(void);
void printItemType(ItemType value);
void fillTreeRandomly(TreePtr treePtr, int numberOfElements);
ItemType getItemType(void);

int main(void) {
    srand(time(NULL));
    Tree myTree = {NULL};
    fillTreeRandomly(&myTree, 10);
    inOrderTraversal(myTree.rootPtr);
    puts("\n");
    
    while(myTree.rootPtr != NULL) {
        printf("%s", "Enter the item to be deleted: ");
        ItemType value = getItemType();
        delete(&myTree, value);
        inOrderTraversal(myTree.rootPtr);
        puts("\n");
    }
}

void delete(TreePtr treePtr, ItemType value) {
    void deleteRecursively(NodePtr nodePtr, ItemType value);
    void removeNodePtr(NodePtr* nodePtrPtr);
    
    if (!isEmpty(treePtr->rootPtr)) {
        if (treePtr->rootPtr->data == value) {
            removeNodePtr(&treePtr->rootPtr);
        }
        else {
            deleteRecursively(treePtr->rootPtr, value);
        }
    }
}

void deleteRecursively(NodePtr nodePtr, ItemType value) {
    void removeNodePtr(NodePtr* nodePtrPtr);
    
    if (value <= nodePtr->data) {
        if (!isEmpty(nodePtr->leftPtr)) {
            if (nodePtr->leftPtr->data == value) {
                removeNodePtr(&nodePtr->leftPtr);
            }
            else {
                deleteRecursively(nodePtr->leftPtr, value);
            }
        }
    }
    else if (!isEmpty(nodePtr->rightPtr)){
        if (nodePtr->rightPtr->data == value) {
            removeNodePtr(&nodePtr->rightPtr);
        }
        else {
            deleteRecursively(nodePtr->rightPtr, value);
        }
    }
}

void removeNodePtr(NodePtr* nodePtrPtr) {
    if (isEmpty((*nodePtrPtr)->leftPtr)) {
        NodePtr tempPtr = *nodePtrPtr;
        *nodePtrPtr = (*nodePtrPtr)->rightPtr;
        free(tempPtr);
    }
    else if (isEmpty((*nodePtrPtr)->rightPtr)){
        NodePtr tempPtr = *nodePtrPtr;
        *nodePtrPtr = (*nodePtrPtr)->leftPtr;
        free(tempPtr);
    }
    else {
        NodePtr tempPtr = (*nodePtrPtr)->leftPtr;
        while (!isEmpty(tempPtr->rightPtr)) {
            tempPtr = tempPtr->rightPtr;
        }
        
        (*nodePtrPtr)->data = tempPtr->data;
        deleteRecursively(*nodePtrPtr, tempPtr->data);
    }
}

void insert(TreePtr treePtr, ItemType value) {
    void insertRecursively(NodePtr nodePtr, ItemType value);
    
    if (isEmpty(treePtr->rootPtr)) {
        treePtr->rootPtr = malloc(sizeof(Node));
        updateNode(treePtr->rootPtr, NULL, value, NULL);
    }
    else {
        insertRecursively(treePtr->rootPtr, value);
    }
}

void insertRecursively(NodePtr nodePtr, ItemType value) {
    if (value > nodePtr->data) {
        if (nodePtr->rightPtr != NULL) {
            insertRecursively(nodePtr->rightPtr, value);
        }
        else {
            nodePtr->rightPtr = malloc(sizeof(Node));
            if (!isEmpty(nodePtr->rightPtr))
                updateNode(nodePtr->rightPtr, NULL, value, NULL);
        }
    }
    else if (value < nodePtr->data) {
        if (nodePtr->leftPtr != NULL) {
            insertRecursively(nodePtr->leftPtr, value);
        }
        else {
            nodePtr->leftPtr = malloc(sizeof(Node));
            if (!isEmpty(nodePtr->leftPtr))
                updateNode(nodePtr->leftPtr, NULL, value, NULL);
        }
    }
}

bool isEmpty(NodePtr nodePtr) {
    return nodePtr == NULL;
}

void updateNode(NodePtr nodePtr, NodePtr left, ItemType value, NodePtr right) {
    nodePtr->data = value;
    nodePtr->leftPtr = left;
    nodePtr->rightPtr = right;
}

void printItemType(ItemType value) {
    printf("%d", value);
}

ItemType getItemTypeRandomly(void) {
    return rand() % 10;
}

ItemType getItemType(void) {
    ItemType value;
    scanf("%d", &value);
    return value;
}

void inOrderTraversal(NodePtr nodePtr) {
    if (!isEmpty(nodePtr)) {
        inOrderTraversal(nodePtr->leftPtr);
        printItemType(nodePtr->data);
        printf("%s", " ");
        inOrderTraversal(nodePtr->rightPtr);
    }
}

void fillTreeRandomly(TreePtr treePtr, int numberOfElements) {
    puts("The numbers placed in the tree are:");
    
    for (int i = 0; i < numberOfElements; i++) {
        ItemType value = getItemTypeRandomly();
        printItemType(value);
        printf(" ");
        insert(treePtr, value);
    }
    
    puts("");
}
