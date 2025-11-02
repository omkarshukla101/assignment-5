#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int value){data=value; next=nullptr;}
};
class LinkedList{
private:
    Node* head;
public:
    LinkedList(){head=nullptr;}
    void insert(int value){
        Node* newNode=new Node(value);
        if(!head){head=newNode; return;}
        Node* current=head;
        while(current->next) current=current->next;
        current->next=newNode;
    }
    void display() const{
        if(!head){cout<<"List is empty.\n"; return;}
        Node* current=head;
        while(current){cout<<current->data<<" "; current=current->next;}
        cout<<endl;
    }
    void reverse(){
        Node* previous=nullptr;
        Node* current=head;
        Node* nextNode=nullptr;
        while(current){
            nextNode=current->next;
            current->next=previous;
            previous=current;
            current=nextNode;
        }
        head=previous;
    }
};
int main(){
    LinkedList list;
    int numberOfNodes, value;
    cout<<"Enter number of nodes: ";
    cin>>numberOfNodes;
    cout<<"Enter "<<numberOfNodes<<" elements:\n";
    for(int i=0;i<numberOfNodes;i++){cin>>value; list.insert(value);}
    cout<<"\nOriginal Linked List: ";
    list.display();
    list.reverse();
    cout<<"Reversed Linked List: ";
    list.display();
    return 0;
}
