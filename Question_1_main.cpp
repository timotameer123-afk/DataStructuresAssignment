#include <iostream>
#include "Question_1_P2.h"
#include "Question_1_P1.h"
#include <string>

using namespace std;

int main() {
    BST bst;
    AVLTree avl;

    int ids[] = {10, 20, 30, 40, 50, 60, 70};
    string t = "Sample Book";
    string a = "Sample Author";

    for (int i = 0; i < 7; i++) {
        bst.root = bst.Insert(bst.root, ids[i], t, a);
        avl.root = avl.insert(avl.root, ids[i], t, a);
    }


    // // AVL Tree :
    cout << "================================" << endl;
    cout << "AVL Tree (Inorder Traversal):" << endl;
    avl.inorder(avl.root);
    cout << "================================" << endl;

    cout << "Tree Heights Comparison:" << endl;
    cout << "BST Height: " << bst.getHeight(bst.root) << endl;
    cout << "AVL Height: " << avl.getHeight(avl.root) << endl;
    cout << "================================" << endl;

    cout << "Enter ID to find closest match: ";
    int target;
    cin >> target;
    int diff = 1e9;
    Book* closest = nullptr;
    avl.breadthFirstTraversal(avl.root, target, diff, closest);

    if (closest) {
        cout << "Closest Book ID: " << closest->id << " (" << closest->title << ")" << endl;
    }
    cout << "================================" << endl;

    cout << "Enter ID to delete from AVL: ";
    int deleteId;
    cin >> deleteId;
    avl.root = avl.deleteNode(avl.root, deleteId);

    cout << "AVL Content after deletion:" << endl;
    avl.inorder(avl.root);

    // BST Tree : 
    cout << "================================" << endl;
    cout << "================================" << endl;

    cout << "BST Tree (Inorder Traversal):" << endl;
    bst.Inorder(bst.root);
    cout << "================================" << endl;
    cout << "Enter ID to search in BST: ";
    int searchId;
    cin >> searchId;
    if (bst.Search(searchId)) {
        cout << "Book with ID " << searchId << " found in BST." << endl;
    } else {
        cout << "Book with ID " << searchId << " not found in BST." << endl;
    }
    cout<< "================================" << endl;
    cout<< "Enter first ID and Second ID to find the  IDs between them in BST: ";
    int id1, id2;
    cin >> id1 >> id2;
    cout << "Books with IDs between " << id1 << " and " << id2 << ":" << endl;
    cout << "================================" << endl;
    bst.Inorder_IDs_between(bst.root, id1, id2);
    cout << "================================" << endl;
    cout << "Enter ID to delete from BST: ";
    int deleteId;
    cin >> deleteId;
    bst.root = bst.Delete(bst.root, deleteId);
    cout << "BST Content after deletion:" << endl;
    bst.Inorder(bst.root);  
    return 0;
}