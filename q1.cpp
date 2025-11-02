#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
   Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList{
private:
    Node* head;
public:
    LinkedList(){
        head = NULL;
    }
int insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << val << " added at start\n";
        return 0;
    }
int insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
        } else {
            Node* temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << val << " added at end\n";
        return 0;
    }

    int insertBeforeAfter(int target, int val, string position) {
        if (head == NULL) {
            cout << "list empty\n";
            return 0;
        }

        Node* newNode = new Node(val);

        if(position == "before" && head->data == target){
            newNode->next = head;
            head = newNode;
            cout << val << " inserted before " << target << endl;
            return 0;
        }

        Node* temp = head;
        Node* prev = NULL;
        while(temp != NULL && temp->data != target){
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL){
            cout << "couldnt find node " << target << endl;
            delete newNode;
            return 0;
        }

        if(position == "before"){
            prev->next = newNode;
            newNode->next = temp;
        }
        else if(position == "after"){
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else{
            cout << "enter before or after properly\n";
            delete newNode;
        }
        return 0;
    }

    int deleteFromBeginning() {
        if (head == NULL) {
            cout << "list empty\n";
            return 0;
        }
        Node* temp = head;
        head = head->next;
        cout << "deleted " << temp->data << " from start\n";
        delete temp;
        return 0;
    }

    int deleteFromEnd() {
        if (head == NULL) {
            cout << "list empty\n";
            return 0;
        }
        if (head->next == NULL) {
            cout << "deleted " << head->data << endl;
            delete head;
            head = NULL;
            return 0;
        }

        Node* temp = head;
        while(temp->next->next != NULL)
            temp = temp->next;

        cout << "deleted " << temp->next->data << " from end\n";
        delete temp->next;
        temp->next = NULL;
        return 0;
    }

    int deleteSpecificNode(int key){
        if(head == NULL){
            cout << "list empty\n";
            return 0;
        }
        if(head->data == key){
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "deleted " << key << endl;
            return 0;
        }

        Node* temp = head;
        while(temp->next != NULL && temp->next->data != key)
            temp = temp->next;

        if(temp->next == NULL){
            cout << "no node with " << key << endl;
            return 0;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "deleted " << key << endl;
        return 0;
    }

    int search(int key){
        Node* temp = head;
        int pos = 1;
        while(temp != NULL){
            if(temp->data == key){
                cout << key << " found at position " << pos << endl;
                return 0;
            }
            temp = temp->next;
            pos++;
        }
        cout << key << " not found\n";
        return 0;
    }

    int display(){
        if(head == NULL){
            cout << "list empty\n";
            return 0;
        }
        Node* temp = head;
        cout << "list: ";
        while(temp != NULL){
            cout << temp->data;
            if(temp->next != NULL) cout << " -> ";
            temp = temp->next;
        }
        cout << " -> null\n";
        return 0;
    }
};

int main(){
    LinkedList list;
    int ch, val, target;
    string pos;

    cout << "linked list demo program\n";

    while(true){
        cout << "\n--- menu ---\n";
        cout << "1. insert at start\n";
        cout << "2. insert at end\n";
        cout << "3. insert before/after\n";
        cout << "4. delete from start\n";
        cout << "5. delete from end\n";
        cout << "6. delete specific node\n";
        cout << "7. search node\n";
        cout << "8. display\n";
        cout << "9. exit\n";
        cout << "enter choice: ";
        cin >> ch;

        switch(ch){
            case 1:
                cout << "enter value: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "enter value: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "enter target: ";
                cin >> target;
                cout << "enter value: ";
                cin >> val;
                cout << "before or after: ";
                cin >> pos;
                list.insertBeforeAfter(target, val, pos);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "enter value to delete: ";
                cin >> val;
                list.deleteSpecificNode(val);
                break;
            case 7:
                cout << "enter value to search: ";
                cin >> val;
                list.search(val);
                break;
            case 8:
                list.display();
                break;
            case 9:
                return 0;
            default:
                cout << "wrong input\n";
        }
    }
    return 0;
}
