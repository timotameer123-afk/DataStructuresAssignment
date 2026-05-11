#ifndef QUESTION_1_P1_H
#define QUESTION_1_P1_H
#include <iostream>
#include <string>
using namespace std;

struct Book
{
    int id;
    string title;
    string author;
    int height;    // used for AVL tree
    Book* left;
    Book* right;
};

class BST {

public:
    int search_steps; 
    Book* root;
    BST(){
        root = nullptr;
        search_steps = 0;
    }

    Book* Insert(Book* node , int id , string title , string author){
        if(node == nullptr){    // tree is empty or we have reached a leaf node ( base case )
            Book* newNode = new Book();
            newNode->id = id;
            newNode->title = title;
            newNode->author = author;
            newNode->height = 1;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }

        else if ( id < node -> id){
            node->left = Insert(node->left , id , title , author);
        }
        else{
            node->right = Insert(node->right , id , title , author);
        }
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        return node;
    }

     int getHeight(Book* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

     int getBalance(Book* node) {
        if (node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }
    
    // LVR (Left, Visit, Right)
    void Inorder(Book* node){
        if(node == nullptr){
            return;
        }
        Inorder(node->left);
        cout << "ID: " << node->id << ", Title: " << node->title << ", Author: " << node->author << endl;
        Inorder(node->right);

    }

   void Inorder_IDs_between(Book* node, int id1, int id2) {
    if (node == nullptr) {
        return;
    }
    this->search_steps++; 
    if (node->id > id1) {
        Inorder_IDs_between(node->left, id1, id2);
    }
    if (node->id >= id1 && node->id <= id2) {
        cout << "ID: " << node->id << ", Title: " << node->title << ", Author: " << node->author << endl;
    }
    if (node->id < id2) {
        Inorder_IDs_between(node->right, id1, id2);
    }
}

    Book* Search(Book* node , int id){
        this->search_steps++;
        if(node == nullptr ){
            return nullptr;
        }
        else if ( id == node -> id){
            return node ;
        }
        else if ( id < node -> id){
            return Search(node->left , id);
        }
        else{
            return Search(node->right , id);
        }
    }

    bool Search (int id){
        Book* result = Search(root , id);
        if ( result == nullptr ){
            return false;
        }
        else{
            return true;
        }
    }


    // Helper function to find the maximum value in a subtree ( used for deletion )
    Book* Findmax(Book* node){
        if ( node == nullptr ){
            return nullptr;
        }
        else if ( node -> right == nullptr){
            return node;
        }
        else{
            return Findmax(node->right);
        }
    }

    Book* Delete(Book* node , int id){
        // if the tree is empty or we have reached a leaf node ( base case )
        if ( node == nullptr ){
            return nullptr;
        }
        else if ( id < node -> id){
            node->left = Delete(node->left , id);
        }
        else if ( id > node -> id){
            node->right = Delete(node->right , id);
        }
        else{
            // Node with only one child or no child
            if ( node -> left == nullptr && node -> right == nullptr){
                node = nullptr;
            }
            else if ( node->left == nullptr && node->right != nullptr){
                node = node->right;
                node -> right = nullptr;
            }
            else if ( node->left != nullptr && node->right == nullptr){
                node = node->left;
                node -> left = nullptr;
            }
            else{
                // Node with two children 
                Book* max = Findmax(node->left);
                // Copy the max value to the current node
                node->id = max->id;
                node->title = max->title;
                node->author = max->author;
                // Delete the max value from the original position
                node->left = Delete(node->left , max->id);
            }
        }
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        return node;   // return the pointer to the root of the subtree after deletion
    }
};

#endif