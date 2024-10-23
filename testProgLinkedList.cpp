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
    int num;                                           //Line 6

    cout << "Line 7: Enter numbers ending "
         << "with -999." << endl;                      //Line 7
    cin >> num;                                        //Line 8

    while (num != -999)                                //Line 9
    {                                                  //Line 10
        list1.insert(num);                             //Line 11
        cin >> num;                                    //Line 12
    }                                                  //Line 13

    cout << endl;                                      //Line 14

    cout << "Line 15: list1: ";                        //Line 15
    list1.print();                                     //Line 16
    cout << endl;                                      //Line 17

    list2 = list1;        //test the assignment operator Line 18

    cout << "Line 19: list2: ";                        //Line 19
    list2.print();                                     //Line 20
    cout << endl;                                      //Line 21

    cout << "Line 22: Enter the number to be "
         << "deleted: ";                               //Line 22
    cin >> num;                                        //Line 23
    cout << endl;                                      //Line 24

    list2.deleteNode(num);                             //Line 25

    cout << "Line 26: After deleting "
         << num << ", list2: " << endl;                //Line 26
    list2.print();                                     //Line 27
    cout << endl;                                      //Line 28

    orderedLinkedList<int> list3, list4;   //Line 29

    cout << "Enter numbers for list3 ending with "
         << "-999" << endl;                            //Line 30
    cin >> num;                                        //Line 31
    while (num != -999) {                              //Line 32
          list3.insert(num);                           //Line 33
          cin >> num;                                  //Line 34
    }

    cout << "Enter the numbers for list4 ending with "
         << "-999" << endl;                            //Line 35
    cin >> num;                                        //Line 36
    while (num != -999) {                              //Line 37
          list4.insert(num);                           //Line 38
          cin >> num;                                  //Line 39
    }

    mergedList.mergeLists(list3, list4);               //Line 40

    cout << "Merged list: ";                           //Line 41
    mergedList.print();                                //Line 42
    cout << endl;                                      //Line 43

    return 0;					                    //Line 44
}                                                      //Line 45