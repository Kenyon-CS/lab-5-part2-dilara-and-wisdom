#ifndef H_orderedListType
#define H_orderedListType

//***********************************************************
// Author: D.S. Malik
//
// This class defines the basic operations for an ordered doubly 
// linked list, like searching, inserting, deleting, and merging.
//***********************************************************

#include "linkedList.h"

using namespace std;

template <class Type>
// Original version used a template-based class definition, but
// we had to replace it with an `int` type explicitly for our compiler.
class orderedLinkedList: public linkedListType<int>
{
public:
    bool search(const Type& searchItem) const;
      // This function checks if `searchItem` is present in the list.
      // If it finds the item, it returns `true`. Otherwise, it returns `false`.

    void insert(const Type& newItem);
      // This function inserts `newItem` into the list, making sure 
      // it goes in the correct, sorted order. The list is updated,
      // and the count of elements is increased by 1.

    void insertFirst(const Type& newItem);
      // This function inserts `newItem` at the very beginning of the list.
      // Count is also incremented by 1.

    void insertLast(const Type& newItem);
      // This function inserts `newItem` at the end of the list.
      // It also increments the count by 1.

    void deleteNode(const Type& deleteItem);
      // This function deletes the node containing `deleteItem` from the list.
      // If the item is found, it removes the node, updates the list, 
      // and decreases the count by 1. If the item isn’t found, 
      // it prints an appropriate message.

    void mergeLists(orderedLinkedList<Type> &list1, orderedLinkedList<Type> &list2);
      // This function merges two ordered linked lists (list1 and list2) 
      // into the current list. After merging, list1 and list2 are destroyed.
};

// Function to search for an item in the list
template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;               // Variable to track if we found the item
    nodeType<Type> *current;          // Pointer to traverse the list

    current = first;  // Start at the beginning of the list

    // Traverse the list while the current node isn't null and the item isn't found
    while (current != nullptr && !found) 
        if (current->info >= searchItem) // Stop searching if we've found an equal or larger item
            found = true;
        else
            current = current->link;    // Move to the next node

    // Check if the item is exactly what we were looking for
    if (found)
       found = (current->info == searchItem);

    return found;  // Return whether the item was found or not
}

// Function to insert a new item into the list in sorted order
template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type> *current;          // Pointer to traverse the list
    nodeType<Type> *trailCurrent;     // Pointer to the node right before `current`
    nodeType<Type> *newNode;          // Pointer to create a new node
    bool found;

    newNode = new nodeType<Type>;     // Create a new node
    newNode->info = newItem;          // Store the new item in the node
    newNode->link = nullptr;          // Set its link to null (it’s a new node)

    // Case 1: Inserting into an empty list
    if (first == nullptr)  
    {
        first = newNode;              // New node becomes the first
        last = newNode;               // And the last, since it's the only one
        count++;
    }
    else  // Case 2: Inserting into a non-empty list
    {
        current = first;
        found = false;

        // Traverse the list and find the correct spot for the new item
        while (current != nullptr && !found)
           if (current->info >= newItem)   // Stop if we find where the new item should go
               found = true;
           else
           {
               trailCurrent = current;    // Move trailCurrent to the current node
               current = current->link;   // Move current to the next node
           }

        // Case 2: Inserting at the front (the new item is the smallest)
        if (current == first)      
        {
            newNode->link = first;    // Link the new node to the old first node
            first = newNode;          // Now the new node is the first one
            count++;
        }
        else  // Case 3: Inserting somewhere in the middle or at the end
        {
            trailCurrent->link = newNode;   // Link the previous node to the new node
            newNode->link = current;        // Link the new node to the next one

            if (current == nullptr)        // If we're at the end of the list,
                last = newNode;            // The new node is now the last node

            count++;
        }
    }
}

// Insert at the front of the list (simply calls the insert function)
template<class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    insert(newItem);  // Reuse the insert function
}

// Insert at the end of the list (simply calls the insert function)
template<class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
    insert(newItem);  // Reuse the insert function
}

// Function to delete a node from the list
template<class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;          // Pointer to traverse the list
    nodeType<Type> *trailCurrent;     // Pointer to the node before `current`
    bool found;

    // Case 1: Empty list (nothing to delete)
    if (first == nullptr)
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        current = first;
        found = false;

        // Traverse the list to find the item to delete
        while (current != nullptr && !found)  
            if (current->info >= deleteItem)   // Stop when we find the item or pass it
                found = true;
            else
            {
                trailCurrent = current;       // Move trailCurrent to the current node
                current = current->link;      // Move current to the next node
            }

        // Case 4: Item not found in the list
        if (current == nullptr)
            cout << "The item to be deleted is not in the list." << endl;
        else if (current->info == deleteItem)   // Item found
        {
            // Case 2: Deleting the first node
            if (first == current)       
            {
                first = first->link;  // Move the first pointer to the next node

                if (first == nullptr) // If the list is now empty,
                    last = nullptr;   // Reset the last pointer

                delete current;       // Delete the node
            }
            else  // Case 3: Deleting a node in the middle or end
            {
                trailCurrent->link = current->link;  // Link the previous node to the next one

                if (current == last)   // If it was the last node,
                    last = trailCurrent;  // Update the last pointer

                delete current;       // Delete the node
            }
            count--;
        }
        else  // Case 4: Item not found
            cout << "The item to be deleted is not in the list." << endl;
    }
}

// Function to merge two ordered lists into the current list
template <class Type>
void orderedLinkedList<Type>::mergeLists(orderedLinkedList<Type>& list1, orderedLinkedList<Type>& list2) 
{
    nodeType<Type> *current1 = list1.first;  // Pointer to traverse list1
    nodeType<Type> *current2 = list2.first;  // Pointer to traverse list2

    // Clear the current list before merging
    this->destroyList();

    // Merge both lists while neither one is empty
    while (current1 != nullptr && current2 != nullptr) {
        if (current1->info < current2->info) {  // Insert smaller item first
            this->insert(current1->info);
            current1 = current1->link;          // Move to the next node in list1
        } else {
            this->insert(current2->info);
            current2 = current2->link;          // Move to the next node in list2
        }
    }

    // If list1 has remaining nodes, insert them
    while (current1 != nullptr) {
        this->insert(current1->info);
        current1 = current1->link;
    }

    // If list2 has remaining nodes, insert them
    while (current2 != nullptr) {
        this->insert(current2->info);
        current2 = current2->link;
    }

    // After merging, destroy list1 and list2 since they're now empty
    list1.destroyList();
    list2.destroyList();
}

#endif
