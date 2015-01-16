// StringOperations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
typedef struct Node{
    int val_;
    Node* next_;
} *Node_ptr;

struct LinkedList{
    Node* head;
    int count;
};
Node* ReverseList(Node*& p, int k)
{
    Node* next = nullptr;
    Node* previous = p;
    p = p->next_;

    previous->next_ = nullptr;

    while (k > 1 && p != nullptr)
    {
        next = p->next_;
        p->next_ = previous;
        previous = p;
        p = next;
        k--;
    }
    return previous;
}

Node* K_ReverseList(Node* p, int n, int k)
{
    Node* q = p;
    Node* h = ReverseList(p, k);
    q->next_ = ReverseList(p, n - k);
    return h;
}

void PrintList(Node* p)
{
    while (p != nullptr)
    {
        cout << p->val_ << " ";
        p = p->next_;
    }
    cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
    Node* p = new Node;
    p->val_ = 1;
    Node* q = p;
    for (int i = 1; i < 6; i++)
    {
        q->next_ = new Node;
        q = q->next_;
        q->val_ = i + 1;
        q->next_ = nullptr;
    }

    PrintList(p);
    p = K_ReverseList(p, 6, 2);
    PrintList(p);
	return 0;
}

