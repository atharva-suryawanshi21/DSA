#include <iostream>
using namespace std;
class TreeNode
{
public:
    int Data;
    TreeNode *Lchild, *Rchild;
};
class StackClass
{
    TreeNode *stack[20];
    int top = -1;

public:
    void push(TreeNode *c)
    {
        top++;
        stack[top] = c;
    }
    TreeNode *pop()
    {
        return stack[top--];
    }
    TreeNode *GetTop()
    {
        if (top != -1)
            return stack[top];
        else
            return NULL;
    }
    int IsEmpty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }
};
class Tree
{
    TreeNode *Root;

public:
    TreeNode *GetRoot() { return Root; }
    Tree() { Root = NULL; }
    Tree(TreeNode *Base) { Root = Base; }
    void InsertNode(int);
    TreeNode *Search(int);
    void Inorder();
    TreeNode *DeleteNode(TreeNode *, int);
};
TreeNode *Tree ::DeleteNode(TreeNode *Root, int Key)
{
    TreeNode *prev = NULL;
    TreeNode *curr = Root;

    while (curr != NULL && curr->Data != Key)
    {
        prev = curr;
        if (curr->Data > Key)
            curr = curr->Lchild;
        else
            curr = curr->Rchild;
    }
    if (curr == NULL)
    {
        cout << "Key Not Found" << endl;
        return Root;
    }
    if (curr->Lchild == NULL || curr->Rchild == NULL)
    {
        TreeNode *NewCurr;
        if (curr->Lchild == NULL)
            NewCurr = curr->Rchild;
        else
            NewCurr = curr->Lchild;

        if (prev == NULL)
            return NewCurr;

        if (curr == prev->Rchild)
            prev->Rchild = NewCurr;
        else
            prev->Lchild = NewCurr;
        free(curr);
    }
    else
    {
        TreeNode *p = NULL, *temp;
        temp = curr->Rchild;
        while (temp->Lchild != NULL)
        {
            p = temp;
            temp = temp->Lchild;
        }
        if (p != NULL)
        {
            p->Lchild = temp->Rchild;
        }
        else
            curr->Rchild = temp->Rchild;
        curr->Data = temp->Data;
        free(temp);
    }

    return Root;
}
void Tree ::Inorder()
{
    TreeNode *temp = Root;
    StackClass S;
    int flag = 1;
    while (flag)
    {
        if (temp != NULL)
        {
            S.push(temp);
            temp = temp->Lchild;
        }
        else
        {
            if (S.IsEmpty())
                flag = 0;
            else
            {
                temp = S.pop();
                cout << temp->Data << " ";
                temp = temp->Rchild;
            }
        }
    }
}
void Tree ::InsertNode(int Key)
{

    TreeNode *Tmp, *NewNode;
    NewNode = new TreeNode;
    NewNode->Data = Key;
    NewNode->Lchild = NewNode->Rchild = NULL;
    if (Root == NULL)
    {
        Root = NewNode;
    }
    else
    {
        Tmp = Root;
        while (Tmp != NULL)
        {
            if (Tmp->Data > Key)
            {

                if (Tmp->Lchild == NULL)
                {
                    Tmp->Lchild = NewNode;
                    break;
                }
                Tmp = Tmp->Lchild;
            }
            else
            {

                if (Tmp->Rchild == NULL)
                {
                    Tmp->Rchild = NewNode;
                    break;
                }
                Tmp = Tmp->Rchild;
            }
        }
    }
}

TreeNode *Tree ::Search(int Key)
{
    TreeNode *temp = Root;
    while (temp != NULL)
    {
        if (temp->Data == Key)
            return temp;
        if (temp->Data > Key)
            temp = temp->Lchild;
        else
            temp = temp->Rchild;
    }
    return NULL;
}
int main()
{
    Tree t1;
    int choice, i = 1, key, KeyDelete;
    char choice2;
    while (1)
    {
        cout << "Select the operation:- " << endl
             << "'1' to create and insert node " << endl
             << "'2' to delete a node" << endl
             << "'3' to display the node " << endl
             << "'4' to end" << endl;
        cin >> choice;
        if (choice == 1)
        {
            while (1)
            {
                cout << "Enter the element " << i++ << endl;
                cin >> key;
                t1.InsertNode(key);
                cout << "Do you wish to continue (y/n)" << endl;
                cin >> choice2;
                if (choice2 == 'n')
                    break;
            }
        }
        if (choice == 2)
        {
            while (1)
            {
                cout << "Enter the element to delete" << endl;
                cin >> KeyDelete;
                t1 = t1.DeleteNode(t1.GetRoot(), KeyDelete);
                cout << "Do you wish to continue (y/n)" << endl;
                cin >> choice2;
                if (choice2 == 'n')
                    break;
            }
        }
        if (choice == 3)
        {
            cout << "The inorder sequence of the tree is:- " << endl;
            t1.Inorder();
            break;
        }
        if (choice == 4)
            break;
        if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
            cout << "Please enter valid number" << endl
                 << endl;
    }
}
