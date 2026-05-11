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

        bool dfs(int src, vector<bool>& vis, vector<bool> recPath)
        {
            vis[src] = true;
            recPath[src] = true;

            for(int v:l[src])
            {
                if(!vis[v])
                {
                    if(dfs(v,vis,recPath))
                    {
                        return true;
                    }
                }
                else if(recPath[v])
                {
                    return true;
                }
            }
            recPath[src] = false;
            return false;
        }

        bool isCycle()
        {

            
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis, recPath))
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
    Graph g1(4);

    g1.addEdge(1,0);
    g1.addEdge(0,2);
    g1.addEdge(2,3);

    g1.printGraph();

    cout<<endl;


    cout<<g1.isCycle();


    
 
}