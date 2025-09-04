//#include<iostream>
#include "Word_BST.h"
using namespace std;
#ifndef Letter_BST_H
#define Letter_BST_H
class Letter_BST_NODE {
public:
    char data;
    Letter_BST_NODE* left;
    Letter_BST_NODE* right;
    Word_BST* rootWord;
    Letter_BST_NODE(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
        rootWord = new Word_BST();

    }
};
class Letter_BST {
public:
    Letter_BST_NODE* root;

    Letter_BST();
    Letter_BST(char data);
    void insertNode(char key);
    void deleteNode(char key);
    Letter_BST_NODE* searchKey(char key);
//    void insertWord(string input);

private:
    Letter_BST_NODE* insertHelper(char input, Letter_BST_NODE* root);
    Letter_BST_NODE* deleteHelper(char input, Letter_BST_NODE* searchNode);
    Letter_BST_NODE* searchKeyHelper(char key, Letter_BST_NODE* searchNode);

};
#endif
