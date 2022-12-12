// create,search and delete
#include <iostream>
using namespace std;

class Node
{
public:
    int Data;
    Node *Right, *Left;
    bool Rbit, Lbit;
};
class TBST
{
    Node *Root;

public:
    TBST()
    {
        Root = new Node;
        Root->Data = INT_MAX;
        Root->Left = Root->Right = Root;
        Root->Rbit = Root->Lbit = 0;
    }
    Node *Insert(int);
    void Search(int);
    void InorderDisplay();
};
Node *TBST ::Insert(int key)
{
    if (Root->Right == Root && Root->Left == Root)
    {
        Node *p = new Node;
        p->Data = key;
        p->Right = p->Left = Root;
        Root->Left = p;
        Root->Lbit = 1;
        p->Rbit = p->Lbit = 0;
        return Root;
    }
    Node *curr = new Node;
    Node *p = new Node;
    curr = Root->Left;
    while (1)
    {
        if (curr->Data < key)
        {
            if (curr->Rbit == 0)
            {
                p->Data = key;
                p->Right = curr->Right;
                p->Left = curr;
                p->Rbit = p->Lbit = 0;
                curr->Right = p;
                curr->Rbit = 1;
                return Root;
            }
            else
                curr = curr->Right;
        }
        else
        {
            if (curr->Lbit == 0)
            {
                p->Data = key;
                p->Right = curr;
                p->Left = curr->Left;
                p->Rbit = p->Lbit = 0;
                curr->Left = p;
                curr->Lbit = 1;
                return Root;
            }
            else
                curr = curr->Left;
        }
    }
}
void TBST ::InorderDisplay()
{
    Node *curr = Root->Left;

    while (curr->Lbit == 1)
    {
        curr = curr->Left; // reach to leftmost node
    }
    while (curr != Root) // the rightmost node marks the end of transversal
    {                    // hence it points back to root
        cout << " " << curr->Data;
        if (curr->Rbit == 1) // if the node has a child
        {
            curr = curr->Right;
            while (curr->Lbit == 1) // move leftmost of that node
            {
                curr = curr->Left;
            }
        }
        else
        {
            curr = curr->Right;
        }
    }
}
void TBST ::Search(int key)
{
    Node *curr = Root->Left;

    while (curr->Lbit == 1)
    {
        curr = curr->Left;
    }

    while (curr != Root)
    {
        if (curr->Data == key)
        {
            cout << endl
                 << "The Element found" << endl;
            return;
        }
        if (curr->Rbit == 1)
        {
            curr = curr->Right;
            while (curr->Lbit == 1)
            {
                curr = curr->Left;
            }
        }
        else
        {
            curr = curr->Right;
        }
    }
    cout << endl
         << "The element not found" << endl;
    return;
}
int main()
{
    TBST tree1;
    int data;
    char choice;
    cout << endl
         << "Enter the 1st Data" << endl;
    while (1)
    {
        cin >> data;
        tree1.Insert(data);
        cout << "Do you want to continue?(y/n)" << endl;
        cin >> choice;
        if (choice == 'y')
            cout << "Enter the data - ";
        else
            break;
    }
    while (1)
    {
        cout << endl
             << "Enter" << endl
             << "'1' to display inorder sequence" << endl
             << "'2' to search for an element" << endl
             << "'3' to exit" << endl;
        cin >> choice;
        if (choice == '2')
        {
            cout << "Enter the element you want to search" << endl;
            cin >> data;
            tree1.Search(data);
        }
        if (choice == '3')
            break;
        if (choice == '1')
        {
            cout << "The inorder transversal of the TBST is- " << endl;
            tree1.InorderDisplay();
            ;
        }
    }

    return 0;
}
