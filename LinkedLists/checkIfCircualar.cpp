#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *reverseLLiterative(node *head)
{
    node *cur = head;
    node *prev = NULL;
    while (cur != NULL)
    {
        node *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}

bool checkifCircular(node *head)
{
    node *temp = head;
    if (head == NULL || head->next == NULL)
    {
        return false;
    }
    temp = temp->next;
    while (temp != head)
    {
        if (temp == NULL)
            return false;
        temp = temp->next;
    }
    return true;
}

void insertEnd(node **headref, int d)
{
    node *ptr = new node();
    ptr->data = d;
    ptr->next = NULL;

    if (*headref == NULL)
        *headref = ptr;

    else
    {
        node *temp = *headref;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

void displayList(node *head)
{
    node *ptr = head;
    if (head == NULL)
        cout << "List is empty" << endl;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    node *headnode = NULL;
    int n = 6;
    int p = 9;
    for (int i = 0; i < n; i++)
    {
        insertEnd(&headnode, p);
        p += 2;
    }
    //headnode->next->next->next->next->next->next = headnode;
    bool t = checkifCircular(headnode);
    cout << t;
}