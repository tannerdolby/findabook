class LibraryCard {
public:
	int id;
	int booksCheckedOut;
	int bookLimit;

	LibraryCard() {
		id = 1;
		booksCheckedOut = 0;
		bookLimit = 3; // only 3 books can be checked out at a time
	}

	LibraryCard(int cardId) {
		id = cardId;
		booksCheckedOut = 0;
		bookLimit = 3;
	}

	void printCard() {
		cout << "Card: " << to_string(id) << ", checked out books: " << to_string(booksCheckedOut) << endl;
	}

	string toString() {
		string s = "library card: " + to_string(id);
		s += ", checked out books: " + to_string(booksCheckedOut);
		return s;
	}
};
