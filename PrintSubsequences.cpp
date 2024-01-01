#include <bits/stdc++.h>
using namespace std;

void printSubsequence(int idx,vector<int> &temp,vector<int> &arr)
{
    if(idx>=arr.size())
    {
        if(temp.size()==0)
        cout << "{}";
        
        for(int x:temp)
        cout << x << " "; 
        cout << "\n";
        return;
    }

    //take element
    temp.push_back(arr[idx]);
    printSubsequence(idx+1,temp,arr);
    temp.pop_back();
    
    //not take element
    printSubsequence(idx+1,temp,arr);
}
int main()
{
    vector<int> arr{3,1,2};
    vector<int> temp;
    printSubsequence(0,temp,arr);
}