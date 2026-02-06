#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int n = opt<int>("n");
    int q = opt<int>("q");
    cout << n << '\n';
    for(int i=1; i<=n; i++) cout<<i<<' '<<i<<' '<<i<<'\n';
    cout << q << '\n';
    while(q--){
    	int i = rnd.next(1, n);
    	int j = rnd.next(1, n);
    	while(i == j) j = rnd.next(1, n);
    	cout << i << ' ' << j << '\n';
    }
}