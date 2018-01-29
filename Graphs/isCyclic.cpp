/*
The structure of the class is as follows 
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
};


*/
using namespace std;
#include <stack>

static bool has_unvisited_child(int el, int vis[], list<int> adj[]) {
    list<int>::iterator it;
    for (it = adj[el].begin(); it != adj[el].end(); ++it) {
        if(!vis[*it]) {
            return true;
        }
    }
    return false;
}

static void check_path(deque<int>& path, set<int>& pathSet, int vis[], list<int> adj[]) {
    while(!path.empty()) {
        int front = path.front();
        if(has_unvisited_child(front, vis, adj)){
            return;
        }else {
            path.pop_front();
            pathSet.erase(front);
        }
    }
}

/* Iterative method, uses set along with deque to
 * store current path and find cycles.
 */
bool Graph :: isCyclic()
{
    
    int vis[V] = { false };
    deque<int> path;
    set<int> pathSet;
    for(int v = 0; v < V; v++) {
        stack<int> S;
        S.push(v);
        list<int>::iterator i;
    
        while(!S.empty()){
            int s = S.top();
            S.pop();
            
            if (!vis[s]) {
                vis[s] = true;
                path.push_front(s);
                pathSet.insert(s);
            
                for (i = adj[s].begin(); i != adj[s].end(); ++i)
                {
                    if(pathSet.find(*i) != pathSet.end()){
                        return true;
                    }
                    if(!vis[*i]) {
                        S.push(*i);
                    }
                }
                
                if(!has_unvisited_child(s, vis, adj)) { //Reached last leaf of dfs
                    int front = path.front();
                    path.pop_front();
                    pathSet.erase(front);
                    check_path(path, pathSet, vis, adj);
                }
            }
        }
        check_path(path, pathSet, vis, adj);
    }
    return false;
}