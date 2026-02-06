#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int n = opt<int>("n");
    int s = opt<int>("s");
    int q = opt<int>("q");
    cout << n << '\n';
    
    vector<int> A(n), B(n), C(n);
    vector<vector<int>> G(s);
    for(int i=0; i<n; i++) G[rnd.next(0, s-1)].push_back(i);
    int Z = 0;
    auto fillgroup = [&](vector<int> &V){
    	int l = Z+1, r = Z+V.size();
    	int m = V.size();
    	for(int i=0; i<V.size(); i++){
    		int x = V[i];
    		A[x] = l+i;
    		B[x] = l+(i+m-1)%m;
    		C[x] = l+(i+m-2)%m;
    	}
    };
    for(int i=0; i<s; i++) fillgroup(G[i]), Z+= G[i].size();
    
    for(int i=0; i<n; i++)
    	cout << A[i] << ' ' << B[i] << ' ' << C[i] << '\n';
    cout << q << '\n';
    while(q--){
    	int i = rnd.next(1, n);
    	int j = rnd.next(1, n);
    	while(i == j) j = rnd.next(1, n);
    	cout << i << ' ' << j << '\n';
    }
}
