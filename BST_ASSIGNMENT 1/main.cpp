#include <iostream>
#include <vector>
#include "Word_BST.h"
#include "letter_BST.h"
using namespace std;



class TreeDictionary{
public:
    Letter_BST* root;

    TreeDictionary(){
        root = new Letter_BST();
    }

    void insertWord(Word input){
        Letter_BST_NODE* letterNode = root->searchKey(input.word[0]);
        if(letterNode == nullptr or letterNode->rootWord == nullptr){
            root->insertNode(input.word[0]);
            letterNode = root->searchKey(input.word[0]);
            letterNode->rootWord->insertNode( (input));
        }else{
            letterNode->rootWord->insertNode( (input));
        }

    }
    void searchWord(string input){
        Letter_BST_NODE* letterNode = root->searchKey(input[0]);
        if(letterNode == nullptr or letterNode->rootWord == nullptr){
         cout << "\nWord do not exists\n";
        }
        else{
            Word result = letterNode->rootWord->searchInDictionary(input);
            cout << "\nResult word: " << result.word << "\nMeaning: " << result.definition << "\n";
        }
    }
    void deleteWord(string input){
        Letter_BST_NODE* letterNode = root->searchKey(input[0]);
        if(letterNode == nullptr or letterNode->rootWord == nullptr){
         cout << "\nWord do not exists\n";
        }
        else{
            letterNode->rootWord->deleteNode(input);
        }
    }
};


int main()
{
    vector<Word> v = getDictionaryData();
    TreeDictionary myDictionaryTree = TreeDictionary();
    for(auto i : v){
        myDictionaryTree.insertWord(i);

    }

    myDictionaryTree.searchWord("Wane");
    myDictionaryTree.deleteWord("Wane");
    myDictionaryTree.searchWord("Wane");

    return 0;
}
