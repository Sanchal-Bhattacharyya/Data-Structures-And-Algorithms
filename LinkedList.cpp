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

void insertAtHead(Node* &head,int val)
{
    Node* curr = new Node(val);
    
    if(head==NULL)
    {
        head = curr;
        return;
    }

    curr->next = head;
    head = curr;

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

Node* reverseLinkedList(Node* &head)
{
    Node *prev = NULL;
    Node* curr = head;

    while(curr!=NULL)
    {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int middleLinkedList(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL &&  fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

Node* mergeLinkedList(Node* l1,Node* l2)
{
    Node* dummyNode = new Node(-1);
    Node* ptr1 = l1;
    Node* ptr2 = l2;
    Node* ptr3 = dummyNode;

    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->data<ptr2->data)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next; 
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    while(ptr1!=NULL)
    {
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
    while(ptr2!=NULL)
    {
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }
    return dummyNode->next;
}

Node* removeNodefromBack(Node* head,int n)
{
    Node* dummyNode = new Node(-1);
    dummyNode->next = head;
    Node* slow = dummyNode;
    Node* fast = dummyNode;

    for(int i=1;i<=n;i++)
    fast = fast->next;

    while(fast->next!=NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    Node* temp = NULL;
    temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return dummyNode->next;

}

Node* findIntersecetionNode(Node* head1,Node* head2)
{
    if(head1 == NULL || head2 == NULL) return NULL;

    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while(ptr1!=ptr2)
    {
        ptr1 = ptr1 == NULL? head2:ptr1->next;
        ptr2 = ptr2 == NULL? head1:ptr2->next;
    }
    
    return ptr1; 

}

bool detectCycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    
    while(fast->next!= NULL && fast->next->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        return true;
    }
    return false;
}

bool isPalindrome(Node* head)
{
    if(head==NULL||head->next==NULL)
    return true;

    //find the middle of linked list

    Node* slow = NULL;
    Node* fast = NULL;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    //reverse right half
    slow->next = reverseLinkedList(slow->next);

    //move slow to the right half
    slow = slow->next;

    while(slow!=NULL)
    {
        if(head->data!=slow->data)
        return false;

        slow = slow->next;
        head = head->next;
    }

    return true;
}

int main()
{
    Node* head = new Node(1);
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtTail(head,7);
    insertAtTail(head,9);
    
    Node* head2 = new Node(2);
    insertAtTail(head2,4);
    insertAtTail(head2,6);
    insertAtTail(head2,8);
    insertAtTail(head2,10);

    Node* ans = mergeLinkedList(head,head2);
    //insertAtHead(head,7);
    //Node* newHead = reverseLinkedList(head);
    printLinkedList(ans);
    //cout << middleLinkedList(ans);
    //printLinkedList(head);
    return 0;
}