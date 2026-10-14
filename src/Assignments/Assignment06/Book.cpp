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