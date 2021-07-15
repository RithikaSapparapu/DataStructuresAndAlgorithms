#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

////can also be solved using stack.
struct node *reverse(struct node *head, int k)
{
    node *t = head;
    node *prev = NULL;
    node *cur = head;
    node *temp;
    for (int i = 0; i < k; i++)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    t->next = cur;
    node *finalHead = prev;
    node *back;
    while (cur != NULL)
    {
        prev = t;
        t = cur;
        back = prev;
        for (int i = 0; i < k; i++)
        {
            if (cur == NULL)
            {
                break;
            }
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        t->next = cur;
        back->next = prev;
    }
    return finalHead;
}

void insertEnd(node **headref, int d)
{
    node *ptr = new node(d);

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
    int t;
    cin >> t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        insertEnd(&headnode, p);
    }
    headnode = reverse(headnode, t);
    displayList(headnode);
}
