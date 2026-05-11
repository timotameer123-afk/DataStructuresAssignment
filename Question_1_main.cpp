#include <iostream>
<<<<<<< HEAD
=======
#include "Question_1_P2.h"
#include "Question_1_P1.h"
>>>>>>> 9b6d4431fac91de8425a1b433915e93c07814b74
#include <string>
#include <vector>
#include "Question_1_P1.h"
#include "Question_1_P2.h"

using namespace std;

void printDivider() {
    cout << "\n====================================================\n";
}

int main() {
    BST bst;
    AVLTree avl;
    int choice, id;
    string title, author;

    cout << "--- Smart Library Management System (BST vs AVL) ---\n";

    while (true) {
        printDivider();
        cout << "1. Add New Book (Insert)\n";
        cout << "2. Search for a Book (Compare Steps)\n";
        cout << "3. Delete a Book\n";
        cout << "4. Display All Books (Inorder)\n";
        cout << "5. Find Books in ID Range\n";
        cout << "6. Find Closest Book (Closest Match)\n";
        cout << "7. Compare Tree Heights (BST vs AVL)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: "; cin >> id;
                cin.ignore(); // لتنظيف الـ buffer قبل قراءة النصوص
                cout << "Enter Book Title: "; getline(cin, title);
                cout << "Enter Book Author: "; getline(cin, author);
                
                // الإدخال في الشجرتين معاً للمقارنة لاحقاً
                bst.root = bst.Insert(bst.root, id, title, author);
                avl.root = avl.insert(avl.root, id, title, author);
                cout << "\nBook added successfully to both trees!\n";
                break;

            case 2:
                cout << "Enter ID to search: "; cin >> id;
                
                // البحث في BST
                bst.search_steps = 0;
                bst.Search(bst.root, id);
                
                // البحث في AVL
                avl.search_steps = 0;
                avl.search(avl.root, id);

                cout << "\nSearch Results:\n";
                cout << "- BST Steps: " << bst.search_steps << endl;
                cout << "- AVL Steps: " << avl.search_steps << endl;
                break;

            case 3:
                cout << "Enter ID to delete: "; cin >> id;
                bst.root = bst.Delete(bst.root, id);
                avl.root = avl.deleteNode(avl.root, id);
                cout << "\nBook deleted from both trees (if existed).\n";
                break;

            case 4:
                cout << "\nBooks in Library (Sorted by ID):\n";
                avl.inorder(avl.root);
                break;

            case 5:
                int id1, id2;
                cout << "Enter Start ID: "; cin >> id1;
                cout << "Enter End ID: "; cin >> id2;
                cout << "\nBooks between " << id1 << " and " << id2 << ":\n";
                avl.Inorder_IDs_between(avl.root, id1, id2);
                break;

            case 6:
                {
                    int target, diff = 1e9;
                    Book* closest = nullptr;
                    cout << "Enter ID to find closest match: "; cin >> target;
                    avl.findClosest(avl.root, target, diff, closest);
                    if (closest)
                        cout << "\nClosest Book -> ID: " << closest->id << ", Title: " << closest->title << endl;
                }
                break;

            case 7:
                cout << "\nTrees Heights Comparison:\n";
                cout << "- BST Height: " << bst.getHeight(bst.root) << endl;
                cout << "- AVL Height: " << avl.getHeight(avl.root) << endl;
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

<<<<<<< HEAD
=======

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
>>>>>>> 9b6d4431fac91de8425a1b433915e93c07814b74
    return 0;
}