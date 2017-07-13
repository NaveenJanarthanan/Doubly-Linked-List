// Implementation file for doublyLinkedList, a pointer-based by-position list of type
// specified in header.

#include "doublyLinkedList.h"     // header file
#include <cstddef>		// for NULL
#include <cassert>     // for assert()
#include <iostream>

using namespace std; 
doublyLinkedList::doublyLinkedList()	// Default Constructor
: size(0), head(NULL), tail(NULL)
{
}


doublyLinkedList::~doublyLinkedList()	// Destructor
{
	bool success;

	while (!isEmpty())
	{
	success = deleteElement(1);  // Repeatedly delete item 1
	}
}


bool doublyLinkedList::isEmpty() const
{
	return (size == 0);
}


int doublyLinkedList::getLength() const
{
	return size;
}


// Copy Constructor
doublyLinkedList::doublyLinkedList(const doublyLinkedList& original)
: size(original.size)
{
	if (original.head == NULL) {
		head = NULL;  // original list is empty
		tail = NULL;
	}
	else
	{
		// copy first node
		head = new listNode;
		assert(head != NULL);  // check allocation

		head->item = original.head->item;

		// copy rest of list
		listNode *newPtr = head;  // new list pointer


		// newPtr points to last node in new list 
		// origPtr points to nodes in original list
		for (listNode *origPtr = original.head->next; origPtr != NULL; origPtr = origPtr->next)
		{
			newPtr->next = new listNode;
			assert(newPtr->next != NULL);

			newPtr = newPtr->next;

			newPtr->item = origPtr->item;
		}

		newPtr->next = NULL;
	}

}


// Locates a specified node in a linked list
// Parameters: the number of the desired node (starting at 1, an int)
// Returns: Returns a pointer to the desired node, or NULL if position out of range.
doublyLinkedList::listNode *doublyLinkedList::ptrTo(int position) const
{
	if ((position < 1) || (position > getLength()))
		return NULL;

	else  // count from the beginning of the list
	{
		listNode *cur = head;

		for (int skip = 1; skip < position; ++skip)
			cur = cur->next;

		return cur;
	}
}


bool doublyLinkedList::retrieveElement(int position, listItemType& dataItem) const
{
	bool success = ((position >= 1) && (position <= getLength()));

	if (success)
	{
		// get pointer to node, then data in node
		listNode *cur = ptrTo(position);

		dataItem = cur->item;
	}

	return success;
}



// Iterative doublyLinkedList Insert
void doublyLinkedList::insertElement(listItemType newItem)
{

	listNode *prev = NULL;
	listNode *cur = head;
		

	while ((cur != NULL) && (newItem > cur->item))
	{
		prev = cur;
		cur = cur->next;

	}

	listNode *newPtr = new listNode;
	newPtr->item = newItem;

	newPtr->next = cur;

	if (prev == NULL)
	{
		if (size != 0)
		//links back to new head
		head->prev = newPtr;
		head = newPtr;
		if (size == 0)
			//makes the tail the new element 
			tail = newPtr;
	     	head->prev = NULL; 
	}
		
	else{
		prev->next = newPtr;
		//assigned to last element
		newPtr->last = prev;
		//links back to new element
		if (newPtr->next != NULL)
			cur->last = newPtr;
		else
			tail = newPtr;
	}

	size++;
}


void doublyLinkedList::locateElement(listItemType key, int& position)
{
	listNode *cur = head;
	
	position = 1;

	while (cur != NULL && cur->item != key)
	{
		cur = cur->next;
		position++;
	}

	if (cur == NULL)
		position = -1;
}


bool doublyLinkedList::deleteElement(int position)
{

	listNode *cur;

	bool success = ((position >= 1) && (position <= getLength()));

	if (success)
	{
		--size;

		if (position == 1)
		{
			// delete the first node from the list
			cur = head;  // save pointer to node
			head = head->next;

			if (head != NULL)
			{
				head->last = NULL;
	}
		}

		else
		{
			listNode *prev = ptrTo(position - 1);
			listNode *next = ptrTo(position + 1);
			// delete the node after the node 
			//    to which Prev points

			cur = prev->next;  // save pointer to node
			prev->next = cur->next;
			if (next != NULL)
				//goes back to previous node 
				next->last = prev;
			else
				tail = prev; 
		}

		// return node to system
		cur->next = NULL;
		cur->prev = NULL;
		delete cur;
		cur = NULL;
	}

	return success;
}

bool doublyLinkedList::operator== (const doublyLinkedList& right)
{
	//shortcut in case comparing same two doublyLinkedLists
	if (&right == this)
		return true;

	//check sizes are the same
	if (getLength() != right.getLength())
		return false;

	//temporary variables for comparison
	listItemType mine;
	listItemType theirs;

	//compare each element
	for (int i = 1; i <= getLength(); i++)
	{
		//use public methods to get each element
		retrieveElement(i, mine);
		right.retrieveElement(i, theirs);

		//return false after any mismatch
		if (mine != theirs)
			return false;
	}

	//if code gets here, all elements must be the same
	return true;
}

bool doublyLinkedList::operator!= (const doublyLinkedList& right)
{
	return !(*this == right);

}

void doublyLinkedList::reverse()
{
	if (size == 0 || size == 1)
		return; 
	else
	{
		listNode *back = tail;
		listNode *front = head; 

		while (back->item > front->item) {
			int t = back->item;
			back->item = front->item;
			front->item = t; 

			front = front->next; 
			back = back->prev; 

		}
	}
}

void doublyLinkedList::printFront() {

	if (size == 0) 
	
	
		cout << "Empty List" << endl;
	else {
		//goes through the list 
		listNode *i = head;
		while (i != NULL) {
			//prints the elements 
			cout << i->item << " ";
			i = i->next;

		
	}
	cout << endl;
	}
}

void doublyLinkedList::printBack() {
	{
		if (size == 0)
			cout << "List is empty" << endl;
			
		else {
			listNode * i = tail;
			while (i != NULL) {
				cout << i->item << " ";
				i = i->last;
			
			}
			cout << endl;
		}
	}

}