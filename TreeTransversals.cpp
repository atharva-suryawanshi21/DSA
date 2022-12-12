#include <iostream>
using namespace std;
class TreeNode
{
public:
    char Data;
    TreeNode *Right;
    TreeNode *Left;
    TreeNode(char data)
    {
        Data = data;
        Right = Left = NULL;
    }
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
void preorder(TreeNode *root)
{
    StackClass s;
    int flag = 1;
    TreeNode *temp = root;
    while (flag)
    {
        if (temp != NULL)
        {
            cout << temp->Data << " ";
            s.push(temp);
            temp = temp->Left;
        }
        else
        {
            if (s.IsEmpty() == 0)
            {
                temp = s.pop();
                temp = temp->Right;
            }
            else
                flag = 0;
        }
    }
}
void inorder(TreeNode *root)
{
    int flag = 1;
    TreeNode *temp = root;
    StackClass s;
    while (flag)
    {
        if (temp != NULL)
        {
            s.push(temp);
            temp = temp->Left;
        }
        else
        {
            if (s.IsEmpty() == 0)
            {
                temp = s.pop();
                cout << temp->Data << " ";
                temp = temp->Right;
            }
            else
                flag = 0;
        }
    }
}
void postorder(TreeNode *root)
{
    StackClass s1, s2;
    TreeNode *temp, *PopedNode;

    s1.push(root);
    while (s1.IsEmpty() == 0)
    {
        PopedNode = s1.pop();
        s2.push(PopedNode);
        if (PopedNode->Left != NULL)
            s1.push(PopedNode->Left);
        if (PopedNode->Right != NULL)
            s1.push(PopedNode->Right);
        }
    while (s2.IsEmpty() == 0)
    {
        temp = s2.pop();
        cout << temp->Data << " ";
    }
}
int main()
{                                                        //                      +
    TreeNode *Root = new TreeNode('+');                  //                    /   /
    Root->Left = new TreeNode('*');                      //                  *       E
    Root->Right = new TreeNode('E');                     //                /  /
    (Root->Left)->Left = new TreeNode('/');              //             /      D
    (Root->Left)->Right = new TreeNode('D');             //           /  /
    (Root->Left)->Left->Left = new TreeNode('A');        //         A     ^
    (Root->Left)->Left->Right = new TreeNode('^');       //              /  /
    (Root->Left)->Left->Right->Left = new TreeNode('B'); //             B    C
    (Root->Left)->Left->Right->Right = new TreeNode('C');
    preorder(Root);
    cout << endl;
    inorder(Root);
    cout << endl;
    postorder(Root);
}
