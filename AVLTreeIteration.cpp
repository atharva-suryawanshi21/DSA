#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int Data;
    Node *Right, *Left;
    int Height;
};
class AVLTree
{
    Node *Root = NULL;

public:
    Node *Insert(Node *, int);
    Node *GetRoot()
    {
        return Root;
    }
    void Inorder();
    void UpdateRoot(Node *NewRoot)
    {
        Root = NewRoot;
    }
    void Preorder();
};
void AVLTree ::Preorder()
{
    Node *temp = Root;
    int Flag = 1;
    stack<Node *> a;
    while (Flag)
    {
        if (temp != NULL)
        {
            cout << temp->Data << " ";
            a.push(temp);
            temp = temp->Left;
        }
        else
        {
            if (a.empty() == 0)
            {
                temp = a.top();
                a.pop();
                temp = temp->Right;
            }
            else
                Flag = 0;
        }
    }
}
Node *GetNode(int key)
{
    Node *NewNode = new Node;
    NewNode->Data = key;
    NewNode->Right = NewNode->Left = NULL;
    NewNode->Height = 1;
    return NewNode;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int height(Node *N)
{
    if (N == NULL)
        return 0;
    else
        return N->Height;
}
int GetBalance(Node *temp)
{
    if (temp == NULL)
        return 0;
    else
        return (height(temp->Left) - height(temp->Right));
}
Node *RightRotate(Node *x)
{
    Node *y = x->Left;
    Node *t = y->Right;
    y->Right = x;
    x->Left = t;
    x->Height = 1 + max(height(x->Left), height(x->Right));
    y->Height = 1 + max(height(y->Left), height(y->Right));
    return y;
}
Node *LeftRotate(Node *x)
{
    Node *y = x->Right;
    Node *t = y->Left;
    y->Left = x;
    x->Right = t;
    x->Height = 1 + max(height(x->Left), height(x->Right));
    y->Height = 1 + max(height(y->Left), height(y->Right));
    return y;
}
Node *AVLTree ::Insert(Node *temp, int key)
{
    if (temp == NULL)
        return GetNode(key);
    if (key < temp->Data)
        temp->Left = Insert(temp->Left, key);
    else
        temp->Right = Insert(temp->Right, key);

    temp->Height = 1 + max(height(temp->Left), height(temp->Right));

    int balance = GetBalance(temp);
    if (balance > 1 && key < temp->Left->Data)
        return RightRotate(temp);
    if (balance > 1 && key > temp->Left->Data)
    {
        temp->Left = LeftRotate(temp->Left);
        return RightRotate(temp);
    }
    if (balance < -1 && temp->Right->Data < key)
        return LeftRotate(temp);
    if (balance < -1 && temp->Right->Data > key)
    {
        temp->Right = RightRotate(temp->Right);
        return LeftRotate(temp);
    }

    return temp;
}
void AVLTree ::Inorder()
{
    Node *temp = Root;
    int Flag = 1;
    stack<Node *> a;
    while (Flag)
    {
        if (temp != NULL)
        {
            a.push(temp);
            temp = temp->Left;
        }
        else
        {
            if (a.empty() == 0)
            {
                temp = a.top();
                a.pop();
                cout << temp->Data << " ";
                temp = temp->Right;
            }
            else
                Flag = 0;
        }
    }
}
int main()
{
    AVLTree Tree1;
    int choice;
    int Data;
    while (1)
    {
        cout << endl
             << "Press" << endl
             << "'1' to Insert an Element in the tree" << endl
             << "'2' to Display inorder sequence of the tree" << endl
             << "'3' to Display Preorder Sequence of the tree" << endl
             << "'4' to quit" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the element" << endl;
            cin >> Data;
            Tree1.UpdateRoot(Tree1.Insert(Tree1.GetRoot(), Data));
        }
        else if (choice == 2)
        {
            cout << "The Inorder Sequence of the tree is :- " << endl;
            Tree1.Inorder();
        }
        else if (choice == 3)
        {
            cout << "The Preorder Sequence of the tree is :- " << endl;
            Tree1.Preorder();
        }
        else
            break;
    }
}
