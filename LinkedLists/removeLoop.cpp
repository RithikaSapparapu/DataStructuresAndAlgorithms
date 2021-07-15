#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *removeLoop(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node *slow = head;
    node *fast = head;
    fast = fast->next->next;
    slow = slow->next;
    while (fast != NULL && fast->next != NULL)
    {
        if (fast == slow)
            break;
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast == slow)
    {
        //find the beginning of the loop and remove the loop!
        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL;
        return head;
    }
    else
        return head;
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
    //testing
    node *headnode = NULL;
    int n, p;
    n = 8;
    p = 5;
    for (int i = 0; i < n; i++)
    {
        insertEnd(&headnode, p);
        p = p + 3;
    }
    cout << "the list contains following elements:" << endl;
    displayList(headnode);
    headnode->next->next->next->next->next->next->next = headnode->next->next->next;
    headnode = removeLoop(headnode);
    cout << "list after removing the loop: ";
    displayList(headnode);
}