#include <bits/stdc++.h>
using namespace std;

int main()
{
    int upper = 1000, lower = 50;
    srand(time(NULL));
    int num = ((rand() % (upper - lower + 1)) + lower);

    float ans = (float)num/10;
    
    cout << num << "\n";
    cout << ceil(ans)*10 << "\n";
    cout << floor(ans)*10 << "\n";

    return 0;
}