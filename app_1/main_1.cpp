#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "../code_1/browserHistory.hpp"

using namespace std;

void displayMenu();

int main(int argc, char* argv[]) {

    // DO NOT MODIFY THIS.
    if(argc>1) 
    {
        freopen(argv[1],"r",stdin);
    }
    // DO NOT MODIFY ABOVE.

    BrowserHistory bh;

    while (true) {
        displayMenu();
        int input;
        cin >> input;
        if (input==1) {
            bh.buildBrowserHistory();
            bh.displayHistory();
        } else if (input==2) {
            bh.displayHistory();
        } else if (input==3) {
            string url;
            int id;
            string prev;
            cout << "Enter the new web page's url:" << endl;
            cin >> url;
            bool isValid=false;
            while (!isValid) {
            cout << "Enter the new web page's id:" << endl;
                cin >> id;
                WebPage* temp = bh.searchPageByID(id);
                if (temp!=nullptr) {
                    cout << "This ID already exists. Try again." << endl;
                } else {
                    isValid=true;
                }
            }
            isValid=false;
            WebPage* prevPage=nullptr;
            while (!isValid) {
                cout << "Enter the previous page's url (or First):" << endl;
                cin >> prev;
                if (prev!="First") {
                    prevPage = bh.searchPageByURL(prev);
                    if (prevPage!=nullptr) {
                        isValid=true;
                    } else {
                        cout << "INVALID(previous page url)... Please enter a VALID previous page url!" << endl;
                    }
                } else {
                    isValid=true;
                }
            }
            WebPage* newPage = new WebPage{id, 0, url, "", nullptr};
            bh.addWebPage(prevPage, newPage);
        } else if (input==4) {
            string url;
            string owner;
            WebPage* temp=nullptr;
            bool isValid=false;
            while (!isValid) {
                cout << "Enter url of the web page to add the owner:" << endl;
                cin >> url;
                temp = bh.searchPageByURL(url);
                if (temp!=nullptr) {
                    isValid=true;
                } else {
                    cout << "Page not found. Try again." << endl;
                }
            }
            isValid=false;
            cout << "Enter the owner:";
            owner="";
            std::getline(std::cin >> std::ws, owner);
            cout << "The owner (" << owner << ") has been added for the ID - " << temp->id << endl;
        } else if (input==5) {
            string url;
            bool isValid=false;
            WebPage* temp=nullptr;
            while (!isValid) {
                cout << "Enter url of the web page to check the view count: " << endl;
                cin >> url;
                temp = bh.searchPageByURL(url);
                if (temp!=nullptr) {
                    isValid=true;
                    cout << "View count for URL - " << url << " is " << temp->views << endl;
                } else {
                    cout << "Page not found. Try again." << endl;
                }
            }
        } else {
            cout << "Quitting...Goodbye!\n";
            return 0;
        }
    }
    
    return 0;
}




/************************************************
           Definitions for main_1.cpp
************************************************/
void displayMenu()
{
    // COMPLETE: You DO NOT need to edit this
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build history " << endl;
    cout << " 2. Display history " << endl;
    cout << " 3. Add web page " << endl;
    cout << " 4. Add owner" << endl;
    cout << " 5. View count for a web page" << endl;
    cout << " 6. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}