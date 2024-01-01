#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[],int l,int r)
{
    if(l>=r)
    return;

    swap(arr[l],arr[r]);
    reverseArray(arr,l+1,r-1);
}
int main()
{
    int arr[] = {1,2,3,4,5,6};
    
    reverseArray(arr,0,5);

    for(int x:arr)
    cout << x << " ";

    return 0;

}