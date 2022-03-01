#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include "Book.h"
#include "User.h"

using namespace std;

string& ltrim(string&, const char* = " \t\n\r\f\v");
string& rtrim(string&, const char* = " \t\n\r\f\v");
string& trim(string&, const char* = " \t\n\r\f\v");
void lower(string& s);

class Librarian {
public:
	vector<string> bookLogFilePaths;
	string userLogFile;
	vector<string> bookLogs;
	vector<Book> books;
	string name;

    // String   | int| int             | vector<Book>
    // Username | id | # of checkedOut | List of checked out (3 at most!)
    // --------- ---- ----------------- --------------------------------
    // gnaare   | 1  | 3               | [Book1, Book2, Book3]
    // root     | 2  | 1               | [Book1]
    // key -> "username"
    // value -> <User>
    // <User> -> username, and a library card, a list of checked out books
    //	unordered_map<string, User> users;

	unordered_set<string> usernameList;
	unordered_map<string, User> usersTable;
	unordered_map<string, vector<Book> > library;

	Librarian() {
		bookLogFilePaths.push_back("Brian-Jacques");
		bookLogFilePaths.push_back("Katherine-Neville");
		bookLogFilePaths.push_back("J.K.-Rowling");
		userLogFile = "./users.txt";
		scanAllBookLogs();
		scanUserLog();
	}

	Librarian(vector<string> bookLogFiles, string userLogFilename) {
		bookLogFilePaths = bookLogFiles;
		userLogFile = userLogFilename;
		scanAllBookLogs();
		scanUserLog();
	}

	void scanUserLog() {
		ifstream file;
		int idx = 1;
		file.open(userLogFile);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				User user;
				LibraryCard card(idx);
				user.username = line;
				user.libraryCard = card;
				usersTable[line] = user;
				usernameList.insert(line);
				idx++;
			}
		}
	}

	bool doesUserExist(string username) {
		lower(username);
		if (usernameList.find(username) != usernameList.end()) {
			return true;
		}
		return false;
	}

	string pollForUniqueName(string username) {
		 string uniqueName = username;
		 if (doesUserExist(uniqueName)) {
			do {
				cout << "That username already exists!" << endl;
				cout << "Enter another username: " << endl;
				cin >> uniqueName;
				lower(uniqueName);
			} while (usernameList.find((uniqueName)) != usernameList.end());
		 }
		 return uniqueName;
	}

    void addUserToLog(string username) {
        ofstream ofs;
        ofs.open("./users.txt", ios::app);
        ofs << username << endl;
        ofs.close();
    }

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

	// todo: Search functionality

    static bool cmp(const Book& a, const Book& b) {
    	return a.title < b.title;
    }

    // todo: Search for a book by title from the library
    Book searchByTitle(string bookTitle) {
    	vector<Book> bookList = library["all"];
    	Book book;
    	// sort book objects by title
    	sort(bookList.begin(), bookList.end(), cmp);

    	return book;
    }

    // Get all the books for a given author
    vector<Book> searchByAuthor(string author) {
    	vector<Book> targetBook;
    	if (library.find(author) != library.end()) {
    		targetBook = library[author];
    		return targetBook;
    	}
    	return targetBook;
    }

    void scanAllBookLogs() {
    	for (int i=0; i < bookLogFilePaths.size(); i++) {
    		string path = bookLogFilePaths[i];
    		scanBookLog("./library/authors/" + removeNonAlphaNumeric(path) + "/books.txt");
    	}
    }

	vector<string> scanBookLog(string filepath) {
		vector<string> bookLog;
		string line;
		ifstream file;
		int lineNum = 1;
		file.open(filepath);
		if (file.is_open()) {
		    string author = "";
			while (getline(file, line)) {
			    istringstream ss(line);
			    string l;
			    if (lineNum == 1) {
			    	author = line;
			    }
			    Book book;
			    book.title = line;
			    book.author = author;
			    library[author].push_back(book);
			    library["all"].push_back(book);
			    lineNum++;
			}
			file.close();
		} else {
			cout << "Error scanning book logs!" << endl;
		}
		return bookLog;
	}

	string removeNonAlphaNumeric(string s) {
		string nonAlnum = "";
		for (int i=0; i < s.length(); i++) {
			if (!isalnum(s[i]) && s[i] != '-') {
				continue;
			}
			nonAlnum += s[i];
		}
		return nonAlnum;
	}
};

// trim from left
string& ltrim(string& s, const char* t)
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

// trim from right
string& rtrim(string& s, const char* t)
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

// trim from left & right
string& trim(string& s, const char* t)
{
    return ltrim(rtrim(s, t), t);
}

// lowercase a string in-place
void lower(string& s) {
	for (int i=0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}
}