#ifndef LINKIEDLIST_H
#define LINKIEDLIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
struct Node{
    T data;
    Node<T> * next;
};

template <class T>
class Linkiedlist {
public:
    Linkiedlist() {
        count = 0;
        head = nullptr;
    }

    Linkiedlist(const Linkiedlist<T> &otherLinkied) {
        if (this->head == otherLinkied.head)
            throw logic_error("Self-assigment Error!");
        else {
            head = nullptr;
            head = otherLinkied.head;
            count = 0;
            Node<T> * temp = head;
            Node<T> *otherTemp = otherLinkied.head;
            while (otherTemp != nullptr) {
                Node<T> * newNode = new Node<T>();
                newNode->data = otherTemp->data;
                newNode->next = nullptr;
                if (temp == nullptr) {
                    head = newNode;
                }
                else {
                    temp->next = newNode;
                }
                temp = newNode;
                otherTemp = otherTemp->next;
                count++;
            }
        }
    }

    void Add(const T &item) {
        Node<T> * temp = head;
        Node<T> * newNode = new Node<T>();
        newNode->data = item;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            count++;
        }
        else {
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void remove(const T &item) {
        Node<T>* previous;
        Node<T>* current;
        current = head;
        if (head == nullptr) {
            cout << "List is Empty !" << endl;
        }
        else {
            while (current != nullptr && current->data != item) {
                previous = current;
                current = current->next;
            }
            if (current == nullptr) {
                cout << "Element not found" << endl;
            }
            else {
                if (current == head) {
                    head = current->next;
                    delete current;
                }
                else {
                    previous->next = current->next;
                    delete current;
                }
            }
        }
    }

    void printAll() {
        Node<T> * temp;
        temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int getSize() const{
        return count;
    }

    bool operator==(const Linkiedlist<T> &otherList) {
        if (this->head == otherList.head) {
            throw logic_error("Self-assigment Error!");
        }
        else {
            Node<T> * temp = head;
            Node<T>* otherTemp = otherList.head;
            if (count == otherList.getSize()) {
                while (temp != nullptr) {
                    if (temp->data != otherTemp->data)
                    {
                        return   false;
                    }
                    temp = temp->next;
                    otherTemp = otherTemp->next;
                }
            }
            else {
                return false;
            }
            return true;
        }
    }


    ~Linkiedlist() {
        if (head != nullptr) {
            Node<T> * current, *temp;
            current = head;
            while (current != nullptr) {
                temp = current;
                current = current->next;
                delete temp;
            }
            head = nullptr;
            count = 0;
        }
    }

private:
    int count;
    Node<T> * head;
};

#endif // LINKIEDLIST_H