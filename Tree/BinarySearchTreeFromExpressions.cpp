#include <iostream>
#include <cstring>

using namespace std;

class TreeNode
{
public:
    char Data;
    TreeNode *Left;
    TreeNode *Right;
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
TreeNode *Create(char preorder[], char inorder[], int N)
{

    if (strlen(preorder) == 0)
        return NULL;

    TreeNode *temp = new TreeNode;
    temp->Data = preorder[0];

    char in1[N], in2[N], pre1[N], pre2[N];
    int i = 0, j = 0, k = 0;
    for (i = 0; inorder[i] != preorder[0];)
        in1[i++] = inorder[i];
    for (j = i + 1; inorder[j] != '\0';)
        in2[k++] = inorder[j++];
    in1[i] = in2[k] = '\0';
    i = j = k = 0;
    for (k = 1; preorder[k] != '\0'; k++)
    {
        if (strchr(in1, preorder[k]) != NULL)
            pre1[i++] = preorder[k];
        else
            pre2[j++] = preorder[k];
    }
    pre1[i] = pre2[j] = '\0';
    temp->Left = Create(pre1, in1, N);
    temp->Right = Create(pre2, in2, N);
    return temp;
}

int CountNode(TreeNode *Root)
{
    if (Root == NULL)
    {
        return 0;
    }
    else
        return (1 + CountNode(Root->Left) + CountNode(Root->Right));
}
int CountLeaf(TreeNode *Root)
{
    if (Root == NULL)
        return 0;
    if (Root->Left == NULL && Root->Right == NULL)
        return 1;
    return (CountLeaf(Root->Left) + CountLeaf(Root->Right));
}
int TreeHeight(TreeNode *Root)
{
    if (Root == NULL || (Root->Left == NULL && Root->Right == NULL))
        return 0;
    int HeightLeft, HeightRight;
    HeightLeft = TreeHeight(Root->Left);
    HeightRight = TreeHeight(Root->Right);
    if (HeightLeft > HeightRight)
        return (1 + HeightLeft);
    else
        return (1 + HeightRight);
}
int main()
{

    char Inorder[] = "DBHEAIFJCG";

    char Preorder[] = "ABDEHCFIJG";
    TreeNode *Root;
    Root = Create(Preorder, Inorder, 10);
    inorder(Root);
    cout << endl
         << CountNode(Root);
    cout << endl
         << CountLeaf(Root);
    cout << endl
         << TreeHeight(Root);
    return 0;
}
