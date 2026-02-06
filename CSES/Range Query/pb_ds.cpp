#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=2e5;
int n;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n;
    oset<ar<int,2>> s;
    for(int i=0;i<n;i++) {
        int x; cin >>x;
        s.insert({i,x});
    }
    for(int i=0;i<n;i++) {
        int p; cin >>p; p--;
        auto it = s.find_by_order(p);
        cout <<(*it)[1] <<" ";
        s.erase(it);
    }
}
