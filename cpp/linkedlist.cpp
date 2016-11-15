#include<iostream>

using namespace std;

typedef struct Node {
    int data;
    Node *nextNode;
} Node;

class List
{
    public:
        List(Node *n = 0) : head(n) {}
        void addNode(int d);
        void print();
        void reverse_print(Node *);
        Node* getHead(){ return head; }

    private:
        Node *head;
};

void List::addNode(int d)
{
    if(head == 0){
        head = new Node;
        head->data = d;
        head->nextNode = 0;
        return ;
    }

    Node *ptr = head;
    while(ptr){
        if(ptr->nextNode == 0){
            ptr->nextNode = new Node;
            ptr->nextNode->data = d;
            ptr->nextNode->nextNode = 0;
            break;
        }
        ptr = ptr->nextNode;
    }
}

void List::print()
{
    Node *ptr = head;
    while(ptr){
        cout << ptr->data << " " ;
        ptr = ptr->nextNode;
    }
    cout << endl;
}

void List::reverse_print(Node *ptr)
{
    if(ptr == 0)
        return ;

    reverse_print(ptr->nextNode);
    cout << ptr->data << " ";
}

int main()
{
    List L = List();
    L.addNode(1);
    L.addNode(2);
    L.addNode(3);
    L.addNode(4);
    L.print();
    L.reverse_print(L.getHead());

    return 0;
}




