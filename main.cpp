#include "BST.cpp"
#include <iostream>
using namespace std;

/*
    BST<double> bst1;
    bst1.insert(5, 5);
    bst1.insert(4, 4);
    bst1.insert(3, 3);
    bst1.insert(6, 6);
    bst1.insert(7, 7);
    bst1.insert(8, 8);
    
   

    bst1.print();
    cout << endl;

    cout << bst1.find_max();
    cout << endl;

    bst1.remove(7);

    bst1.print();
    cout << endl;

    bst1.travel_in_order();
    cout << endl;
    bst1.travel_post_order();
    cout << endl;
    bst1.travel_pre_order();
    cout << endl;

*/

int main(){
    
    BST<double> bst;

    while(true)
    {
        char choice;
        int key;
        cout << "Action: d/f/i/m/M/p/q/r/s "
             << "(deep-cp/find/insert/min/Max/print/quit/remove/shallow-cp): ";
        cin >> choice;

        switch (choice)
        {
            case 'd': // Deep copy
            {
                /*
                BST<double>* bst2 = new BST<double>(bst);
                bst2->print();
                delete bst2;
                */
            }
                break;
            case 'f': // Find a value
                cout << "Value to find: ";
                cin >> key;
                cout << boolalpha << bst.contains(key);
                break;
            case 'i': // Insert a value
                cout << "Value to insert: ";
                cin >> key;
                bst.insert(key,key);
                break;
            case 'm': // Find the minimum value
                if (bst.is_empty()) 
                        cerr << "Can't search an empty tree!" << endl;
                    else
                        cout << bst.find_min() << endl; 
                    break;
            case 'M': // Find the maximum value
                if (bst.is_empty()) 
                    cerr << "Can't search an empty tree!" << endl;
                else
                    cout << bst.find_max() << endl; 
                break;
            case 'p': // Print the whole tree
                bst.print(); 
                break;
            case 'r':
                cout << "Value to remove: "; cin >> key;
                bst.remove(key); 
                break;
            case 's': // Shallow copy
            {
                break;
            }
            case 'q': // Quit
                return 0; 
            default:
                cout << endl;
                break;
        }      
    }
    return 0;
}