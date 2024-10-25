//**********************************************************
// Author: D.S. Malik
//
// This program tests the various operations on an ordered
// linked list.
//**********************************************************
#include <iostream>
#include "linkedList.h"                                //Line 1
#include "orderedLinkedList.h"                         //Line 2

using namespace std;                                   //Line 3

int main()                                             //Line 4
{
    orderedLinkedList<int> list1, list2, mergedList;   //Line 5
    // Declare three ordered linked lists: list1 and list2 will store numbers, 
    // and mergedList will hold the result of merging two other lists.
    
    int num;                                           //Line 6
    // Variable to store user input.

    cout << "Line 7: Enter numbers to add to list1, ending with -999." << endl; //Line 7
    // Prompt the user to input numbers into list1. Input will stop when the user enters -999.
    
    cin >> num;                                        //Line 8
    // Read the first number.

    while (num != -999)                                //Line 9
    {                                                  //Line 10
        list1.insert(num);                             //Line 11
        // Insert the number into list1 in its correct sorted position.
        
        cin >> num;                                    //Line 12
        // Keep reading numbers until the user inputs -999.
    }                                                  //Line 13

    cout << endl;                                      //Line 14

    cout << "Line 15: Here is list1: ";                //Line 15
    list1.print();                                     //Line 16
    // Print all the numbers currently stored in list1.
    
    cout << endl;                                      //Line 17

    list2 = list1;                                     //Line 18
    // Copy list1 into list2 to test the assignment operator. list2 should now be identical to list1.

    cout << "Line 19: Here is list2 (a copy of list1): "; //Line 19
    list2.print();                                     //Line 20
    // Print list2 to confirm the copy operation was successful.
    
    cout << endl;                                      //Line 21

    cout << "Line 22: Enter a number to delete from list2: "; //Line 22
    // Ask the user for a number to delete from list2.
    
    cin >> num;                                        //Line 23
    cout << endl;                                      //Line 24

    list2.deleteNode(num);                             //Line 25
    // Try to delete the given number from list2.

    cout << "Line 26: After deleting " << num << " from list2: " << endl; //Line 26
    list2.print();                                     //Line 27
    // Print list2 to show the result after deletion.
    
    cout << endl;                                      //Line 28

    orderedLinkedList<int> list3, list4;               //Line 29
    // Now, let's create two new ordered linked lists: list3 and list4.

    cout << "Enter numbers for list3, ending with -999: " << endl; //Line 30
    // Prompt the user to input numbers for list3. Input will stop with -999.
    
    cin >> num;                                        //Line 31
    while (num != -999) {                              //Line 32
        list3.insert(num);                             //Line 33
        // Insert each number into list3, in sorted order.
        
        cin >> num;                                    //Line 34
        // Keep reading until -999 is entered.
    }

    cout << "Enter numbers for list4, ending with -999: " << endl; //Line 35
    // Prompt the user to input numbers for list4 in the same way.
    
    cin >> num;                                        //Line 36
    while (num != -999) {                              //Line 37
        list4.insert(num);                             //Line 38
        // Insert each number into list4, in sorted order.
        
        cin >> num;                                    //Line 39
        // Keep reading until -999 is entered.
    }

    mergedList.mergeLists(list3, list4);               //Line 40
    // Merge the elements of list3 and list4 into mergedList. 
    // After merging, list3 and list4 will be empty, and all their elements will be in mergedList.

    cout << "Merged list: ";                           //Line 41
    mergedList.print();                                //Line 42
    // Print the contents of the merged list, which should contain all elements from both lists, sorted.
    
    cout << endl;                                      //Line 43

    return 0;                                          //Line 44
    // End of the program.
}
