#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

void removeDuplicatesFromSorted(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    node *cur = head;
    node *fut = head->next;
    while (fut != NULL)
    {
        if (cur->data == fut->data)
        {
            cur->next = fut->next;
            free(fut);
            fut = cur->next;
        }
        else
        {
            fut = fut->next;
            cur = cur->next;
        }
    }
    return;
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
    int n, p;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        insertEnd(&headnode, p);
    }
    removeDuplicatesFromSorted(headnode);
    displayList(headnode);
}