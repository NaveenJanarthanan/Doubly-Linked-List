//Test client for CSC 2431 
//DO NOT MODIFY

#include <iostream>
using namespace std;

#include "doublyLinkedList.h"

//prototypes
void print(doublyLinkedList list);

int main()
{
	doublyLinkedList first;

	//create a list with 6 elements for testing
	first.insertElement(20);
	first.insertElement(10);
	first.insertElement(30);
	first.insertElement(40);
	first.insertElement(25);
	first.insertElement(5);

	int pos;

	first.locateElement(30, pos);

	first.deleteElement(pos);

	cout << "first, printed with client print:  " << endl;
	print(first);

	//create a copy of 6-element list
	doublyLinkedList second(first);

	//test all 3 cases for delete
	second.deleteElement(1);
	second.deleteElement(4);
	second.deleteElement(2);

	cout << "\nsecond, printed with client print:  " << endl;
	print(second);

	//test copy constructor
	doublyLinkedList third(first);

	//test == and !=
	cout << boolalpha;
	cout << "\ntesting == " << endl;
	cout << (first == first) << endl;
	cout << (first == second) << endl;
	cout << (first == third) << endl;

	cout << "\ntesting != " << endl;
	cout << (first != first) << endl;
	cout << (first != second) << endl;
	cout << (first != third) << endl;

	//test print functions
	cout << "\ntesting printFront on first: " << endl;
	first.printFront();

	cout << "\ntesting printBack on first: " << endl;
	first.printBack();

	//test reverse
	first.reverse();

	cout << "\ntesting printFront on first after reverse: " << endl;
	first.printFront();

	cout << "\ntesting printBack on first after reverse: " << endl;
	first.printBack();


	return 0;
}


//Client function to print a list of listItemType
//Parameters: the list to print (posList)
//Returns: nothing
void print(doublyLinkedList list)
{
	for (int i = 1; i <= list.getLength(); i++)
	{
		listItemType x;
		list.retrieveElement(i, x);
		cout << x << endl;
	}
}