#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph
{
    public:
        int V;
        list<int> *l;

        Graph(int V)
        {
            this->V = V;
            l = new list<int>[V];
        }

        void addEdge(int u, int v)
        {
            l[u].push_back(v);
            l[v].push_back(u);
        }

        void printGraph()
        {
            for(int i=0; i<V; i++)
            {
                cout<<i<<":";
                for(int neighbour: l[i])
                {
                    cout<<neighbour<<" ";
                }
                cout<<endl;
            }
        }

        void dfsHelper(int u, vector<bool>& arr)
        {
            cout<<u<<" ";
            arr[u] = true;

            for(int v:l[u])
            {
                if(!arr[v])
                {
                    dfsHelper(v, arr);
                }
            }
        }

        void dfs()
        {
            int src = 0;

            vector<bool> arr(V,false);

            for(int i=0; i<V; i++)
            {
                if(!arr[i])
                {
                    dfsHelper(i,arr);
                }
            }
            cout<<endl;
        }


        
};

int main()
{
    Graph g1(5);

    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(3,4);

    g1.printGraph();

    vector<bool> arr(g1.V, false);

    g1.dfs();
}