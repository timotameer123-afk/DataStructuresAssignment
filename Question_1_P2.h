#ifndef QUESTION_1_P2_H
#define QUESTION_1_P2_H
#include <iostream>
#include "Question_1_P1.h"
#include <string>
#include <queue>
using namespace std;


class AVLTree : public BST{
    public:
    AVLTree() : BST() {}


    // Right rotation and left rotation
    Book* RightRotate(Book* old) {
        Book* newR = old->left;
        Book* Rchild = newR->right;

        // Perform rotation
        newR->right = old;
        old->left = Rchild;

        // Update heights
        old->height = 1 + max(getHeight(old->left), getHeight(old->right));
        newR->height = 1 + max(getHeight(newR->left), getHeight(newR->right));

        // Return new root
        return newR;
    }
    Book* LeftRotate(Book* old) {
        Book* newR = old->right;
        Book* Lchild = newR->left;

        // Perform rotation
        newR->left = old;
        old->right = Lchild;

        // Update heights
        old->height = 1 + max(getHeight(old->left), getHeight(old->right));
        newR->height = 1 + max(getHeight(newR->left), getHeight(newR->right));

        // Return new root
        return newR;
    }


    //Insertion function
    Book* insert(Book* node, int id, string title, string author) {
        if (node == nullptr) {
            Book* newNode = new Book();
            newNode->id = id;
            newNode->title = title;
            newNode->author = author;
            newNode->height = 1;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }
        if (id < node->id) {
            node->left = insert(node->left, id, title, author);
        } else if (id > node->id) {
            node->right = insert(node->right, id, title, author);
        } else {
            return node;
        }

        // Update height of the ancestor node and balance
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && id < node->left->id)
            return RightRotate(node);

        // Right Right Case
        if (balance < -1 && id > node->right->id)
            return LeftRotate(node);

        // Left Right Case
        if (balance > 1 && id > node->left->id) {
            node->left = LeftRotate(node->left);
            return RightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && id < node->right->id) {
            node->right = RightRotate(node->right);
            return LeftRotate(node);
        }

        return node; // Return the unchanged node pointer
    }

    
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

    // Search function
    bool search(Book* node, int id) {
        this->search_steps++; 

        if (node == nullptr) {
            return false;
        }
        else if (id == node->id) {
            return true;
        }
        else if (id < node->id) {
            return search(node->left, id);
        }
        else {
            return search(node->right, id);
        }
    }

    //Inorder Traversal
    void inorder(Book* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << "ID: " << node->id << endl << ", Title: " << node->title << endl<< ", Author: " << node->author << endl;
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<< endl;
        inorder(node->right);
    }

    // BFT Traversing + finding closest value
    Book* breadthFirstTraversal(Book* node, int id, int& closestDiff, Book*& closest) {
        queue <Book*> q;
        Book* current = root;
        if (current != nullptr) {
            q.push(current);
            while(!q.empty()){
                current = q.front();
                q.pop();
                this->search_steps++;
                int diff = abs(current->id - id);
                if (diff < closestDiff) {
                    closestDiff = diff;
                    closest = current;
                }
                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }

        }
        return current;
    }


    // Another function to find closest value using Inorder Traversal
    Book* findClosest(Book* node, int target, int& closestDiff, Book*& closest) {
    if (node == nullptr) return closest;

    this->search_steps++;

    int currentDiff = abs(node->id - target);
    if (currentDiff < closestDiff) {
        closestDiff = currentDiff;
        closest = node;
    }
    if (target < node->id)
        return findClosest(node->left, target, closestDiff, closest);
    else if (target > node->id)
        return findClosest(node->right, target, closestDiff, closest);
    else
        return node;
}

    // Function to search for an id between limits in AVL tree
    void Inorder_IDs_between(Book* node, int id1, int id2) {
    if (node == nullptr) {
        return;
    }

    this->search_steps++; 

    if (node->id > id1) {
        Inorder_IDs_between(node->left, id1, id2);
    }

    if (node->id >= id1 && node->id <= id2) {
        cout << "ID: " << node->id << ", Title: " << node->title 
             << ", Author: " << node->author << endl;
    }

    if (node->id < id2) {
        Inorder_IDs_between(node->right, id1, id2);
    }}


    //Deletion function
    Book* deleteNode(Book* node, int id) {
        if (node == nullptr) return nullptr;

        if (id < node->id) {
            node->left = deleteNode(node->left, id);
        } else if (id > node->id) {
            node->right = deleteNode(node->right, id);
        } else {
            if (node->left == nullptr || node->right == nullptr) {
                Book* temp = node->left ? node->left : node->right;
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                Book* temp = node->right;
                while (temp->left != nullptr) temp = temp->left;

                node->id = temp->id;
                node->title = temp->title;
                node->author = temp->author;
                node->right = deleteNode(node->right, temp->id);
            }}
        

        if (node == nullptr) return nullptr;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0)
            return RightRotate(node);

        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = LeftRotate(node->left);
            return RightRotate(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0)
            return LeftRotate(node);

        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = RightRotate(node->right);
            return LeftRotate(node);
        }

        return node;
    }

};

#endif