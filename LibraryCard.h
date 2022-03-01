#include <fstream>
using namespace std;

class LibraryCard {
public:
	int id;
	int booksCheckedOut;
	int bookLimit;
	int lastAddedId;

	LibraryCard() {
		lastAddedId = 0;
		id = lastAddedId;
		booksCheckedOut = 0;
		bookLimit = 3;
	}

	LibraryCard(int cardId) {
		id = cardId;
		booksCheckedOut = 0;
		bookLimit = 3;
		lastAddedId = id;
	}

	void printCard() {
		cout << "Card: " << to_string(id) << ", checked out books: " << to_string(booksCheckedOut) << endl;
	}

	string toString() {
		string s = "library card: " + to_string(id);
		s += ", # checked out: " + to_string(booksCheckedOut);
		return s;
	}
};