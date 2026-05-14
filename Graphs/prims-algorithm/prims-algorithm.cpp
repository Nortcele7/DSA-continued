#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<climits>

using namespace std;


class Edge
{
    public:
        int v;
        int wt;

        Edge(int v, int wt)
        {
            this->v = v;
            this->wt = wt;
        }
};

void primsMST(int src, vector<vector<Edge>> g, int V)
{
    vector<bool> mst_set(V, false);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    int minCost = 0;

    pq.push({0, src});

    while(pq.size()>0)
    {
        int u = pq.top().second;
        int cost = pq.top().first;

        pq.pop();

        if(!mst_set[u])
        {

            mst_set[u] = true;

            minCost += cost;

        
            for(Edge e: g[u])
            {
                if(!mst_set[e.v])
                {
                    pq.push({e.wt, e.v});
                }
            }

        }

    }

    cout<<"Min Cost = "<<minCost;

}



int main()
{
    int V = 4;

    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1,10));
    g[1].push_back(Edge(0,10));

    g[0].push_back(Edge(2,15));
    g[2].push_back(Edge(0,15));

    g[0].push_back(Edge(3,30));
    g[3].push_back(Edge(0,30));

    g[1].push_back(Edge(3,40));
    g[3].push_back(Edge(1,40));

    g[2].push_back(Edge(3,50));
    g[3].push_back(Edge(2,50));

    primsMST(0, g, V);



   

    cout<<endl;

}
