#include <unordered_map>

#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include "User.h"

class Librarian {
public:
	string name;
	// String   | int| int             | vector<Book>
	// Username | id | # of checkedOut | List of checked out (3 at most!)
	// --------- ---- ----------------- --------------------------------
	// gnaare   | 1  | 3               | [Book1, Book2, Book3]
	// root     | 2  | 1               | [Book1]
	// key -> "username"
	// value -> <User>
	// <User> -> username, and a library card, a list of checked out books
	unordered_map<string, User> users;



	Librarian() {
		name = "Root";
	};



	// handle a interaction with user for checking out a book
	// and write to the "Librarian log" to keep track of users checking
	// out a book and at what time/date

	bool checkLibraryCard(User user) {
		LibraryCard card = user.libraryCard;
		// if the user has a non-null ID, and hasnt reached book limit ready to go
		if (card.id >= 0 && card.booksCheckedOut <= card.bookLimit) {
			return true;
		}
		return false;
	}

	void updateLibraryCard(User& user, LibraryCard updatedCard) {
		user.libraryCard = updatedCard;
	}

	// Search functionality - searchByAuthor, searchByTitle, searchByGenre
};
#endif