/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Assignment 06
// Date Modified: 10-16-2026
// Generative AI Use: No AI Used
//
/******************************************************/
# include <iostream>
# include <string>
# include <iomanip>
# include <fstream>
# include <sstream>
#include <limits>
using namespace std ;

class Book
{
private:
    string title ;
    string author ;
    int year ;
    int pages ;

public:
    // Member function prototypes
    Book() ;  // Default constructor
    Book(string t, string a, int y, int p) ;  // constructor with parameters
    void setDetails(string t, string a, int y, int p) ;  // Set book details
    void displayDetails(int index) ;  // Display book details in table format with index
    string getAuthor() ;  // Getter for author
    string getTitle() ;   // Getter for title
    string toString() ;   // Convert book details to string format
} ;

// Implemented Book Class Constructors and Functions
Book::Book()
{
    // Default Book Constructor
    title = "" ;
    author = "" ;
    year = 0 ;
    pages = 0 ;
}

Book::Book(string t, string a, int y, int p)
{
    title = t ;
    author = a ;
    year = y ;
    pages = p ;
}

void Book::setDetails(string t, string a, int y, int p)
{
    // Set book details
    title = t ;
    author = a ;
    year = y ;
    pages = p ;
}

void Book::displayDetails(int index)
{
    // Display book details and index
    cout << left ;

    cout << setw(5) << index 
    << setw(30) << title
    << setw(20) << author
    << setw(10) << year
    << setw(10) << pages << '\n' ;
}

string Book::getAuthor()
{
    return author ;
}

string Book::getTitle()
{
    return title ;
}

string Book::toString()
{
   return  title + ',' 
   + author + ',' 
   + to_string(year) + ',' 
   + to_string(pages); 
}

// Implemented Library Class
class Library
{
    private:
        Book bookCollection[100] ;
        int fileAccesses = 0 ; // Track how many times the source txt file was accessed

        // Private Helper Functions
        void loadBooksFromFile() ;
        void saveBooksToFile() ;
        void refreshCollection() ; // Refresh the collection of books
        bool checkStream() ; // Fix the stream if invalid input causes it to fail

    public:
        Library() ; // Default Constructor
        void addBook(Book newBook) ;
        void removeBookByNumber(int number) ;
        void removeBookByTitle(string title) ;
        void displayAllBooks() ;
        void displayBooksByAuthor(string author) ;
        void displayBookByTitle(string title) ;
        void menu() ;
} ;

Library::Library()
{
    // Read from a file
    loadBooksFromFile() ;
}

// Public Member Functions
void Library::addBook(Book newBook)
{
    // Check stream
    if (checkStream() == false)
    {
        // Exit this function
        return ;
    }
    try
    {
        int availableBookIndex = 0 ;

        // Loop through all books and find an empty index
        for (int currentBook = 0 ; currentBook < 100 ; currentBook++)
        {   
            if (bookCollection[currentBook].getTitle() == "" )
            {
                break ;
            }
            // Increment the book index 
            availableBookIndex++ ;
        }

        if (availableBookIndex >= 0 && availableBookIndex < 100)
        {
            // Assign the newBook to the available index
            bookCollection[availableBookIndex] = newBook ;
            cout << "Book added successfully!" << '\n' ;

            // Save the book to output txt file
            saveBooksToFile() ;

            // Refresh the book collection
            refreshCollection() ;
        }
        else
        {
            throw out_of_range("Library::addBook(" + newBook.getTitle() + ") -> Can't add titled book out of range!") ;
        }
    }
    catch (const out_of_range& e)
    {
        // Print the error message
        cout << "\nERROR: " ;
        cerr << e.what() << '\n' ;
        cout << '\n' ;

        // Exit function
        return ;
    }
}

void Library::displayAllBooks()
{
    // Display the table header for our library book collection
    cout << left ;

    cout << setw(5) << "No."
    << setw(30) << "Title"
    << setw(20) << "Author"
    << setw(10) << "Year"
    << setw(10) << "Pages" << '\n' ;

    string dividerLine = "---------------------------------------------------------------------------" ;
    cout << dividerLine << '\n';

    // Loop through books in our library and print them
    for (int currentBook = 0 ; currentBook < 100 ; currentBook++)
    {
        if (bookCollection[currentBook].getTitle() != "" )
        {
            // Display book in a table format
            bookCollection[currentBook].displayDetails(currentBook) ;
        }
    }
}

void Library::removeBookByNumber(int number)
{
    // Check stream
    if (checkStream() == false)
    {
        // Exit this function
        return ;
    }
    // Check if the given book number is within the 100 index range of bookCollection
    try
    {
        if (number >= 0 && number < 100)
        {
            // Remove the specified book by number (index)
            bookCollection[number] = Book() ;
            cout << "Book removed successfully!" << '\n' ;

            // Save the book to output txt file
            saveBooksToFile() ;

            // Refresh the book collection
            refreshCollection() ;
        }
        else
        {
            // Raise an out of range error
            throw out_of_range("Library::removeBookByNumber(" + to_string(number) + ") -> Out of range book number!") ;
        }
    }
    catch(const out_of_range& e)
    {
        // Print the error message
        cout << "\nERROR: " ;
        cerr << e.what() << '\n' ;
        cout << '\n' ;
    }
}

void Library::removeBookByTitle(string title)
{
    try
    {
        // Loop through all books until a matching title is found
        for (int currentBook = 0 ; currentBook < 100 ; currentBook++)
        {
            if (bookCollection[currentBook].getTitle() == title)
            {
                bookCollection[currentBook] = Book() ;
                cout << "Book removed successfully!" << '\n' ;
                // Save the book to output txt file
                saveBooksToFile() ;

                // Refresh the book collection
                refreshCollection() ;

                return ; // Exit this function successfully
            }
        }
        // If a book without a matching title is found, throw an error.
        throw invalid_argument("Library::removeBookByTitle(" + title + ") -> Book title not found!") ;
    }
    catch(const invalid_argument& e)
    {
        // Print the error message
        cout << "\nERROR: " ;
        cerr << e.what() << '\n' ;
        cout << '\n' ;
    }
}

void Library::displayBooksByAuthor(string author)
{
    try
    {
        int authoredBooks = 0 ;

        // Loop through all books and display those only by a specific author (e.g. Herman Melville)
        cout << left ;

        cout << setw(5) << "No."
        << setw(30) << "Title"
        << setw(20) << "Author"
        << setw(10) << "Year"
        << setw(10) << "Pages" << '\n' ;

        string dividerLine = "---------------------------------------------------------------------------" ;
        cout << dividerLine << '\n';

        // Loop through books in our library and print them
        for (int currentBook = 0 ; currentBook < 100 ; currentBook++)
        {
            if (bookCollection[currentBook].getAuthor() == author )
            {
                // Display book in a table format
                bookCollection[currentBook].displayDetails(currentBook) ;

                authoredBooks++ ;
            }
        }

        // If we didn't find any books of this author
        if (authoredBooks == 0)
        {
            throw invalid_argument("Library::displayBooksByAuthor(" + author + ") -> This author does not exist!") ;
        }
    }
    catch(const invalid_argument& e)
    {
        // Print the error message
        cout << "\nERROR: " ;
        cerr << e.what() << '\n' ;
        cout << '\n' ;
    }
}

void Library::displayBookByTitle(string title)
{
     try
    {
        // Loop through all books and display the one with our specified title
        cout << left ;

        cout << setw(5) << "No."
        << setw(30) << "Title"
        << setw(20) << "Author"
        << setw(10) << "Year"
        << setw(10) << "Pages" << '\n' ;

        string dividerLine = "---------------------------------------------------------------------------" ;
        cout << dividerLine << '\n';

        // Loop through books in our library and print them
        for (int currentBook = 0 ; currentBook < 100 ; currentBook++)
        {
            if (bookCollection[currentBook].getTitle() == title)
            {
                // Display book in a table format
                bookCollection[currentBook].displayDetails(currentBook) ;
                //Exit function
                return;
            }
        }
        // Throw an error if no book of the desired title was found
        throw invalid_argument("Library::displayBooksByTitle(" + title + ") -> This title does not exist!") ;
    }
    catch(const invalid_argument& e)
    {
        // Print the error message
        cout << "\nERROR: " ;
        cerr << e.what() << '\n' ;
        cout << '\n' ;
    }
}

// Function to display the menu and handle user's choice
void Library::menu()
{
    int choice ;

    do
    {
        cout << endl << "*** Library Management System ***" << endl ;
        cout << "1. Add a new book" << endl ;
        cout << "2. Display all books" << endl;
        cout << "3. Display books by a specific author" << endl ;
        cout << "4. Remove a book by number" << endl ;
        cout << "5. Remove a book by title" << endl ;
        cout << "6. Display a book by title" << endl ;
        cout << "7. Exit" << endl << endl ;
        cout << "Enter your choice: " ;
        cin >> choice ;
        cout << endl ;

        if (choice == 1)
        {
            string title, author ;
            int year, pages ;

            // Input the book details
            cout << "Enter the title: " ;
            cin.ignore(); // To clear the newline left in the buffer by previous input
            getline(cin, title) ;
            cout << "Enter the author: " ;
            getline(cin, author) ;
            cout << "Enter the year of publication: " ;
            cin >> year ;
            cout << "Enter the number of pages: " ;
            cin >> pages ;

            // Create a new book object and add it to the library
            Book newBook(title, author, year, pages) ;
            addBook(newBook) ;
        }
        else if (choice == 2)
        {
            displayAllBooks() ;
        }
        else if (choice == 3)
        {
            string author ;
            cout << "Enter the author's name: " ;
            cin.ignore() ;
            getline(cin, author) ;
            displayBooksByAuthor(author) ;
        }
        else if (choice == 4)
        {
            int number ;
            displayAllBooks() ;
            cout << endl << "Enter the number of the book to remove: " ;
            cin >> number ;
            removeBookByNumber(number) ;
        }
        else if (choice == 5)
        {
            string title;
            cout << "Enter the title of the book to remove: " ;
            cin.ignore() ;
            getline(cin, title) ;
            removeBookByTitle(title) ;
        }
        else if (choice == 6)
        {
            string title ;
            cout << "Enter the title of the book to display: " ;
            cin.ignore() ;
            getline(cin, title) ;
            displayBookByTitle(title) ;
        }
        else if (choice == 7)
        {
            cout << "Exiting the program." << endl ;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl ;
        }
    } while (choice != 7) ;
}

// Helper functions
void Library::loadBooksFromFile()
{
    // Declare input file
    ifstream inFile ;
    inFile.open("booklist.txt") ;

    // Book Collection Index
    int bookIndex = 0 ;

    // Read all lines from input file
    if (inFile.is_open())
    {
        while (!inFile.eof())
        {
            try
            {
                // Capture a line in the file and convert to a stream
                string currentLine = "" ;
                getline(inFile, currentLine) ;
                if (currentLine == "") // Skip if the line is just whitespace
                {
                    continue ;
                }
                stringstream ss(currentLine) ;

                
                // Each part of the comma separated file line
                const int LINE_PARTS_SIZE = 4 ;
                string lineParts[LINE_PARTS_SIZE] ;

                // Sub loop to break up line stream by comma
                for(int linePart = 0 ; linePart < LINE_PARTS_SIZE ; linePart++)
                {
                    getline(ss, lineParts[linePart], ',') ;
                }

                // Place the segments of the line into variables (cast strings to int for year and pages)
                string rTitle = lineParts[0] ;
                string rAuthor = lineParts[1] ;
                int rYear = stoi(lineParts[2]) ;
                int rPages = stoi(lineParts[3]) ;

                // Create a Book to place in the library
                Book rBook = Book(rTitle, rAuthor, rYear, rPages) ; 
                bookCollection[bookIndex] = rBook ;
                
                if (fileAccesses == 0)
                {
                    // Do not display this message on collection refresh.
                    // Only on initial startup.
                    cout << "Book added successfully!" << '\n' ;
                }
            }
            catch (const invalid_argument& e)
            {
                // Print the error message
                cout << "\nERROR: " ;
                cerr << e.what() ;
                cout << '\n' ;

                // Skip to next line
                continue ;
            }
            bookIndex++ ; 
        }
    }
    else
    {
        // Exit function with no books if file does not open
        cout << "ERROR: Input file not opened" ;
        return ;
    }
    // Increment that this file has been accessed and close file
    fileAccesses++ ;
    inFile.close() ;
}

void Library::saveBooksToFile()
{
    // Generate an output file
    ofstream outFile ;
    outFile.open("booklist.txt") ;

    // Write all books as a comma-separated file
    if (outFile.is_open())
    {
        for (int currentBook = 0 ; currentBook < 100 ; currentBook++)
        {
            if (bookCollection[currentBook].getTitle() != "")
            {
                // Convert Book details to a string
                outFile << bookCollection[currentBook].toString() << '\n' ;
            }
        }

    }
    else
    {
        return ;
    }
    outFile.close() ;
}

// My custom helpers
void Library::refreshCollection()
{
    // Clear books from collection array
    for (int currentBook = 0 ; currentBook < 100 ; currentBook++)
    {
        bookCollection[currentBook] = Book() ;
    }

    // Reload books from the file
    loadBooksFromFile() ;
}

bool Library::checkStream()
{
    // Clear the stream if failure is detected
    if (cin.fail() == true)
    {
        cin.clear() ;
        cin.ignore(numeric_limits<streamsize>::max(), '\n') ;
        cout << '\n' << "ERROR: Cin Stream Error -> Invalid Integer Input, operation aborted!" << '\n' ;
        return false ;
    }

    // Return true if the stream is okay
    return true ;
}
// Main function
int main()
{
    Library library ;
    library.menu() ;  // Call the menu function to handle all options
    
    return 0; 
}

/******************************************************/
/*
Post Assignment Reflection:

NOTE: I just discovered that the 'works on my machine' trap screwed me over.
    As my previous assignment failed to compile on the CSIS-smoke grading server
    due to a missing header, even though it somehow compiled fine on my local machine
    without the header declared. So now I'm testing my source code
    in a fresh VM on an actual linux distribution so I hopefully
    run into less issues like these.

I learned about how I could define a class to create
an object with different attributes and functions. I then
applied that knowledge with my knowledge of arrays, loops,
and control flow to build an entirely new class that could contain
multiple instances of the Book class objects.

I looked heavily at both class lecture examples and searched up documentation
online to review how to read and write to a file, learn more about classes,
and find help for things I wanted to add to my program. Such as
interpolating strings in a straightforward manner using format. I also
broke down the problem by implementing class functions and testing
them in a separate file.

The hardest part of this program in my opinion was implementing the
loadBooksFromFile() function. My approach used getline() to
extract a line (in an EOF controlled while loop) from the booklist.txt
file and store it as a string. I then "casted" that line string
using sstream into a stream that I broke down further and stored
into separate strings I could use to add details to a book in the library. 

As my implementation was feature complete. I compared it
carefully against the reference output to evaluate the correctness
of my implemented classes. In the initial comparison round
I found major bugs in my initial implementation
with invalid integer input and how the
book collection numbers were displayed after removing a book.

To deal with invalid integer input, I created a small private
bool helper function that cleared the input stream whenever
it failed. I then used that helper to check the stream
in any function that requested some type of integer input from
the user via the menu. If the stream was in a fail state, I then
cleared it and aborted the function to prevent further code inside
it from executing. This fixed the issue of an infinite menu loop 
occurring and inconsistent data being written to the booklist.txt file.

For ensuring the collection numbers were displayed in a consistent and
updated manner after a book was removed, I tweaked my implemented
loadBooksFromFile() helper to refresh the internal library collection (bookCollection[]).
This was a hack that wasn't as efficient compared to using a sorting algorithm
on the ineternal library collection array, but as I'm preparing for the midterm exam
I decided to use this approach to save time and take note of it.

Overall, this assigment was challenging and took me many hours to complete. But I felt
like searching forums, documentation and the lecture example codes helped me understand
how I could implement specific parts of this assignment which was a huge help.
*/
/******************************************************/