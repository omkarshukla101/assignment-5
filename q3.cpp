#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }
    }
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void display() const {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void printMiddle() const {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        int length = 0;
        Node* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }
        int midIndex = length / 2; 
        temp = head;
        for (int i = 0; i < midIndex; i++)
            temp = temp->next;

        cout << "Middle element: " << temp->data << endl;
    }
};

int main() {
    LinkedList list;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insert(val);
    }

    cout << "\nLinked List: ";
    list.display();

    list.printMiddle();

    return 0;
}
