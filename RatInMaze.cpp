#include <iostream>
#include <vector>
using namespace std;

void solve(int row,int col,int maze[4][4],string move,int vis[4][4],int n)
{
    if(row==n-1 && col==n-1)
    {
        cout << move << "\n";
        return;
    }

    //downward
    if(row+1<n && !vis[row+1][col] && maze[row+1][col]==1)
    {
        vis[row][col] = 1;
        solve(row+1,col,maze,move+'D',vis,n);
        vis[row][col] = 0;
    }
    
    //left
    if(col-1>=0 && !vis[row][col-1] && maze[row][col-1]==1)
    {
        vis[row][col] = 1;
        solve(row,col-1,maze,move+'L',vis,n);
        vis[row][col] = 0;
    }

    //right
    if(col+1<n && !vis[row][col+1] && maze[row][col+1]==1)
    {
        vis[row][col] = 1;
        solve(row,col+1,maze,move+'R',vis,n);
        vis[row][col] = 0;
    }

    //upwards
    if(row-1>=0 && !vis[row-1][col] && maze[row-1][col]==1)
    {
        vis[row][col] = 1;
        solve(row-1,col,maze,move+'U',vis,n);
        vis[row][col] = 0;
    }
    return;
}
int main()
{
    int maze[4][4] = {{1,0,0,0},
                      {1,1,0,1},
                      {1,1,0,0},
                      {0,1,1,1}};
    
    int vis[4][4] = {0};
    
    if(maze[0][0]==1)
    solve(0,0,maze,"",vis,4);

    return 0;
    
}