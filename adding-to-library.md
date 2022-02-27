If using JavaScript is something your up for:

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

Otherwise, feel free to populate book titles however you would like for adding to this project.