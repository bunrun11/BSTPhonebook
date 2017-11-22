/*
 * PhonebookBST.cpp
 *
 *  Created on: Nov 20, 2017
 *      Author: Job
 */

#include "PhonebookBST.h"
#include "Person.h"
#include <fstream>

#include <ctime>

PhonebookBST::PhonebookBST() {

}

PhonebookBST::~PhonebookBST() {

}

//Adds a contact to the phonebook
void PhonebookBST::addContact(){
	string firstname, lastname;
	cout<<"Enter name: ";
	cin>>firstname>>lastname;

	string phonenumber;
	cout<<"Enter phone: ";
	cin>>phonenumber;

	if(isValidNameInput(firstname) && isValidNameInput(lastname) && isValidPhonenumberInput(phonenumber)){
		mdatabase.insert(*new Person(firstname, lastname, phonenumber));
		cout<<"'"<<firstname<<" "<<lastname<<"' has been added."<<endl;
	}
}

//loads a file of contacts to the phonebook
void PhonebookBST::loadContacts(){
	string filename;
	cout<<"Enter filename: ";
	cin>>filename;

	ifstream filestream;
	filestream.open(filename);
	if(filestream.is_open())
	{
		int count = 0;
		string firstname, lastname, phonenumber;
		while(!filestream.eof()){
			filestream>>firstname>>lastname>>phonenumber;
			mdatabase.insert(*new Person(firstname, lastname, phonenumber));
			count++;
		}
		filestream.close();
		cout<<count<<" contacts added."<<endl;
	}
	else{
		cout<<"File not Found!"<<endl;
	}
}

//returns the specified contact's phonenumber
void PhonebookBST::findContact(){
	string firstname, lastname;
	cout<<"Enter name: ";
	cin>>firstname>>lastname;

	std::clock_t begin = clock();

	Person searchingFor(firstname, lastname, "");
	Person *person = mdatabase.find(searchingFor);

	std::clock_t end = clock();
	double elapsed_secs = double(end - begin)  / CLOCKS_PER_SEC;
	cout<<"Begin: "<<begin<<endl;
	cout<<"End: "<<end<<endl;
	cout<<"Seconds Elapsed: "<<elapsed_secs<<endl;

	if(person == 0){
		cout<<"Person not Found!"<<endl;
	}
	else{
		cout<<"Phone Number: "<<person->getPhoneumber()<<endl;
	}
}

//prints all the contacts
void PhonebookBST::printAllContacts(){
	int count = mdatabase.inOrder();
	cout<<count<<" contacts..."<<endl;
}

//prints all the contacts up until the specified "filter" contact
void PhonebookBST::printFilteredContacts(){
	string firstname, lastname;
	cout<<"Enter name: ";
	cin>>firstname>>lastname;

	Person filter(firstname, lastname, "");
	int count = mdatabase.inOrder(filter);
	cout<<count<<" contacts..."<<endl;
}

bool PhonebookBST::isValidNameInput(string name){
	for(string::iterator it = name.begin(); it != name.end(); ++it){
		if(!isalpha(*it)){
			cout<<"'"<<name<<"' is invalid!"<<endl;
			return false;
		}
	}
	return true;
}

bool PhonebookBST::isValidPhonenumberInput(string number){
	for(string::iterator it = number.begin(); it != number.end(); ++it){
		if(!isdigit(*it)){
			cout<<"'"<<number<<"' is invalid!"<<endl;
			return false;
		}
	}
	return true;
}


