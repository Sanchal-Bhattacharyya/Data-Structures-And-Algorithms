#include <bits/stdc++.h>
using namespace std;

vector<int> stringMatch(string &str, string &pat) {

	const int p = 31;
	const int m = 1e9+9;
	
	int S = str.size();
	int P = pat.size();
	
	vector<long long> p_pow(S);
	p_pow[0] = 1;
	for(int i=1;i<S;i++)
		p_pow[i] = (p_pow[i-1]*p)%m;
	
	vector<long long> h(S+1,0);
	for(int i=0;i<S;i++)
		h[i+1] = (h[i] + (str[i] - 'A' + 1)*p_pow[i])%m;
	
	long long h_s = 0;
	for(int i=0;i<P;i++)
		h_s = (h_s + (pat[i] - 'A' + 1)*p_pow[i])%m;
	
	vector<int> occurences;
	
    for (int i = 0; i + P - 1 < S; i++) { 
        long long cur_h = (h[i+P] + m - h[i]) % m; 
        if (cur_h == (h_s * p_pow[i] % m))
            occurences.push_back(i);
    }
    return occurences;
}

int main()
{
    string str = "CODENCODE";
    string pat = "CODE";
    vector<int> ans = stringMatch(str,pat);
    for(int x:ans)
    cout << x << " ";

    return 0;

}