#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;
#define MAX 999

class Graph
{
    int vertices;
    set<int> AllVertices;
    int MinWeight = 0;
    vector<vector<int>> matrix;

public:
    Graph(int vertices)
    {
        this->vertices = vertices;
        vector<int> v(vertices, MAX);
        for (int i = 0; i < vertices; i++)
            matrix.push_back(v);
    }
    void AddEdge(int v1, int v2, int weight)
    {
        matrix[v1][v2] = matrix[v2][v1] = weight;
        AllVertices.insert(v1);
        AllVertices.insert(v2);
    }
    void MinSpanTree(int v1)
    {
        set<int> set1;
        multimap<int, int> map1;
        set<int> allvertices(AllVertices);
        set1.insert(v1);
        allvertices.erase(v1);

        while (allvertices.size() != 0)
        {
            // cout << "hi" << endl;
            int min = MAX;
            int min_it, min_i;
            for (auto it = set1.begin(); it != set1.end(); it++)
                for (auto i = allvertices.begin(); i != allvertices.end(); i++)
                    if (min > matrix[*it][*i])
                    {
                        min = matrix[*it][*i];
                        min_it = *it;
                        min_i = *i;
                    }
            set1.insert(min_i);
            allvertices.erase(min_i);
            map1.insert(pair<int, int>(min_it, min_i));
            MinWeight = MinWeight + matrix[min_it][min_i];
        }
        cout << "the Minimum weight " << MinWeight << endl;
        for (auto i : map1)
        {
            cout << i.first << " " << i.second << endl;
        }
    }
};

int main()
{
    int total;
    cout << "Enter total no. of verteices" << endl;
    cin >> total;
    Graph g1(total + 1);
    int Vertex1, Vertex2, Weight;
    int choice;
    do
    {
        cout << "Enter\n'1' to add edge\n'2' to get minimum spanning tree\n'3' to exit" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter Vertex 1,Vertex2 and the weight of the edge :-  ";
            cin >> Vertex1 >> Vertex2 >> Weight;
            g1.AddEdge(Vertex1, Vertex2, Weight);
        }
        if (choice == 2)
        {
            cout << "Enter Any Vertex :- ";
            cin >> Vertex1;
            cout << "THe Minimum Spanning Tree" << endl;
            g1.MinSpanTree(Vertex1);
        }
    } while (choice != 3);
}
