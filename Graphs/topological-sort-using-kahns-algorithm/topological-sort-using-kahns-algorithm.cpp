#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<queue>

using namespace std;

class Graph
{
    public:
        int V;
        list<int> *l;
        vector<int> indegree;

        Graph(int V)
        {
            this->V = V;
            l = new list<int>[V];
            indegree = vector<int>(V,0);

        }

        void addEdge(int u, int v)
        {
            l[u].push_back(v);
            indegree[v]++;
        }

        void topological_kahn()
        {
            queue<int> q;
            for(int i=0; i<V; i++)
            {
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }

            while(q.size()>0)
            {
                int curr = q.front();

                q.pop();

                cout<<curr<<" ";

                for(int v: l[curr])
                {
                    indegree[v]--;
                    if(indegree[v]==0)
                    {
                        q.push(v);
                    }
                }
            }

        }


};

int main()
{

    Graph g1(6);

    g1.addEdge(5, 2);
    g1.addEdge(5, 0);
    g1.addEdge(4, 0);
    g1.addEdge(4, 1);
    g1.addEdge(2, 3);
    g1.addEdge(3, 1);

    g1.topological_kahn();

}