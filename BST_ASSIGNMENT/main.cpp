#include <iostream>
#include <vector>
#include "dictionary.h"
using namespace std;
class BST_NODE {
public:
	Word data;
	BST_NODE* left;
	BST_NODE* right;

	BST_NODE(Word data) {
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
};
class BST{
    public:
    BST_NODE* root;

    BST(){
        this->root = nullptr;
    }

    void insert (Word data){
//        cout << "Test " << data.word << "\n";
        this->root = insertHelper(data, root);
    }
    void insertSortedArray(vector<Word> &input){
        int s = 0;
        int e = input.size()-1;

        this->root = insertSortedArrayHelper(input, s, e);
    }

    void preOrder(){
        preOrderHelper(this->root);
    }

    void inOrder(){
        inOrderHelper(this->root);
    }
    Word searchInDictionary(string input){

        BST_NODE* result = searchInDictionaryHelper(input, this->root);
        if(result == nullptr){
            Word result = Word("Not Found", "Not Found");
            return result;
        }else{
            return result->data;
        }

    }
    void deleteNode(string input){

        this->root = deleteHelper(input, root);

    }

    private:
        BST_NODE* deleteHelper(string input, BST_NODE* searchNode) {
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
                    BST_NODE* tempLeft = searchNode->left;
                    searchNode->left = nullptr;
                    delete searchNode;
                    return tempLeft;
                }
                else if(searchNode->left == nullptr){
                    BST_NODE* tempRight = searchNode->right;
                    searchNode->right = nullptr;
                    delete searchNode;
                    return tempRight;
                }
                else{
                    BST_NODE* minNode = searchNode->right;
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
        BST_NODE* searchInDictionaryHelper(string input, BST_NODE* searchNode){
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
        BST_NODE* insertSortedArrayHelper(vector<Word> &input, int s, int e){
            if(s > e){
                return nullptr;
            }
            else if(s==e){
                return new BST_NODE(input[s]);
            }else{
                int mid = s + (e-s)/2;
                BST_NODE* node = new BST_NODE(input[mid]);
                node->left = insertSortedArrayHelper(input, s, mid - 1);
                node->right = insertSortedArrayHelper(input, mid+1, e);
                return node;
            }
        }
        BST_NODE* insertHelper(Word input, BST_NODE* root){
            //Base case
            if(root == nullptr){
                root = new BST_NODE(input);

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
    void preOrderHelper(BST_NODE * root){
        if(!root){
            return;
        }else{
//            cout << "Call Happened" << " ";
            cout << root->data.word << "\n";
            preOrderHelper(root->left);
            preOrderHelper(root->right);
        }
    }
        void inOrderHelper(BST_NODE * root){
        if(!root){
            return;
        }else{
//            cout << "Call Happened" << " ";
            inOrderHelper(root->left);
            cout << root->data.word << "\n";
            inOrderHelper(root->right);
        }
    }

};
int main()
{
    vector<Word> v = getDictionary();
    BST myDictionaryTree = BST();



//    for(auto i : v){
//        myDictionaryTree.insert(i);
//    }
//    myDictionaryTree.inOrder();
    myDictionaryTree.insertSortedArray(v);
//    myDictionaryTree.inOrder();

    Word result = myDictionaryTree.searchInDictionary("Apex");
    cout << "Search result: " << result.word << "\nDefinition: " << result.definition << "\n";

    myDictionaryTree.deleteNode("Apex");

    result = myDictionaryTree.searchInDictionary("Apex");
    cout << "Search result: " << result.word << "\nDefinition: " << result.definition << "\n";
    myDictionaryTree.inOrder();
    cout << "Hello world!" << endl;
    return 0;
}
