#ifndef Word_BST_H
#define Word_BST_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Word {
public:
	string word;
	string definition;
	Word() {
		word = "";
		definition = "";
	}

	Word(string w, string d) {
		word = w;
		definition = d;
	}
};


class Word_BST_NODE {
public:
	Word data;
	Word_BST_NODE* left;
	Word_BST_NODE* right;

	Word_BST_NODE(Word data) {
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
};
class Word_BST {
public:
	Word_BST_NODE* root;

	Word_BST();

	void insertNode (Word data);
	void insertSortedArray(vector<Word> &input);

	void preOrder();

	void inOrder();

	Word searchInDictionary(string input);

	void deleteNode(string input);



private:
	Word_BST_NODE* deleteHelper(string input, Word_BST_NODE* searchNode) ;
	Word_BST_NODE* insertSortedArrayHelper(vector<Word> &input, int s, int e);
	Word_BST_NODE* insertHelper(Word input, Word_BST_NODE* root);
	void preOrderHelper(Word_BST_NODE * root);
	void inOrderHelper(Word_BST_NODE * root);
    Word_BST_NODE* searchInDictionaryHelper(string input, Word_BST_NODE* searchNode);
};

vector<Word> getDictionaryData();

#endif
