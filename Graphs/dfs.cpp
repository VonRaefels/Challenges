using namespace std;
#include <stack>

void dfs(int s, vector<int> g[], bool vis[])
{
    stack<int> S;
    S.push(s);
    vector<int>::reverse_iterator i;
    
    while(!S.empty()){
        s = S.top();
        S.pop();
        
        // This is needed in this case (DFS) since we migh
        // see a stacked element twice, we could also implement
        // it by stacking the first element of the adj list...
        if (!vis[s]) {
            cout << s << " ";
            vis[s] = true;
        }
        
        for (i = g[s].rbegin(); i != g[s].rend(); ++i)
        {
            if(!vis[*i]) {
                S.push(*i);
            }
        }
    }
}

