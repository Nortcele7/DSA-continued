#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<utility>
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

        bool detectCycle(int src, vector<bool>& vis)
        {
            queue<pair<int, int>> q;
            
            q.push({src, -1});

            vis[src] = true;

            while(q.size()>0)
            {
                int u = q.front().first;
                int par = q.front().second;

                q.pop();    

                for(int v: l[u])
                {
                    if(!vis[v])
                    {
                        q.push({v, u});
                        vis[v] = true;
                    }
                    else if(v!=par)
                    {
                        return true;
                    }
                }

            }

            return false;

        }

        bool isCycle()
        {
            vector<bool> vis(V, false);

            for(int i=0; i<V; i++)
            {
                if(!vis[i])
                {
                    if(detectCycle(i, vis))
                    {
                        return true;
                    }
                }
            }

            return false;

        }


        
};




int main()
{
    Graph g1(5);

    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(1,3);
    g1.addEdge(2,3);
    g1.addEdge(3,4);

    g1.printGraph();

    g1.bfs();

    cout<<endl;

    cout<<g1.isCycle();
    
 
}