/*
 * PhonebookBST.h
 *
 *  Created on: Nov 20, 2017
 *      Author: Job
 */

#ifndef PHONEBOOKBST_H_
#define PHONEBOOKBST_H_

#include <iostream>
#include "BinarySearchTree.h"
#include "Person.h"

class PhonebookBST {
private:
	BinarySearchTree<Person> mdatabase;

public:
	PhonebookBST();
	~PhonebookBST();

	void addContact();
	void loadContacts();
	void findContact();
	void printAllContacts();
	void printFilteredContacts();

private:
	bool isValidNameInput(string);
	bool isValidPhonenumberInput(string);
};

#endif /* PHONEBOOKBST_H_ */
