//============================================================================
// Name        : PhoneBook.cpp
// Author      : Job
// Date		   : 11/20/2017
// Description : A phonebook using a BST
//============================================================================

#include <iostream>
#include "BinarySearchTree.h"
#include "Person.h"
#include "PhonebookBST.h"
using namespace std;

int main() {

	PhonebookBST phonebook;
	bool isDone = false;

	cout<<"***MY PHONEBOOK APPLICATION***"<<endl;
	cout<<"Please choose an operation:"<<endl;
	char input;
	do
	{
		cout<<"A(Add)|L(Load)|S(Search)|P(Print)|F(Filter)|Q(Quit): ";
		cin>>input;

		switch(input){
		case 'a':
		case 'A':
			phonebook.addContact();
			break;

		case 'l':
		case 'L':
			phonebook.loadContacts();
			break;

		case 's':
		case 'S':
			phonebook.findContact();
			break;

		case 'p':
		case 'P':
			phonebook.printAllContacts();
			break;

		case 'f':
		case 'F':
			phonebook.printFilteredContacts();
			break;

		case 'q':
		case 'Q':
			cout<<"Bye"<<endl;
			isDone = true;
			break;
		}

		cout<<endl;
	}
	while(!isDone);

	return 0;
}

