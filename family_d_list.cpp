#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
// making a class node to that will store elements on node with pointers
class node
{
public:
    string name;
    int age;
    node *next; // next pointer pointing twards next element
    node *prev; // previous pointer pointing towards prev elemnts/node

    node(string n, int a) // constructor- create a basic node
    {
        name = n;
        age = a;
        next = NULL;
        prev = NULL;
    }
};
// function that will add family member details in the node and add the node in the linked list
void insertFamilyMembers(node *&head, string n, int a)
{
    node *nd = new node(n, a);
    if (head == NULL)
    {
        head = nd;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nd;
    nd->prev = temp;
}
// function that will display all the elements value in linked list
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->name << "\t" << temp->age << endl;
        temp = temp->next;
    }
}
int main()
{
    node *head = NULL;
    string name;
    int age;
    char a = 'y';
    while ((a == 'y') || (a == 'Y')) // loop that will ask you everytime if you want to enter another member
    {
        cout << "Enter name of the family member:" << endl;
        // cin not used bcoz spaces in name is not accepted
        getline(cin >> ws, name); // as getline function cant be used in loops we use this code to remove excess whitespaces
        cout << "Enter age of the family member:" << endl;
        cin >> age;
        insertFamilyMembers(head, name, age);
        cout << "do you want to enter another member details (ans in y/n only):" << endl;
        cin >> a;
    }
    display(head);
}