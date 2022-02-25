#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include "User.h"

class Librarian {
public:
	string name;

	Librarian() {
		name = "Root";
	};

	// handle a interaction with user for checking out a book
	// and write to the "Librarian log" to keep track of users checking
	// out a book and at what time/date

	bool checkLibraryCard(User user) {
		LibraryCard card = user.libraryCard;
		// if the user has a non-null ID, and hasnt reached book limit ready to go!
		if (card.id >= 0 && card.booksCheckedOut <= card.bookLimit) {
			return true;
		}
		return false;
	}

	LibraryCard createLibraryCard(int id) {
		LibraryCard card;
		card.id = id + 1;
		card.booksCheckedOut = 0;
		return card;
	}

	void updateLibraryCard(User& user, LibraryCard card) {
		// todo
	}

	// Search functionality - searchByAuthor, searchByTitle, searchByGenre
};
#endif
