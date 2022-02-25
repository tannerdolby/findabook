#include <iostream>
#include "BookLogReader.h"
#include "Librarian.h"

using namespace std;

int main() {

	// Initialize an instance of the BookLogReader class to read the log file
	BookLogReader logger("./test-books.txt");

	cout << "Text logs" << endl;
	for (auto line : logger.logs) {
		cout << line << endl;
	}

	cout << endl;

	cout << "Book Object logs" << endl;

	for (auto book : logger.books) {
		book.printBook();
	}

	cout << endl;

	cout << "Library" << endl;

	for (auto pair : logger.library) {
		cout << pair.first << ": " << endl;
		for (auto book : pair.second) {
			book.printBook();
		}
		cout << endl;
	}

	// Librarian will keep track of book operations and checking users
	// library cards to allow them to browse the library
	Librarian librarian;


	User userOne("gnaare");

	cout << userOne.username << endl;
	cout << userOne.libraryCard.id << endl;
	cout << userOne.libraryCard.bookLimit << endl;

	return 0;
}
