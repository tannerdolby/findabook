Adding to the library only takes a few steps. Depending on what type of addition you would like to do, there will only be two scenarios:

1. Add a single book or books to an existing author directory.
2. Create a brand new author directory and add a single book or books.

For situation one, simply add book title strings to the exisiting `/Author-Name/books.txt` file at the end of the file. Ensuring you add book titles each on a newline.

For situation two, create a new directory in the project `/Author-Name/` and then create a `books.txt` file inside the newly created author directory. From here, add book titles to the text file with each title being on a newline.

## Generating Book Titles
If using JavaScript is something your up for:

Utilize the npm package [openlibrary](https://github.com/tannerdolby/openlibrary) and call `getAllTitles` to quickly generate a list of book titles for a given author. Or if you already have book titles, go ahead and insert them at the end of books.txt inside their respective author directory.

```js
const openlibrary = new OpenLibrary();
openlibrary.getAllTitles("Katherine Neville").then(res => {
    res.forEach(title => {
        console.log(title);
    });
});
// The Eight
// Magic Circle
// ...
```

The list printed from above can be copied and pasted into a file called books.txt inside a given authors directory, or you could add your own book title data. Note: If you are adding a whole new author to the library, first create the directory i.e. `/Author-Name` and then place a books.txt file within. Now add the author name on the first line of the text file and then begin adding the book titles separated by newlines.

Otherwise, feel free to populate book titles however you would like for adding to this project.