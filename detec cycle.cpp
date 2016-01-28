#include <bits/stdc++.h>
using namespace std;

class Graph
{
    private:
    int V;
    list<int> *adj;
    bool isCyclic(int v,bool visited [], bool *rs);

    public:
    Graph(int V);
    void addEdge(int v, int w);
    bool iscyclic();//constructor
};
Graph::Graph(int V)//constructor has no return type
{
    this->V=V;
    adj = new lis<int>[V];
}
void Graph::addEdge(int v,int w)
{
 adj[v].push_back(w);   
}

int main()
{

return 0;
}
