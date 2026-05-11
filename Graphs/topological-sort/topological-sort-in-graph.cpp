#include<iostream>
#include<vector>
#include<list>
#include<stack>

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

        void topological_dfs(int src, vector<bool>& vis, stack<int>& s)
        {
            vis[src] = true;

            for(int v: l[src])
            {
                if(!vis[v])
                {
                    topological_dfs(v,vis, s);
                }
            }
            s.push(src);
        }

        void topological_sort()
        {
            vector<bool> vis(V, false);

            stack<int> s;

            for(int i=0; i<V; i++)
            {
                if(!vis[i])
                {
                    topological_dfs(i, vis, s);
                }
            }

            while(!s.empty())
            {
                cout<<s.top()<<" ";
                s.pop();
            }

        }

};

int main()
{
    Graph g1(2);

    g1.addEdge(1,0);
    g1.addEdge(0,1);

    g1.topological_sort();


}