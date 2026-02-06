#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=2e5;
int n, q, p[mxn];

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

oset<ar<int,2>> s;

int qry(int a) {
    // return s.order_of_key()
    return s.order_of_key({a,0});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n >>q;
    for(int i=0;i<n;i++) {
        cin >>p[i];
        s.insert({p[i],i});
    }
    for(int i=0;i<q;i++) {
        char ch; cin >>ch;
        if(ch=='!') {
            int k,x; cin >>k >>x; k--;
            s.erase({p[k],k});
            p[k]=x;
            s.insert({p[k],k});
        } else {
            int a,b; cin >>a >>b;
            cout <<qry(b+1) -qry(a) <<"\n";
        }
    }
}
