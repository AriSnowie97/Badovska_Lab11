#include <iostream>
#include <string>
#include <regex>

using namespace std;

struct Book {
private:
    string title;
    string author;
    string ISBN;

public:
    Book() = default;

    Book(const string& t, const string& a, const string& i)
        : title(t), author(a), ISBN(i) {
        // Improved ISBN validation and formatting
        regex isbnRegex("\\d{3}-\\d{5}-\\d{1}");
        if (!regex_match(ISBN, isbnRegex)) {
            cerr << "Invalid ISBN format: " << ISBN << endl;
            ISBN = ""; // Clear the invalid ISBN
        }
        else {
            formatISBN();
        }
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    string getISBN() const {
        return ISBN;
    }

private:
    void formatISBN() {
        // Remove all non-digit characters
        regex nonDigit("\\D");
        string formattedISBN = regex_replace(ISBN, nonDigit, "");

        // Format the ISBN to the standard 10-digit format
        if (formattedISBN.length() == 10) {
            ISBN = formattedISBN.substr(0, 3) + "-" + formattedISBN.substr(3, 5) + "-" + formattedISBN.substr(8, 1);
        }
        else {
            cout << "Invalid ISBN length: " << formattedISBN << endl;
            ISBN = ""; // Clear the invalid ISBN
        }
    }
};

int main() {
    Book book1("Harry Potter", "J.K. Rowling", "978-5-17-091121-6");
    Book book2("Lord of the Rings", "J.R.R. Tolkien", "1234567890"); // Invalid ISBN

    cout << "Book 1:" << endl;
    cout << "  Title: " << book1.getTitle() << endl;
    cout << "  Author: " << book1.getAuthor() << endl;
    cout << "  ISBN: " << book1.getISBN() << endl;

    cout << "\nBook 2:" << endl;
    cout << "  Title: " << book2.getTitle() << endl;
    cout << "  Author: " << book2.getAuthor() << endl;
    cout << "  ISBN: " << book2.getISBN() << endl;

    return 0;
}