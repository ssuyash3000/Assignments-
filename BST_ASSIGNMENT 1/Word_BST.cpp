#include<iostream>
#include<queue>
#include<climits>
#include "Word_BST.h"

using namespace std;


Word_BST::Word_BST(){
    this->root = nullptr;
}

void Word_BST:: insertNode (Word data){
//        cout << "Test " << data.word << "\n";
    this->root = insertHelper(data, root);
}

void Word_BST::insertSortedArray(vector<Word> &input){
    int s = 0;
    int e = input.size()-1;

    this->root = insertSortedArrayHelper(input, s, e);
}

void Word_BST::preOrder(){
    preOrderHelper(this->root);
}

void Word_BST::inOrder(){
    inOrderHelper(this->root);
}

Word Word_BST::searchInDictionary(string input){

    Word_BST_NODE* result = searchInDictionaryHelper(input, this->root);
    if(result == nullptr){
        Word result = Word("Not Found", "Not Found");
        return result;
    }else{
        return result->data;
    }

}

void Word_BST::deleteNode(string input){

    this->root = deleteHelper(input, root);

}
Word_BST_NODE* Word_BST::insertHelper(Word input, Word_BST_NODE* root){
    //Base case
    if(root == nullptr){
        root = new Word_BST_NODE(input);

    }else{
        //induction hypothesis
        if(root->data.word > input.word){
            root->left = insertHelper(input, root->left);
        }else if (root->data.word < input.word){
            root->right = insertHelper(input, root->right);
        }
        else{
            cout << root->data.word  << " Word is already there in the BST\n";
        }

    }
    //return value
     return root;
}


Word_BST_NODE* Word_BST::insertSortedArrayHelper(vector<Word> &input, int s, int e){
    if(s > e){
        return nullptr;
    }
    else if(s==e){
        return new Word_BST_NODE(input[s]);
    }else{
        while (s < e && input[s].word == input[s+1].word) {
            cout << input[s].word << " is duplicate and will be skipped.\n";
            s++;
        }

        int mid = s + (e-s)/2;
        Word_BST_NODE* node = new Word_BST_NODE(input[mid]);
        node->left = insertSortedArrayHelper(input, s, mid - 1);
        node->right = insertSortedArrayHelper(input, mid+1, e);
        return node;
    }
}


Word_BST_NODE* Word_BST::deleteHelper(string input, Word_BST_NODE* searchNode) {
    if(searchNode == nullptr){
        return nullptr;
    }
    if(input > searchNode->data.word){
        searchNode->right = deleteHelper(input, searchNode->right);
    }
    else if(input < searchNode->data.word){
        searchNode->left = deleteHelper(input, searchNode->left);
    }
    else{
        cout << "/////////////////////////Testing///////////////////////////////\n";
        if(searchNode->left == nullptr and searchNode->right == nullptr){
            delete searchNode;
            return nullptr;
        }
        else if(searchNode->right == nullptr){
            Word_BST_NODE* tempLeft = searchNode->left;
            searchNode->left = nullptr;
            delete searchNode;
            return tempLeft;
        }
        else if(searchNode->left == nullptr){
            Word_BST_NODE* tempRight = searchNode->right;
            searchNode->right = nullptr;
            delete searchNode;
            return tempRight;
        }
        else{
            Word_BST_NODE* minNode = searchNode->right;
            while(minNode->left != nullptr){
                minNode = minNode->left;
            }
            Word minValue = minNode->data;
            searchNode->data = minValue;
            searchNode->right = deleteHelper(minValue.word, minNode);
            return searchNode;
        }
    }
    return searchNode;
}


Word_BST_NODE* Word_BST::searchInDictionaryHelper(string input, Word_BST_NODE* searchNode){
    if(searchNode == nullptr){
        return nullptr;
    }
    if(searchNode->data.word == input){
        return searchNode;
    }else{
        if(searchNode->data.word > input){
            return searchInDictionaryHelper(input, searchNode->left);
        }else{
            return searchInDictionaryHelper(input, searchNode->right);
        }

    }
}



void Word_BST::preOrderHelper(Word_BST_NODE * root){
    if(!root){
        return;
    }else{
//            cout << "Call Happened" << " ";
        cout << root->data.word << "\n";
        preOrderHelper(root->left);
        preOrderHelper(root->right);
    }
}
void Word_BST::inOrderHelper(Word_BST_NODE * root){
    if(!root){
        return;
    }else{
//            cout << "Call Happened" << " ";
        inOrderHelper(root->left);
        cout << root->data.word << "\n";
        inOrderHelper(root->right);
    }
}
