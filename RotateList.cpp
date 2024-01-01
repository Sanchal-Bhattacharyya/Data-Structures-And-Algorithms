#include <iostream>
using namespace std;

class Node
{
    public:
    
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node* &head,int val)
{
    Node* curr = new Node(val);
    
    if(head==NULL)
    {
        head = curr;
        return;
    }
    
    Node* ptr = head;
    
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = curr;
}

void printLinkedList(Node* head)
{
    Node* ptr = head;
    while(ptr!=NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << "\n";
}

Node* rotateList(Node* &head,int k)
{
    //edge cases
    if(!head || !head->next || k==0) return head;

    //compute length
    Node* ptr = head;
    int len = 1;
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
        len++;
    }

    //traverse till that Node
    ptr->next = head;
    k = k%len;
    k = len - k;
    while(k--) ptr = ptr->next;

    //break the connection
    head = ptr->next;
    ptr->next = NULL;

    return head;

}
int main()
{
    Node* head = new Node(1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);

    printLinkedList(rotateList(head,2));

    return 0;

}