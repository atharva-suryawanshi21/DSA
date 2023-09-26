#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <iterator>
using namespace std;
class Graph
{
    int Vertices;
    list<int> *AdjacencyList;

public:
    Graph(int A)
    {
        Vertices = A;
        AdjacencyList = new list<int>[Vertices];
    }
    void AddEdge(int A, int B)
    {
        AdjacencyList[A].push_back(B);
    }
    void DFS(int Start)
    {
        stack<int> Stack;
        vector<bool> visited(Vertices, 0);
        list<int>::iterator it;
        int s;

        Stack.push(Start);
        while (!Stack.empty())
        {

            s = Stack.top();
            Stack.pop();
            if (visited[s] == 0)
            {
                cout << s << " ";
                visited[s] = 1;
            }
            for (it = AdjacencyList[s].begin(); it != AdjacencyList[s].end(); it++)
                if (visited[*it] == 0)
                    Stack.push(*it);
        }
    }
    void BFS(int Start)
    {
        queue<int> Queue;
        vector<bool> visited(Vertices, 0);
        list<int>::iterator it;
        int s;

        Queue.push(Start);
        while (!Queue.empty())
        {
            s = Queue.front();
            Queue.pop();
            if (visited[s] == 0)
            {
                cout << s << " ";
                visited[s] = 1;
            }
            for (it = AdjacencyList[s].begin(); it != AdjacencyList[s].end(); it++)
                if (visited[*it] == 0)
                    Queue.push(*it);
        }
    }
};
int main()
{
    cout << "Enter the number of vertices in the graph" << endl;
    int Vertices;
    cin >> Vertices;
    Graph G1(Vertices + 1);
    int V1, V2, Choice = 0, inChoice = 1;

    while (Choice != 3)
    {
        cout << "\n\nEnter" << endl
             << "'1' to Add an edge" << endl
             << "'2' to get DFS and BFS transversal " << endl
             << "'3' to end " << endl;
        cin >> Choice;
        if (Choice == 1)
        {
            while (inChoice == 1)
            {
                cout << " Enter Vertex 1 and Vertex 2" << endl;
                cin >> V1 >> V2;
                G1.AddEdge(V1, V2);
                cout << "Do you want to continue? (Yes-1/No-0) ";
                cin >> inChoice;
            }
        }
        if (Choice == 2)
        {
            cout << "Enter the Initial Vertex - ";
            cin >> V1;
            cout << "\nThe BFS Transversal - ";
            G1.BFS(V1);
            cout << "\nThe DFS Transversal - ";
            G1.DFS(V1);
        }
        inChoice = 1;
    }
}
