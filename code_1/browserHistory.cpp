/*************************************************************/
/*                BrowserHistory Definition                  */
/*************************************************************/
/* TODO: Implement the member functions of BrowserHistory    */
/*     This class uses a linked-list of WebPage structs to   */
/*     represent the schedule of web pages                   */
/*************************************************************/

#include "browserHistory.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

/*
 * Purpose: Constructor for empty linked list
 * @param none
 * @return none
 */
BrowserHistory::BrowserHistory() {
    /*
    DO NOT MODIFY THIS
    This constructor is already complete. 
    */
    head = nullptr;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool BrowserHistory::isEmpty() {
    /* finished. do not touch. */
    return (head == NULL);
}

/*
 * Purpose: prints the current list of pages 
 * in the given format.
 * [ID::1]-(URL::url1) -> ... -> NULL
 * @param none
 * @return none
 */
void BrowserHistory::displayHistory() {
    // TODO
    cout << "== CURRENT BROWSER HISTORY ==" << endl;
    if (isEmpty()) {
        cout << "Empty History" << endl;
        cout << "NULL\n===\n";
        return;
    }
    WebPage* current = head;
    while (current!=nullptr) {
        cout << "[ID:: " << current->id << "]-(URL::" << current->url << ") -> ";
        current=current->next;
    }
    cout << "NULL\n===\n";
}

/*
 * Purpose: Add a new webpage to the browser history LL
 *   between the previous and the page that follows it in the list.
 * @param previousPage, the show that comes before the new page
 * @param newPage, the webpage to be added. 
 * @return none
 */
void BrowserHistory::addWebPage(WebPage* previousPage, WebPage* newPage) {
    // TODO
    if (previousPage==NULL) {
        newPage->next=head;
        head=newPage;
        cout << "adding: " << "[" << newPage->id << "]-" << newPage->url << " (HEAD)\n";
        return;
    }
    newPage->next=previousPage->next;
    previousPage->next=newPage;
    cout << "adding: " << "[" << newPage->id << "]-" << newPage->url << " (prev: " << "[" << previousPage->id << "])\n";
    return;
}

/*
 * Purpose: populates the BrowserHistory with the predetermined pages
 * @param none
 * @return none
 */
void BrowserHistory::buildBrowserHistory() {
    WebPage* colorado = new WebPage{10, 0, "https://www.colorado.edu/", "", nullptr};
    WebPage* wikipedia = new WebPage{11, 0, "https://www.wikipedia.org/", "", nullptr};
    WebPage* brilliant = new WebPage{12, 0, "https://brilliant.org/", "", nullptr};
    WebPage* khanacademy = new WebPage{13, 0, "https://www.khanacademy.org/", "", nullptr};
    WebPage* numberphile = new WebPage{14, 0, "https://www.numberphile.com/", "", nullptr};
    WebPage* prevpage = head;
    /*while (prevpage!=nullptr && prevpage->next!=nullptr) {
        prevpage=prevpage->next;
    }*/
    prevpage=nullptr;
    addWebPage(prevpage, colorado);
    addWebPage(colorado, wikipedia);
    addWebPage(wikipedia, brilliant);
    addWebPage(brilliant, khanacademy);
    addWebPage(khanacademy, numberphile);
    return;
}


/*
 * Purpose: Search the BrowserHistory for the specified 
 * web page by ID and return a pointer to that node.
 * @param int id - ID of the web page to look for in LL.
 * @return pointer to node of page, or NULL if not found
 *
 */
WebPage* BrowserHistory::searchPageByID(int id) {
    // TODO
    WebPage* current = head;
    while (current!=nullptr) {
        if (current->id==id) {
            return current;
        }
        current=current->next;
    }
    return nullptr;
}


/*
 * Purpose: Search the BrowserHistory for the specified 
 * web page by the URL and return a pointer to that node.
 * @param string url - url of the web page to look for in LL.
 * @return pointer to node of page, or NULL if not found
 *
 */
WebPage* BrowserHistory::searchPageByURL(std::string url) {
    // TODO
    WebPage* current = head;
    while (current!=nullptr) {
        if (current->url==url) {
            return current;
        }
        current=current->next;
    }
    return nullptr;
}

/*
 * Purpose: Give an owner to a web page.
 * @param receiver - name of the show that is receiving the rating
 * @param rating - the rating that is being given to a show
 * @return none
 */
void BrowserHistory::addOwner(std::string url, string owner) {
    WebPage* tmp = searchPageByURL(url);
    if (tmp==nullptr) {
        cout << "Page not found" << endl;
        return;
    }
    tmp->owner=owner;
    cout << "The owner (" << tmp->owner << ") has been added for the ID - "<< tmp->id << "\n";
    return;

}

void BrowserHistory::updateViews(string url) {
    // TODO
    WebPage* current = head;
    while (current!=nullptr) {
        if (current->url==url) {
            current->views++;
        }
        current=current->next;
    }
    return;
}
