#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include "Book.h"

using namespace std;

string& ltrim(string&, const char* = " \t\n\r\f\v");
string& rtrim(string&, const char* = " \t\n\r\f\v");
string& trim(string&, const char* = " \t\n\r\f\v");

class BookLogReader {
public:
	string logfile;
	vector<string> logs;
	vector<Book> books;
	unordered_map<string, vector<Book> > library;

	BookLogReader() {
		logfile = "";
		scanBookLog();
	}

	BookLogReader(string logFilePath) {
		logfile = logFilePath;
		scanBookLog();
	}

	vector<string> scanBookLog() {
		vector<string> bookLog;
		string line;
		ifstream file;
		file.open(logfile);
		if (file.is_open()) {
			while (getline(file, line)) {

				// add untouched line of a books entry to logs
			    logs.push_back(line);

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