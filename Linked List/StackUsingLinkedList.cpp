#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class stack
{
    Node *top;
    int size;

public:
    stack()
    {
        top = NULL;
        size = 0;
    }
    int StackSize() { cout << "The size of the stack is " << size << endl; }
    int IsEmpty();
    void push(int);
    int pop();
    int GetTop();
    void display();
};
int stack ::IsEmpty()
{
    return (top == NULL) ? 1 : 0;
}
void stack ::push(int element)
{
    Node *NewNode;
    NewNode = new Node;
    size++;
    if (top == NULL)
    {
        NewNode->data = element;
        NewNode->next = NULL;
        top = NewNode;
    }
    else
    {
        NewNode->data = element;
        NewNode->next = top;
        top = NewNode;
    }
}
int stack ::pop()
{
    Node *temp;
    temp = top;
    int PopData;
    if (IsEmpty())
    {
        cout << "stack underflow";
        return 0;
    }
    else
    {
        PopData = top->data;
        top = top->next;
        delete temp;
        return PopData;
    }
}
int stack ::GetTop()
{
    if (!IsEmpty())
        return top->data;
    else
        return 0;
}
void stack ::display()
{
    cout << "The stack is - " << endl;
    while (top != NULL)
    {
        cout << top->data << endl;
        top = top->next;
    }
}
int main()
{
    stack l1;
    l1.push(3);
    l1.push(4);
    l1.push(5);
    cout << l1.pop() << endl;
    l1.push(6);
    cout << "The top data - " << l1.GetTop() << endl;
    l1.display();
    return 0;
}
