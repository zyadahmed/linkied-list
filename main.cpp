#include <iostream>
#include "Linkiedlist.h"
#include <string>
using namespace std;
void choices(){
    cout << "Menu:" << endl;
    cout << "1. Add an element to the list" << endl;
    cout << "2. Remove an element from the list" << endl;
    cout << "3. Print the contents of the list" << endl;
    cout << "4. Compare the list with another list" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}
int main() {
    Linkiedlist<int> myList;
    int choice, value, compareValue;
    Linkiedlist<int> otherList;
    bool isEqual;

    do {
        choices();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to be added: ";
                cin >> value;
                myList.Add(value);
                break;
            case 2:
                cout << "Enter the value to be removed: ";
                cin >> value;
                myList.remove(value);
                break;
            case 3:
                cout << "The contents of the list are: ";
                myList.printAll();
                break;
            case 4:
                cout << "Enter the number of elements in the other list: ";
                cin >> compareValue;
                otherList = Linkiedlist<int>();
                for (int i = 0; i < compareValue; i++) {
                    cout << "Enter element " << i+1 << ": ";
                    cin >> value;
                    otherList.Add(value);
                }
                isEqual = (myList == otherList);
                if (isEqual) {
                    cout << "The two lists are equal" << endl;
                } else {
                    cout << "The two lists are not equal" << endl;
                }
                break;
            case 5:
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
