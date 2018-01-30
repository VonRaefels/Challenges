static bool has_unvisited_child(int el, int vis[], vector<int> adj[]) {
    vector<int>::iterator it;
    for (it = adj[el].begin(); it != adj[el].end(); ++it) {
        if(!vis[*it]) {
            return true;
        }
    }
    return false;
}

static void check_path(deque<int>& path, stack<int>& result, int vis[], vector<int> adj[]) {
    while(!path.empty()) {
        int front = path.front();
        if(has_unvisited_child(front, vis, adj)){
            return;
        }else {
            path.pop_front();
            result.push(front);
        }
    }
}
/*
 * Very similar to cycle detection. Just use a stack to push the nodes
 * and respect the ordering.
 */
int * topoSort(vector<int> graph[], int N)
{
    int *sorted = new int[N];
    stack<int> result;
    deque<int> path;
    int vis[N] = { false };
    
    for(int v = 0; v < N; v++) {
        stack<int> S;
        S.push(v);
        vector<int>::iterator i;
        while(!S.empty()){
            int s = S.top();
            S.pop();
            
            if (!vis[s]) {
                vis[s] = true;
                path.push_front(s);
            
                for (i = graph[s].begin(); i != graph[s].end(); ++i)
                {
                    if(!vis[*i]) {
                        S.push(*i);
                    }
                }
                if(!has_unvisited_child(s, vis, graph)) { //Reached last leaf of dfs
                    int front = path.front();

                    path.pop_front();
                    result.push(front);
                    check_path(path, result, vis, graph);
                }
                
            }
        }
        check_path(path, result, vis, graph);
    }
    int i = 0;
    while (!result.empty())
    {
        sorted[i] = result.top();
        result.pop();
        i++;
    }
    return sorted;
}