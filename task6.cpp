#include <iostream>
#include <string>
using namespace std;

class Bookstore {
public:
    string isbn;
    string title;
    string author;
    string genre;
    float price;
    int stock;

    void displayBook();
    void addNewBook();
    void updateStock();
    void processSale();
    void salesreport();
};
void Bookstore::salesreport()
{
    cout<<"Process sales has not been emplement";
}
void Bookstore::displayBook() {
    cout <<"ISBN: "<<isbn;
    cout <<", Title: "<<title;
    cout <<", Author: "<<author;
    cout <<", Genre: "<<genre;
    cout <<", Price: $"<<price;
    cout <<", Stock: " << stock<<endl;
}

void Bookstore::addNewBook() {
    cout <<"Enter ISBN: ";
    cin >>isbn;
    cout <<"Enter Title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter Author: ";
    getline(cin, author);
    cout <<"Enter Genre: ";
    getline(cin, genre);
    cout << "Enter Price: ";
    cin >>price;
    cout << "Enter Stock: ";
    cin >>stock;
    cout << "Book successfully added." << endl;
}

void Bookstore::updateStock() {
    int newStock = 0;
    cout <<"Enter new stock: ";
    cin >>newStock;
    if (newStock>= 0) {
        stock = newStock;
        cout <<"Stock updated successfully." << endl;
    }
     else {
        cout <<"Invalid stock value entered." << endl;
    }
}

void Bookstore::processSale() {
    int quantitySold = 0;
    cout << "Enter quantity sold: ";
    cin >> quantitySold;

    if (quantitySold > 0 && quantitySold <= stock) {
        float totalCost = price * quantitySold;
        stock -= quantitySold;
        cout << "Sale processed successfully." << endl;
        cout << "Total cost: $" << totalCost << endl;
        cout << "Remaining stock: " << stock << endl;
    }
    else {
        cout <<"Invalid quantity sold or insufficient stock." << endl;
    }
}

int main() {
    const int MAX_BOOKS = 100;
    Bookstore b[MAX_BOOKS];
    int numBooks = 0;
    string choice;

    while (choice != "6") {
        cout << "Bookstore Inventory Management System" << endl;
        cout << "1. Add New Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Update Stock" << endl;
        cout << "4. Process Sale" << endl;
        cout << "5. Generate sales report" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == "1") {
            if (numBooks < MAX_BOOKS) {
                b[numBooks].addNewBook();
                numBooks++;
            }
            else {
                cout << "Maximum book capacity reached." << endl;
            }
        }
        else if (choice == "2") {
            cout << ">>> " << endl;
            for (int i = 0; i < numBooks; i++) {
                b[i].displayBook();
            }
        }
        else if (choice == "3") {
            if (numBooks > 0) {
                string isbn;
                cout << "Enter ISBN: ";
                cin >> isbn;
                bool found = false;
                for (int i = 0; i < numBooks; i++) {
                    if (b[i].isbn == isbn) {
                        b[i].updateStock();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Book not found." << endl;
                }
            }
            else {
                cout << "No books in inventory." << endl;
            }
        }
        else if (choice == "4") {
            if (numBooks > 0) {
                string isbn;
                cout << "Enter ISBN: ";
                cin >> isbn;
                bool found = false;
                for (int i = 0; i < numBooks; i++) {
                    if (b[i].isbn == isbn) {
                        b[i].processSale();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Book with not found." << endl;
                }
            }
            else {
                cout << "No books in inventory." << endl;
            }
        }
        else if (choice == "5") {

            b[numBooks].salesreport();

        }
        else if(choice == "6"){
            cout<<"Exiting the program...";
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
