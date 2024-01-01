#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    int f = 1;
    for(int i=1;i<=n;i++)
    f = f*i;

    return f;
}

int main()
{
    int n,k;
    cin >> n >> k;

    int fact = factorial(n-1);
    
    vector<int> nums;
    for(int i=1;i<=n;i++)
    {
        nums.push_back(i);
    }

    string ans = "";

    //because of 0th based indexing
    k = k-1;

    while(true)
    {
        ans = ans + to_string(nums[k/fact]);
        nums.erase(nums.begin()+k/fact);
        if(nums.size()==0)
        {
            break;
        }
        k = k%fact;
        fact = fact/nums.size();
    }

    cout << ans;

}