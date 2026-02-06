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
    
    vector<int> B(n), C(n);
    iota(B.begin(), B.end(), 1);
    iota(C.begin(), C.end(), 1);
    while(s--){
    	int i = rnd.next(0, n-2);
    	int j = rnd.next(i+1, n-1);
    	reverse(C.begin()+i, C.begin()+j+1);
    }
    shuffle(B.begin(), B.end());
    for(int i=0; i<n; i++)
    	cout << i+1 << ' ' << B[i] << ' ' << C[i] << '\n';
    cout << q << '\n';
    while(q--){
    	int i = rnd.next(1, n);
    	int j = rnd.next(1, n);
    	while(i == j) j = rnd.next(1, n);
    	cout << i << ' ' << j << '\n';
    }
}