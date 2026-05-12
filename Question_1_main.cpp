#include <iostream>
#include <string>
#include <vector>
#include "Question_1_P1.h"
#include "Question_1_P2.h"

using namespace std;

int main()
{
    BST bst;
    AVLTree avl;
    int choice, id;
    string title, author;

    cout << "--- Smart Library Management System ---\n";

    while (true)
    {
        cout << "\n1. Add New Book\n";
        cout << "2. Search for a Book\n";
        cout << "3. Delete a Book\n";
        cout << "4. Display All Books\n";
        cout << "5. Find Books in ID Range\n";
        cout << "6. Find Closest Book\n";
        cout << "7. Compare Tree Heights\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0)
            break;

        switch (choice)
        {

        case 1:
        {
            cout << "Enter Book ID: ";
            cin >> id;
            cout << "Enter Book Title: ";
            cin >> title;
            cout << "Enter Book Author: ";
            cin >> author;

            bst.root = bst.Insert(bst.root, id, title, author);
            avl.root = avl.insert(avl.root, id, title, author);

            cout << "\nBook added successfully to both trees!\n";
            cout << "===========================================\n";
            break;
        }    
        case 2:
        {
            cout << "Enter ID to search: ";
            cin >> id;

            bst.search_steps = 0;
            bst.Search(bst.root, id);

            avl.search_steps = 0;
            avl.search(avl.root, id);

            cout << "\nSearch Steps Results:\n";
            cout << "- BST Steps: " << bst.search_steps << endl;
            cout << "- AVL Steps: " << avl.search_steps << endl;
            cout << "===========================================\n";
            break;
        }    
        case 3:
        {
            cout << "Enter ID to delete: ";
            cin >> id;

            bst.root = bst.Delete(bst.root, id);
            avl.root = avl.deleteNode(avl.root, id);

            cout << "\nBook deleted from both trees (if existed).\n";
            cout << "===========================================\n";
            break;
        }    
        case 4:
        {
            cout << "\nTraverse Books in Library:\n";
            cout << "-- BST Inorder --\n";
            bst.Inorder(bst.root);
            cout << "-- AVL Inorder --\n";
            avl.inorder(avl.root);
            cout << "===========================================\n";
            break;
        }    

        case 5:
        {
            int id1, id2;
            cout << "Enter Start ID: ";
            cin >> id1;
            cout << "Enter End ID: ";
            cin >> id2;

            cout << "\nBooks between " << id1 << " and " << id2 << ":\n";
            cout << "-- BST --\n";
            bst.Inorder_IDs_between(bst.root, id1, id2);
            cout << "-- AVL --\n";
            avl.Inorder_IDs_between(avl.root, id1, id2);
            cout << "===========================================\n";
            break;
        }

        case 6:
        {
            int target;
            cout << "Enter ID to find closest match: ";
            cin >> target;

            int diffAVL = 1e9;
            Book *closestAVL = nullptr;
            avl.findClosest(avl.root, target, diffAVL, closestAVL);
            if (closestAVL)
                cout << "\n[AVL] Closest Book -> ID: " << closestAVL->id
                     << ", Title: " << closestAVL->title << endl;

            int diffBST = 1e9;
            Book *closestBST = nullptr;
            bst.findClosest(bst.root, target, diffBST, closestBST);
            if (closestBST)
                cout << "[BST] Closest Book -> ID: " << closestBST->id
                     << ", Title: " << closestBST->title << endl;

            cout << "===========================================\n";
            break;
        }

        case 7:
        {
            cout << "\nTrees Heights Comparison:\n";
            cout << "- BST Height: " << bst.getHeight(bst.root) << endl;
            cout << "- AVL Height: " << avl.getHeight(avl.root) << endl;
            cout << "===========================================\n";
            break;
        }    
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}