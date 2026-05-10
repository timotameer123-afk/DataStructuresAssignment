#include <iostream>
#include <string>
using namespace std;

struct Book
{
    int id;
    string title;
    string author;
    Book* left;
    Book* right;
};

class BST {
public:
    Book* root;
    BST(){
        root = nullptr;
    }

    Book* Insert(Book* node , int id , string title , string author){
        if(node == nullptr){    // tree is empty or we have reached a leaf node ( base case )
            Book* newNode = new Book();
            newNode->id = id;
            newNode->title = title;
            newNode->author = author;
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
        return node;
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

    Book* Search(Book* node , int id){
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
                // Node with two children get the max value in the left subtree 
                Book* max = Findmax(node->left);
                // Copy the max value to the current node
                node->id = max->id;
                node->title = max->title;
                node->author = max->author;
                // Delete the max value from the original position
                node->left = Delete(node->left , max->id);
            }
        }
        return node;   // return the pointer to the root of the subtree after deletion
    }
};

int main() {
    BST bst;
    bst.root = bst.Insert(bst.root, 5, "The Lord of the Rings", "J.R.R. Tolkien");
    bst.root = bst.Insert(bst.root, 2, "To Kill a Mockingbird", "Harper Lee");
    bst.root = bst.Insert(bst.root, 9, "The Hobbit", "J.R.R. Tolkien");
    bst.root = bst.Insert(bst.root, 1, "The Great Gatsby", "F. Scott Fitzgerald");
    bst.root = bst.Insert(bst.root, 6, "The Catcher in the Rye", "J.D. Salinger");
    bst.root = bst.Insert(bst.root, 4, "Pride and Prejudice", "Jane Austen");
    bst.root = bst.Insert(bst.root, 3, "1984", "George Orwell");
    cout << "================================" << endl;
    cout << "Books in the BST (Inorder Traversal):" << endl;
    bst.Inorder(bst.root);
    cout << "================================" << endl;
    cout << "Enter the ID of the book to search: ";
    int searchId ; 
    cin >> searchId ;
    if ( bst.Search(searchId)){
        cout << "Book with ID " << searchId << " found in the BST." << endl;
    }
    else{
        cout << "Book with ID " << searchId << " not found in the BST." << endl;
    }
    cout << "================================" << endl;
    cout << "Enter the ID of the book to delete: ";
    int deleteId ;
    cin >> deleteId ;
    bst.root = bst.Delete(bst.root , deleteId);
    cout << "Books in the BST (Inorder Traversal) after deletion:" << endl;
    bst.Inorder(bst.root);  

    return 0;
}

