void printBinaryTree(NodePtr root) {
    static int column = 0;
    
    if (isEmpty(root)) {
        return;
    }
    
    column += 5;
    printBinaryTree(root->rightPtr);
    column -= 5;
    
    printf("%*c", column, ' ');
    printItemType(root->data);
    puts("");
    
    column += 5;
    printBinaryTree(root->leftPtr);
    column -= 5;
}
