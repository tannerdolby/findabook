#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include "Book.h"
#include "User.h"

using namespace std;

string& ltrim(string&, const char* = " \t\n\r\f\v");
string& rtrim(string&, const char* = " \t\n\r\f\v");
string& trim(string&, const char* = " \t\n\r\f\v");
void lower(string& s);

struct UniqueNameCheck {
	bool exists;
	string uniqueName;
};

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
		for (int i=0; i < bookLogFilePaths.size(); i++) {
			string path = bookLogFilePaths[i];
			scanBookLog("./library/authors/" + removeNonAlphaNumeric(path) + "/books.txt");
		}
		scanUserLog();
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

	Librarian(vector<string> bookLogFiles, string userLogFilename) {
		bookLogFilePaths = bookLogFiles;
		userLogFile = userLogFilename;
		for (int i=0; i < bookLogFilePaths.size(); i++) {
			string path = bookLogFilePaths[i];
			scanBookLog("./library/authors/" + removeNonAlphaNumeric(path) + "/books.txt");
		}
		scanUserLog();
	}

	void scanUserLog() {
		ifstream file;
		file.open(userLogFile);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				usernameList.insert(line);
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
    }

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

	vector<string> scanBookLog(string filepath) {
		vector<string> bookLog;
		string line;
		ifstream file;
		int lineNum = 1;
		file.open(filepath);
		if (file.is_open()) {
		    string author = "";
			while (getline(file, line)) {
			    Book book;
			    istringstream ss(line);
			    string l;
			    if (lineNum == 1) {
			    	author = line;
			    }
			    book.title = line;
			    book.author = author;
			    library[author].push_back(book);
			    lineNum++;
			}
			file.close();
		} else {
			cout << "Error scanning book logs!" << endl;
		}
		return bookLog;
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