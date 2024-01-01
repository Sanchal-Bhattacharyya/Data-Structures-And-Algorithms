#include <iostream>
using namespace std;

int countSubsequence(int idx,int sum,int arr[],int k,int n)
{
    if(idx==n)
    {
        if(sum==k)
            return 1;
        
        return 0;
    }

    

    //take
    sum = sum + arr[idx];
    int t = countSubsequence(idx+1,sum,arr,k,n);
    sum = sum - arr[idx];

    //not take
    int nt = countSubsequence(idx+1,sum,arr,k,n);
    
    return t+nt;

}

int main()
{
    int k = 10;
    int arr[5] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << countSubsequence(0,0,arr,k,n) << "\n";
    return 0;
}