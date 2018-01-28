using namespace std;
#include <queue>

void bfs(int s,vector<int> adj[],bool vis[])
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    vector<int>::iterator i;
    
    while(!q.empty()){
        s = q.front();
        q.pop();
        cout << s << " ";
        
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!vis[*i]) {
                vis[*i] = true;
                q.push(*i);
            }
        }
    }
}