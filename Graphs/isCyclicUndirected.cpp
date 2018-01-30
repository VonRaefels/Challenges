/*The structure of the class is as follows 
which contains an integer V denoting the no 
of vertices and a list of adjacency vertices.
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};*/

static bool has_unvisited_child(int el, int vis[], list<int> adj[]) {
    list<int>::iterator it;
    for (it = adj[el].begin(); it != adj[el].end(); ++it) {
        if(!vis[*it]) {
            return true;
        }
    }
    return false;
}

/*
 * UNDIRECTED GRAPHS, it is easier than directed graphs,
 * no need to store the path, just check if it was visited.
 */ 
bool Graph :: isCyclic()
{
    int vis[V] = { false };
    for(int v = 0; v < V; v++) {
        if(!has_unvisited_child(v, vis, adj)) {
            continue;
        }
        stack<int> S;
        int s = v;
        S.push(s);
        list<int>::iterator i;
        
        while(!S.empty()){
            s = S.top();
            S.pop();
            
            if (!vis[s]) {
                vis[s] = true;
            
                for (i = adj[s].begin(); i != adj[s].end(); ++i)
                {
                    if (*i == s) {
                        return true;
                    }
                    if(!vis[*i]) {
                        S.push(*i);
                    }
                }
            }else {
                return true;
            }
        }
    }
    return false;
}