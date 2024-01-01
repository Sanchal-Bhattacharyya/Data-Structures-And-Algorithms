#include <bits/stdc++.h>
using namespace std;

void printAllPermute(int idx,vector<int> &input)
{
    if(idx==input.size())
    {
        for(int x:input)
        cout << x << " ";

        cout << "\n";
        return;
    }

    for(int i=idx;i<input.size();i++)
    {
        swap(input[i],input[idx]);
        printAllPermute(idx+1,input);
        swap(input[i],input[idx]);
    }

    return;
}

int main()
{
    vector<int> input{1,2,3};
    vector<int> ds;
    printAllPermute(0,input);

    return 0;
}