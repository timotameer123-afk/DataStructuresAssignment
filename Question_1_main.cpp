#include <iostream>
#include "Question_1_P2.h"
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

    return 0;
}