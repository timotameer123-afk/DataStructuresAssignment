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

    // Sorted ID : 

    bst.root = bst.Insert(bst.root, 1, "The Alchemist", "Paulo Coelho");
    bst.root = bst.Insert(bst.root, 2, "To Kill a Mockingbird", "Harper Lee");
    bst.root = bst.Insert(bst.root, 3, "1984", "George Orwell");
    bst.root = bst.Insert(bst.root, 4, "Pride and Prejudice", "Jane Austen");
    bst.root = bst.Insert(bst.root, 5, "The Great Gatsby", "F. Scott Fitzgerald");
    bst.root = bst.Insert(bst.root, 6, "Moby Dick", "Herman Melville");
    bst.root = bst.Insert(bst.root, 7, "War and Peace", "Leo Tolstoy");
    bst.root = bst.Insert(bst.root, 8, "The Catcher in the Rye", "J.D. Salinger");
    bst.root = bst.Insert(bst.root, 9, "Animal Farm", "George Orwell");
    bst.root = bst.Insert(bst.root, 10, "Brave New World", "Aldous Huxley");
    bst.root = bst.Insert(bst.root, 11, "The Hobbit", "J.R.R. Tolkien");
    bst.root = bst.Insert(bst.root, 12, "Harry Potter and the Sorcerer's Stone", "J.K. Rowling");
    bst.root = bst.Insert(bst.root, 13, "The Lord of the Rings", "J.R.R. Tolkien");
    bst.root = bst.Insert(bst.root, 14, "Crime and Punishment", "Fyodor Dostoevsky");
    bst.root = bst.Insert(bst.root, 15, "The Kite Runner", "Khaled Hosseini");
    bst.root = bst.Insert(bst.root, 16, "Jane Eyre", "Charlotte Bronte");
    bst.root = bst.Insert(bst.root, 17, "Wuthering Heights", "Emily Bronte");
    bst.root = bst.Insert(bst.root, 18, "The Chronicles of Narnia", "C.S. Lewis");
    bst.root = bst.Insert(bst.root, 19, "The Da Vinci Code", "Dan Brown");
    bst.root = bst.Insert(bst.root, 20, "The Book Thief", "Markus Zusak");
    bst.root = bst.Insert(bst.root, 21, "Dune", "Frank Herbert");
    bst.root = bst.Insert(bst.root, 22, "The Little Prince", "Antoine de Saint-Exupery");
    bst.root = bst.Insert(bst.root, 23, "Gone with the Wind", "Margaret Mitchell");
    bst.root = bst.Insert(bst.root, 24, "Fahrenheit 451", "Ray Bradbury");
    bst.root = bst.Insert(bst.root, 25, "The Stranger", "Albert Camus");
//--------------------------------------------------------------------------------------------
    avl.root = avl.insert(avl.root, 1, "The Alchemist", "Paulo Coelho");
    avl.root = avl.insert(avl.root, 2, "To Kill a Mockingbird", "Harper Lee");
    avl.root = avl.insert(avl.root, 3, "1984", "George Orwell");
    avl.root = avl.insert(avl.root, 4, "Pride and Prejudice", "Jane Austen");
    avl.root = avl.insert(avl.root, 5, "The Great Gatsby", "F. Scott Fitzgerald");
    avl.root = avl.insert(avl.root, 6, "Moby Dick", "Herman Melville");
    avl.root = avl.insert(avl.root, 7, "War and Peace", "Leo Tolstoy");
    avl.root = avl.insert(avl.root, 8, "The Catcher in the Rye", "J.D. Salinger");
    avl.root = avl.insert(avl.root, 9, "Animal Farm", "George Orwell");
    avl.root = avl.insert(avl.root, 10, "Brave New World", "Aldous Huxley");
    avl.root = avl.insert(avl.root, 11, "The Hobbit", "J.R.R. Tolkien");
    avl.root = avl.insert(avl.root, 12, "Harry Potter and the Sorcerer's Stone", "J.K. Rowling");
    avl.root = avl.insert(avl.root, 13, "The Lord of the Rings", "J.R.R. Tolkien");
    avl.root = avl.insert(avl.root, 14, "Crime and Punishment", "Fyodor Dostoevsky");
    avl.root = avl.insert(avl.root, 15, "The Kite Runner", "Khaled Hosseini");
    avl.root = avl.insert(avl.root, 16, "Jane Eyre", "Charlotte Bronte");
    avl.root = avl.insert(avl.root, 17, "Wuthering Heights", "Emily Bronte");
    avl.root = avl.insert(avl.root, 18, "The Chronicles of Narnia", "C.S. Lewis");
    avl.root = avl.insert(avl.root, 19, "The Da Vinci Code", "Dan Brown");
    avl.root = avl.insert(avl.root, 20, "The Book Thief", "Markus Zusak");
    avl.root = avl.insert(avl.root, 21, "Dune", "Frank Herbert");
    avl.root = avl.insert(avl.root, 22, "The Little Prince", "Antoine de Saint-Exupery");
    avl.root = avl.insert(avl.root, 23, "Gone with the Wind", "Margaret Mitchell");
    avl.root = avl.insert(avl.root, 24, "Fahrenheit 451", "Ray Bradbury");
    avl.root = avl.insert(avl.root, 25, "The Stranger", "Albert Camus");

    // Unsorted ID :

    // bst.root = bst.Insert(bst.root, 13, "The Lord of the Rings", "J.R.R. Tolkien");
    // bst.root = bst.Insert(bst.root, 5, "The Great Gatsby", "F. Scott Fitzgerald");
    // bst.root = bst.Insert(bst.root, 21, "Dune", "Frank Herbert");
    // bst.root = bst.Insert(bst.root, 2, "To Kill a Mockingbird", "Harper Lee");
    // bst.root = bst.Insert(bst.root, 18, "The Chronicles of Narnia", "C.S. Lewis");
    // bst.root = bst.Insert(bst.root, 9, "Animal Farm", "George Orwell");
    // bst.root = bst.Insert(bst.root, 25, "The Stranger", "Albert Camus");
    // bst.root = bst.Insert(bst.root, 1, "The Alchemist", "Paulo Coelho");
    // bst.root = bst.Insert(bst.root, 16, "Jane Eyre", "Charlotte Bronte");
    // bst.root = bst.Insert(bst.root, 7, "War and Peace", "Leo Tolstoy");
    // bst.root = bst.Insert(bst.root, 23, "Gone with the Wind", "Margaret Mitchell");
    // bst.root = bst.Insert(bst.root, 10, "Brave New World", "Aldous Huxley");
    // bst.root = bst.Insert(bst.root, 4, "Pride and Prejudice", "Jane Austen");
    // bst.root = bst.Insert(bst.root, 19, "The Da Vinci Code", "Dan Brown");
    // bst.root = bst.Insert(bst.root, 12, "Harry Potter and the Sorcerer's Stone", "J.K. Rowling");
    // bst.root = bst.Insert(bst.root, 6, "Moby Dick", "Herman Melville");
    // bst.root = bst.Insert(bst.root, 24, "Fahrenheit 451", "Ray Bradbury");
    // bst.root = bst.Insert(bst.root, 3, "1984", "George Orwell");
    // bst.root = bst.Insert(bst.root, 20, "The Book Thief", "Markus Zusak");
    // bst.root = bst.Insert(bst.root, 8, "The Catcher in the Rye", "J.D. Salinger");
    // bst.root = bst.Insert(bst.root, 14, "Crime and Punishment", "Fyodor Dostoevsky");
    // bst.root = bst.Insert(bst.root, 17, "Wuthering Heights", "Emily Bronte");
    // bst.root = bst.Insert(bst.root, 15, "The Kite Runner", "Khaled Hosseini");
    // bst.root = bst.Insert(bst.root, 22, "The Little Prince", "Antoine de Saint-Exupery");
    // bst.root = bst.Insert(bst.root, 11, "The Hobbit", "J.R.R. Tolkien");

    // //--------------------------------------------------------------------------------------------

    // avl.root = avl.insert(avl.root, 13, "The Lord of the Rings", "J.R.R. Tolkien");
    // avl.root = avl.insert(avl.root, 5, "The Great Gatsby", "F. Scott Fitzgerald");
    // avl.root = avl.insert(avl.root, 21, "Dune", "Frank Herbert");
    // avl.root = avl.insert(avl.root, 2, "To Kill a Mockingbird", "Harper Lee");
    // avl.root = avl.insert(avl.root, 18, "The Chronicles of Narnia", "C.S. Lewis");
    // avl.root = avl.insert(avl.root, 9, "Animal Farm", "George Orwell");
    // avl.root = avl.insert(avl.root, 25, "The Stranger", "Albert Camus");
    // avl.root = avl.insert(avl.root, 1, "The Alchemist", "Paulo Coelho");
    // avl.root = avl.insert(avl.root, 16, "Jane Eyre", "Charlotte Bronte");
    // avl.root = avl.insert(avl.root, 7, "War and Peace", "Leo Tolstoy");
    // avl.root = avl.insert(avl.root, 23, "Gone with the Wind", "Margaret Mitchell");
    // avl.root = avl.insert(avl.root, 10, "Brave New World", "Aldous Huxley");
    // avl.root = avl.insert(avl.root, 4, "Pride and Prejudice", "Jane Austen");
    // avl.root = avl.insert(avl.root, 19, "The Da Vinci Code", "Dan Brown");
    // avl.root = avl.insert(avl.root, 12, "Harry Potter and the Sorcerer's Stone", "J.K. Rowling");
    // avl.root = avl.insert(avl.root, 6, "Moby Dick", "Herman Melville");
    // avl.root = avl.insert(avl.root, 24, "Fahrenheit 451", "Ray Bradbury");
    // avl.root = avl.insert(avl.root, 3, "1984", "George Orwell");
    // avl.root = avl.insert(avl.root, 20, "The Book Thief", "Markus Zusak");
    // avl.root = avl.insert(avl.root, 8, "The Catcher in the Rye", "J.D. Salinger");
    // avl.root = avl.insert(avl.root, 14, "Crime and Punishment", "Fyodor Dostoevsky");
    // avl.root = avl.insert(avl.root, 17, "Wuthering Heights", "Emily Bronte");
    // avl.root = avl.insert(avl.root, 15, "The Kite Runner", "Khaled Hosseini");
    // avl.root = avl.insert(avl.root, 22, "The Little Prince", "Antoine de Saint-Exupery");
    // avl.root = avl.insert(avl.root, 11, "The Hobbit", "J.R.R. Tolkien");

    cout << "--- Smart Library Management System ---\n";

    while (true)
    {
        cout << "1. Add New Book\n";
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
            if (bst.Search(id))
            {
                cout << "Book with ID " << id << " exists in BST.\n";
            }
            else 
            {
                cout << "Book with ID " << id << " does NOT exist in BST.\n";
            }

            if (avl.search(avl.root, id))
            {
                cout << "Book with ID " << id << " exists in AVL.\n";
            }
            else
            {
                cout << "Book with ID " << id << " does NOT exist in AVL.\n";
            }

            cout << "Search Steps Results:\n";
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
            int displayChoice;

            cout << "-------------------------\n";
            cout << "Choose Display Option:\n";
            cout << "1. Display BST\n";
            cout << "2. Display AVL\n";
            cout << "3. Display Both\n";
            cout << "Enter your choice: ";
            cin >> displayChoice;

            cout << endl;

            switch (displayChoice)
            {
            case 1:
            {
                cout << "-- BST Inorder --\n";
                bst.Inorder(bst.root);
                break;
            }

            case 2:
            {
                cout << "-- AVL Inorder --\n";
                avl.inorder(avl.root);
                break;
            }

            case 3:
            {
                cout << "-- BST Inorder --\n";
                bst.Inorder(bst.root);

                cout << "\n-- AVL Inorder --\n";
                avl.inorder(avl.root);
                break;
            }

            default:
            {
                cout << "Invalid choice!\n";
            }
            }

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
                cout << "[AVL] Closest Book -> ID: " << closestAVL->id
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
            cout << "Trees Heights Comparison:\n";
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