# Find A Book - Library System 📙
Browse the wares of the library. A user must be created to obtain a library card in order to check out books. The librarian will handle anything you might need while you look for a good read.

## Demo
todo

## Adding To The Library
Can't find a book or an author your looking for? Feel free to add books to an existing authors book log or create a log for a new author in a few quick steps:

1. Utilize the npm package [openlibrary](https://github.com/tannerdolby/openlibrary) and call `getAllTitles` to quickly generate a list of book titles for a given author. Or if you already have book titles, go ahead and insert them at the end of books.txt inside their respective author directory.

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

2. The list printed from above can be copied and pasted into a file called books.txt inside a given authors directory, or you could add your own book title data. Note: If you are adding a whole new author to the library, first create the directory i.e. `/Author-Name` and then place a books.txt file within. Now add the author name on the first line of the text file and then begin adding the book titles separated by newlines.

## Resources
Book information provided by the [Open Library API](https://openlibrary.org/dev/docs/api/).