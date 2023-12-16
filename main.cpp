#include <crtdbg.h>
#include <iostream>
#include <random>
#include <time.h>


using namespace std;

class SingleLinkedList {

public:
    struct Node {
        char data;

        Node *nextNode;

        Node(char val = NULL): data(val),nextNode(nullptr){}

        ~Node(){
            delete nextNode;
        }
    };

    bool PalindromeCheck(SingleLinkedList reversedList)
    {
        Node *curr = head;
        Node *curr2 = reversedList.head;
        while(curr != nullptr && curr2 != nullptr)
        {
            if(curr->data == curr2->data)
            {
                curr = curr->nextNode;
                curr2 = curr2->nextNode;
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    SingleLinkedList():head(nullptr){}
    Node* head;

    void add(char val){

        Node* new_node = new Node(val);

        if(head == nullptr)
        {
            head = new_node;
        }
        else
        {
            new_node->nextNode = head;
            head = new_node;
        }
    }


    void delete_back() {
        if (head == nullptr) {
            cout << "\nThe list is empty, so there is nothing to remove. Feel free to add something!";
            return;
        }
        if (head->nextNode == nullptr) {
            head = nullptr;
            return;
        }

        Node *temp = head;
        Node *templag = head;
        while(temp->nextNode != nullptr){
            templag = temp;
            temp = temp->nextNode;
        }

        templag->nextNode = nullptr;
        delete temp;
    }

    void PopChar(SingleLinkedList* reverse){
        Node *curr = head;
        while(curr != nullptr) { // TODO
            reverse->add(curr->data);
            curr = curr->nextNode;
        }

    }

};

int main() {
    SingleLinkedList linkedList;
    SingleLinkedList linkedList2;

    char Palindrome1[7] = {'r','a','c','e','c','a','r'};
    char Palindrome2[3] = { 'p','o','p'};
    char notPalindrome[4] = {'w','o','r','d'};

    for( char i : Palindrome1)
    {
        linkedList.add(i);
    }
    linkedList.PopChar(&linkedList2);
    cout<< "\nare the characters a palindrome?" << linkedList.PalindromeCheck(linkedList2);
    for( char i : Palindrome1) {
        linkedList.delete_back();
        linkedList2.delete_back();
    }


    for( char i : Palindrome2)
    {
        linkedList.add(i);
    }
    linkedList.PopChar(&linkedList2);
    cout<< "\nare the characters a palindrome?" << linkedList.PalindromeCheck(linkedList2);
    for( char i : Palindrome2) {
        linkedList.delete_back();
        linkedList2.delete_back();
    }

    for( char i : notPalindrome)
    {
        linkedList.add(i);
    }
    linkedList.PopChar(&linkedList2);
    cout<< "\nare the characters a palindrome?" << linkedList.PalindromeCheck(linkedList2);
    for( char i : notPalindrome) {
        linkedList.delete_back();
        linkedList2.delete_back();
    }
    string userin;
    do
    {
        cout<< "\nenter a word and this program will tell you if it is a palindrome. 0 to quit.";
        userin ="";
        cin >> userin;
        for (char i : userin){
            linkedList.add(i);
        }
        linkedList.PopChar(&linkedList2);
        cout<< "\nare the characters a palindrome?" << linkedList.PalindromeCheck(linkedList2);
        for( char i : userin) {
            linkedList.delete_back();
            linkedList2.delete_back();
        }
    }while (userin != "0");

}
