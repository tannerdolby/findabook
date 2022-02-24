#include <iostream>
#include "User.h"

class Librarian {
	string name;
public:


	Librarian() {
		name = "Root";
	};

	bool checkLibraryCard(User user) {
		LibraryCard card = user.libraryCard;
		// if the user has a non-null ID, and hasnt reached book limit ready to go!
		if (card.id >= 0 && card.numBooksCheckedOut <= card.bookLimit) {
			return true;
		}
		return false;
	}

	void createLibraryCard(User& user) {
		LibraryCard card;
		card.id = 123; // generate uuid
		card.numBooksCheckedOut = 0;
	}

	void updateLibraryCard(User& user, LibraryCard card) {
		// todo
	}

	// Search functionality - searchByAuthor, searchByTitle, searchByGenre
};