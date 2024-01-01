#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row,int col,vector<string> &board,int n)
{
    int originalrow = row;
    int originalcol = col;

    //checking upper diagonal
    while(row>=0 && col>=0)
    {
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }

    row = originalrow;
    col = originalcol;

    //checking for lower diagonal
    while(row<n && col>=0)
    {
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }

    row = originalrow;
    col = originalcol;

    //checking left horizontal -X axis
    while(col>=0)
    {
        if(board[row][col]=='Q') return false;
        col--;
    }

    return true;
}

void solve(int col,vector<string> &board,int n)
{
    //base condition
    if(col==n)
    {
        for(string s:board)
        cout << s << "\n";

        cout <<"\n\n";

        return;
    }

    for(int row = 0;row<n;row++)
    {
        if(isSafe(row,col,board,n))
        {
            board[row][col] = 'Q';
            solve(col+1,board,n);
            board[row][col] = '.';
        }
    }
}
int main()
{
    int n;
    cin >> n;
    cout << "Arrangements:" << "\n\n";
    std::vector<string> board(n);
    string s(n,'.');
    
    for(int i=0;i<n;i++)
    board[i] = s;

    solve(0,board,n);

}