#include <bits/stdc++.h>
using namespace std;

bool printSubsequenceSum(int idx,int sum,int k,int arr[],vector<int> &ele)
{
    if(idx==5)
    {
        if(sum==k)
        {
            for(int x:ele) 
            cout << x <<" ";
            
            cout << "\n";
            
            return true;
        }
        return false;
    }

    //take the element
    ele.push_back(arr[idx]);
    sum += arr[idx];
    printSubsequenceSum(idx+1,sum,k,arr,ele);
    sum -= arr[idx];
    ele.pop_back();

    //not take the element
    printSubsequenceSum(idx+1,sum,k,arr,ele); 
    
    return false;
}

int main()
{
    vector<int> elements;
    int arr[5] = {1,2,3,4,5};
    int idx = 0;
    int k = 10;
    int sum = 0;
    printSubsequenceSum(idx,sum,k,arr,elements);
    return 0;
}