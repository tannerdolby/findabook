#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include "Book.h"

using namespace std;

string& ltrim(string&, const char* = " \t\n\r\f\v");
string& rtrim(string&, const char* = " \t\n\r\f\v");
string& trim(string&, const char* = " \t\n\r\f\v");

struct UniqueNameCheck {
	bool exists;
	string uniqueName;
};

class Logger {
public:
	string bookLogFile;
	string userLogFile;
	vector<string> bookLogs;
	vector<Book> books;

	unordered_set<string> usernameList;

	unordered_map<string, User> usersTable;

	unordered_map<string, vector<Book> > library;

	Logger() {
		bookLogFile = "./test-books.txt";
		userLogFile = "./library-log.txt";
		scanBookLog();
		scanUserLog();
	}

	Logger(string bookLogFilename, string userLogFilename) {
		bookLogFile = bookLogFilename;
		userLogFile = userLogFilename;
		scanBookLog();
		scanUserLog();
	}

	void scanUserLog() {
		ifstream file;
		// usersLogFile
		file.open("./users.txt");
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				usernameList.insert(line);
			}
		}
	}

	bool doesUserExist(string username) {
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
			} while (usernameList.find(uniqueName) != usernameList.end());
		 }
		 return uniqueName;
	}

	 void addUserToLog(string username) {
		 ofstream ofs;
		 ofs.open("./users.txt", ios::app);
		 ofs << username << endl;
	 }

	vector<string> scanBookLog() {
		vector<string> bookLog;
		string line;
		ifstream file;
		file.open(bookLogFile);
		if (file.is_open()) {
			while (getline(file, line)) {

				// add untouched line of a books entry to logs
			    bookLogs.push_back(line);

			    // create Book objects
			    // title | author | genre
			    Book book;
			    vector<string> data;
			    istringstream ss(line);
			    string l;

			    while (getline(ss, l, '|')) {
			        data.push_back(trim(l));
			    }

			    book.title = data[0];
			    book.author = data[1];
			    book.genre = data[2];

			    books.push_back(book);

			    library[book.author].push_back(book);

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