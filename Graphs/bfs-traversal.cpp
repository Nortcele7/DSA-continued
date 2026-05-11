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

        // BFS Traversal in graph
        void bfs()
        {
            queue<int> q1;

            //bool arr[g1.V] = {false};

            vector<bool> arr(V, false);

            q1.push(0);
            arr[0] = true;

            while(q1.size()>0)
            {
                int u = q1.front();
                q1.pop();
                cout<<u<<" ";

                for(int v: l[u])
                {
                    if(!arr[v])
                    {
                        arr[v] = true;
                        q1.push(v);
                    }
                }

            }

        }


        
};




int main()
{
    Graph g1(5);

    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(1,3);
    g1.addEdge(2,4);
    g1.addEdge(3,2);

    g1.printGraph();

    g1.bfs();
    
 
}