# include <iostream>
# include <string>
# include <iomanip>
# include <format>
# include <fstream>
# include <sstream>
using namespace std ;

// Book Class
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
   return format("{},{},{},{}", title, author, year, pages) ;
}

// Implemented Library Class
class Library
{
    private:
        Book bookCollection[100] ;

        // Private Helper Functions
        void loadBooksFromFile() ;
        void saveBooksToFile() ;

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
    // Initialize empty array of Books
    bookCollection[100] ;

    // Read from a file
    loadBooksFromFile() ;
}

// Public Member Functions
void Library::addBook(Book newBook)
{
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

            // Save the book to output txt file
            saveBooksToFile() ;
        }
        else
        {
            throw out_of_range(format("Library::addBook({}) -> Can't add titled book out of range!", newBook.getTitle())) ;
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
        }
        else
        {
            // Raise an out of range error
            throw out_of_range(format("Library::removeBookByNumber({}) -> Out of range book number!", number)) ;
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

                return ; // Exit this function successfully
            }
        }
        // If a book without a matching title is found, throw an error.
        throw invalid_argument(format("Library::removeBookByTitle({}) -> Book title not found!", title)) ;
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
            throw invalid_argument(format("Library::displayBooksByAuthor({}) -> This author does not exist!", author)) ;
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
        throw invalid_argument(format("Library::displayBooksByTitle({}) -> This title does not exist!", title)) ;
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

                // // DEBUG: Print these temporarily
                // cout << "\n\nBook #" << bookIndex << '\n'
                //     << "Title: " << lineParts[0] << '\n'
                //     << "Author: " << lineParts[1] << '\n'
                //     << "Year: " << lineParts[2] << '\n'
                //     << "Pages: " << lineParts[3] << '\n' ;

                // Create a Book to place in the library
                Book rBook = Book(rTitle, rAuthor, rYear, rPages) ; 
                bookCollection[bookIndex] = rBook ;
                cout << "Book added successfully!" << '\n' ;
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
        return ;
    }
    inFile.close() ;
}

void Library::saveBooksToFile()
{
    // Generate an output file
    ofstream outFile ;
    outFile.open("finalbooklist.txt") ;

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


int main()
{
    //TEST: Initialize and test Book Object (GOOD)
    // Book androidBook("About Android 15", "Android Authors", 2024, 350) ;
    // Book androidBook16("About Android 16", "Android Authors", 2025, 370) ;
    // Book androidBook17("About Android 17", "Android Authors", 2026, 390) ;

    // cout << "String Representation of Book Elements: "
    //     << androidBook.toString() << '\n' ;

    // androidBook.displayDetails(35) ;
    // cout << "Title: " << androidBook.getTitle() << '\n' ;
    // cout << "Author: " << androidBook.getAuthor() << '\n' ;

    // // Change Year using setDetails
    // androidBook.setDetails("About Android 15", "Android Authors", 2025, 350) ;
    // androidBook.displayDetails(35) ;



    // Build the library object
    Library library ;

    // TEST: Check for overflow in BookCollection
    // for (int currentBook = 0 ; currentBook < (100 - 5) ; currentBook++ )
    // {
    //     Book spamBook = Book(format("About Android {}", currentBook), "Hacker", 2024, 350) ;
    //     library.addBook(spamBook) ;
    // }

    library.menu() ;  // Call the menu function to handle all options

    // library.addBook(androidBook) ;
    // library.addBook(androidBook16) ;
    // library.addBook(androidBook17) ;
    // library.displayAllBooks() ;

    // TEST: Add a new book to our library
    // library.addBook(androidBook) ;

    // TEST: Display all our books in the library
    // library.displayAllBooks() ;

    // TEST: Remove Book #5 (About Android 15)
    // library.removeBookByNumber(5) ;
    // library.displayAllBooks() ;

    // TEST: Attempt to remove a book out of range
    // library.removeBookByNumber(-999) ;


    // TEST: Remove a book by title
    // library.removeBookByTitle("About iOS 26") ;

    // TEST: Check books by a specific author
    // library.displayBooksByAuthor("Android Authors") ;

    // TEST: Check books by a specific author that doesn't exist in our collection
    // library.displayBooksByAuthor("iOS Authors") ;

    // TEST: Check books by a specific title that doesn't exist in our collection
    // library.displayBookByTitle("About iOS 26") ;

    // TEST: Add Book with invalid type data
    int aYear = 0 ; 

    cout << "Enter Year Here: " ;
    cin >> aYear ;
    cout << '\n' ;

    Book androidBookFraud("About Android Fraud", "Android Authors", aYear, 390) ;
    library.addBook(androidBookFraud) ;

    library.displayAllBooks() ;

    return 0 ;
}