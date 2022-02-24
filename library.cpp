#include <iostream>
#include "BookLogReader.h"
#include "Librarian.h"

using namespace std;

int main() {

	// Initialize an instance of the BookLogReader class to read the log file
	BookLogReader logger("./book-log.txt");

	cout << "Text logs" << endl;
	for (auto line : logger.logs) {
		cout << line << endl;
	}

	cout << endl;

	cout << "Book Object logs" << endl;

	for (auto book : logger.books) {
		book.toStr();
	}

	cout << endl;

	cout << "Library" << endl;

	for (auto pair : logger.library) {
		cout << pair.first << ": " << endl;
		for (auto book : pair.second) {
			book.toStr();
		}
		cout << endl;
	}

	// Librarian will keep track of book operations and checking users
	// library cards to allow them to browse the library
	Librarian librarian;


	User gnaare;
	gnaare.username = "gnaare";

	cout << gnaare.username << endl;
	cout << gnaare.libraryCard.id << endl;
	cout << gnaare.libraryCard.bookLimit << endl;

	return 0;
}