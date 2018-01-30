void printMatrix(int A[MAX][MAX], int N, int M){
int row, columns;
    for (int row=0; row<N; row++)
    {
        for(int columns=0; columns<M; columns++)
            {
             printf("%d     ", A[row][columns]);
            }
        printf("\n");
    }
}

struct Coordinate
{
    int x, y;

    Coordinate(int paramx, int paramy) : x(paramx), y(paramy) {}
};

list<Coordinate> adjacent(Coordinate c, int A[MAX][MAX], int vis[MAX][MAX], int N, int M) {
    list<Coordinate> neighbours;
    int counter = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int posX = c.x + i;
            int posY = c.y + j;
            if(i == 0 && j == 0) { continue; }
            if (posX >= 0 && posY >= 0 && !vis[posX][posY] && A[posX][posY] == 1 && posX < N && posY < M) {
                neighbours.push_back(Coordinate(posX, posY));
            }
        }
    }
    return neighbours;
}

int findIslands(int A[MAX][MAX], int N, int M)
{
    int vis[MAX][MAX] =
        {
          {0, 0},
          {0, 0}
        };
    bool island = false;
    int num_islands = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(A[i][j] == 0) { continue; } 
            else if (!vis[i][j]) { island = true; }
            stack<Coordinate> S;
            S.push(Coordinate(i, j));
            list<Coordinate>::iterator it;
            
            while(!S.empty()){
                Coordinate s = S.top();
                S.pop();
                
                if (!vis[s.x][s.y]) {
                    vis[s.x][s.y] = true;
                    
                    list<Coordinate> adj = adjacent(s, A, vis, N, M);
                    
                    for (it = adj.begin(); it != adj.end(); ++it)
                    {
                        Coordinate n = *it;
                        if(!vis[n.x][n.y]) {
                            S.push(*it);
                        }
                    }
                }
            }
            if (island) {
                island = false;
                num_islands++;
            }
        }
    }
    return num_islands;
}