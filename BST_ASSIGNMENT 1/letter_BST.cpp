#include "letter_BST.h"

Letter_BST::Letter_BST() {
    this->root=nullptr;
}

void Letter_BST::insertNode(char key) {
    this->root = insertHelper(key, this->root);
}
void Letter_BST::deleteNode(char key) {
    this->root = deleteHelper(key, this->root);
}
Letter_BST_NODE* Letter_BST::searchKey(char key){
    return searchKeyHelper(key, this->root);
}

Letter_BST_NODE* Letter_BST::insertHelper(char input, Letter_BST_NODE* root) {
    //Base case
    if (root == nullptr) {
        root = new Letter_BST_NODE(input);

    } else {
        //induction hypothesis
        if (root->data > input) {
            root->left = insertHelper(input, root->left);
        } else if (root->data < input) {
            root->right = insertHelper(input, root->right);
        }
        else {
            cout << root->data  << "\netter is already there in the BST\n";
        }

    }
    //return value
    return root;
}
Letter_BST_NODE* Letter_BST::deleteHelper(char input, Letter_BST_NODE* searchNode) {
    if(searchNode == nullptr){
        return nullptr;
    }
    if(input > searchNode->data){
        searchNode->right = deleteHelper(input, searchNode->right);
    }
    else if(input < searchNode->data){
        searchNode->left = deleteHelper(input, searchNode->left);
    }
    else{
        cout << "/////////////////////////Testing///////////////////////////////\n";
        if(searchNode->left == nullptr and searchNode->right == nullptr){
            delete searchNode;
            return nullptr;
        }
        else if(searchNode->right == nullptr){
            Letter_BST_NODE* tempLeft = searchNode->left;
            searchNode->left = nullptr;
            delete searchNode;
            return tempLeft;
        }
        else if(searchNode->left == nullptr){
            Letter_BST_NODE* tempRight = searchNode->right;
            searchNode->right = nullptr;
            delete searchNode;
            return tempRight;
        }
        else{
            Letter_BST_NODE* minNode = searchNode->right;
            while(minNode->left != nullptr){
                minNode = minNode->left;
            }
            char minValue = minNode->data;
            searchNode->data = minValue;
            searchNode->right = deleteHelper(minValue, searchNode->right);
            return searchNode;
        }
    }
    return searchNode;
}


Letter_BST_NODE* Letter_BST::searchKeyHelper(char key, Letter_BST_NODE* searchNode){

    if(searchNode == nullptr){
        return nullptr;
    }

    if(key == searchNode->data){
        return searchNode;
    }
    else if(key > searchNode->data){
        return searchKeyHelper(key, searchNode->right);
    }
    else{
        return searchKeyHelper(key, searchNode->left);
    }

}



