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
