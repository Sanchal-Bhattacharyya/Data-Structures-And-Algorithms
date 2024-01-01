#include <bits/stdc++.h>
using namespace std;

bool printSubsequence(int idx,int sum,vector<int> &ds,int arr[],int k,int n)
{
    if(idx==n)
    {
        if(sum==k)
        {
            for(int x:ds) cout << x << " ";
            return true;
        }
        return false;
    }

    //take
    ds.push_back(arr[idx]);
    sum = sum + arr[idx];
    if(printSubsequence(idx+1,sum,ds,arr,k,n)) return true;
    ds.pop_back();
    sum = sum - arr[idx];

    //not take
    if(printSubsequence(idx+1,sum,ds,arr,k,n)) return true;

    return false;

}

int main()
{
    int k = 10;
    vector<int> ds;
    int arr[5] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printSubsequence(0,0,ds,arr,k,n);
    return 0;
}