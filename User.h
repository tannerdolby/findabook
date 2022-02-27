#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#ifndef USER_H
#define USER_H

#include "LibraryCard.h"
#include "Book.h"

class User {
public:
	string username;
	LibraryCard libraryCard;
	vector<Book> checkedOutBooks;

	User() {
		ofstream ofs;
		LibraryCard card;
		vector<Book> books;
		username = "default-user";
		libraryCard = card;
		checkedOutBooks = books;
	}

	User(string name) {
		ofstream ofs;
		LibraryCard card;
		vector<Book> books;
		username = name;
		libraryCard = card;
		checkedOutBooks = books;
	}

	void printUser() {
		cout << username << ": ";
		libraryCard.printCard();
	}

	string toString() {
		return username + " | " + libraryCard.toString();
	}

};
#endif /* USER_H */