class LibraryCard {
public:
	int id;
	int numBooksCheckedOut;
	int bookLimit;

	LibraryCard() {
		id = 0;
		numBooksCheckedOut = 0;
		bookLimit = 3; // only 3 books can be checked out at a time
	}
};

class User {
public:
	string username;
	LibraryCard libraryCard;
	vector<Book> checkedOutBooks;

	User() {
		username = "default-user";
		LibraryCard card;
		card.id += 1;
		card.numBooksCheckedOut = 0;
		libraryCard = card;
		vector<Book> books;
		checkedOutBooks = books;
	}

	// Ask the librarian to do something
//	void askLibrarian(User user, string task) {
//		Librarian librarian;
//	}
};