#include <iostream>
using namespace std;

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

	void toStr() {
		cout << title << " by " << author << " (" << genre << ")" << endl;
	}
};