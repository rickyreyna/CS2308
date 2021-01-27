#include "StringList.h"
#include <iostream>

using namespace std;

StringList::StringList()
{
    head = NULL;
}

StringList::~StringList()
{

}

int StringList::count()
{
    int num_count = 0;
    StringNode *ptr;
    ptr = new StringNode;
    ptr = head;
    while(ptr != NULL)
    {
        num_count += 1;
        ptr = ptr -> next;
    }
    delete ptr;

return num_count;
}

void StringList::add(string x)
{
    StringNode *NewString;
    NewString = new StringNode;
    NewString -> data = x;
    NewString -> next = head;
    head = NewString;
}

bool StringList::remove(string x)
{
    StringNode *previous;
    previous = new StringNode;

    StringNode *browser;
    browser = new StringNode;
    browser = head;

    while(browser -> data != x)
    {
        previous -> next = browser;
        browser = browser -> next;
    }
    if(browser -> data != x)
    {
        previous -> next = browser -> next;
        browser -> next = NULL;
        delete browser;
        delete previous;
        return true;
    }
    else if(browser == head)
    {
        head = browser -> next;
        delete browser;
        delete previous;
        return true;
    }
    else
    {
        delete browser;
        delete previous;
        return false;
    }
}

void StringList::display()
{
    StringNode *display;
    display = new StringNode;
    display -> next = head;

    while(display)
    {
        cout << display -> data << endl;
        display = display -> next;
    }
    delete display;

}

string StringList::minimum()
{
    StringNode *previous;
    previous = new StringNode;
    previous -> data = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";

    StringNode *first;
    first = new StringNode;
    first -> next = head;

    string smallest;

        while(first)
    {
        if( (first -> data) < (previous -> data) )
        {
            smallest = first -> data;
        }
        previous -> next = first;
        first = first -> next;
    }
return smallest;
}

void StringList::sort()
{
    string list_remove;
    bool check_for_remove;
    int SIZE;

    SIZE = count();

    for(int i = 1; i > SIZE; i++)
    {
        list_remove = minimum();
        add(list_remove);
        check_for_remove = remove(list_remove);
    }


}
