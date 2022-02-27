#include <iostream>
using namespace std;

#ifndef BOOK_H
#define BOOK_H

class Book {

public:
	string title;
	string author;
	string genre;

	Book() {
		title = "";
		author = "";
		genre = "";
	}

	Book(string bookTitle, string authorName, string bookGenre) {
		title = bookTitle;
		author = authorName;
		genre = bookGenre;
	}

	void printBook() {
		cout << title << " by " << author << " (" << genre << ")" << endl;
	}

	string toString() {
		return title + " by " + author + " (" + genre + ")";
	}
};
#endif /* BOOK_H */