#include <iostream>
using namespace std;

int c = 0;

void print()
{
    if(c == 5)
    return;
    
    cout << c << "\n";
    c++;
    print();
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    print();

    return 0;

}