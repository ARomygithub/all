#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
#define pdi pair<double,int>

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e3;
int n;
vector<int> v1;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

oset<pdi> s;

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

bool ask(int i, int j, int k) {
    cout <<"? " <<i <<" " <<j <<k <<"\n";
    cout <<flush;
    string resp;
    cin >>resp;
    return (resp[0]=='Y');
}

int find_1(int l, int r) {
    if(l==r) {
        return v1[0];
    }
    int i = rng32()%r;
    int k = rng32()%r;
    while(k==i) {
        k = rng32()%r;
    }
    bool yes=1;
    vector<int> v2;
    for(int ii=0;ii<r;ii++) {
        // if(ii==i || ii==k) continue;
        yes = ask(i,ii,k);
        if(!yes) {
            v2.push_back(ii);
        }
    }
    if(sz(v2)==0) {
        swap(i,k);
        for(int ii=0;ii<r;ii++) {
            // if(ii==i || ii==k) continue;
            yes = ask(i,ii,k);
            if(!yes) {
                v2.push_back(ii);
            }
        }        
    }
    v1.swap(v2);
    return find_1(1,sz(v1));
}

void solve() {
    cin >>n;
    v1.resize(n);
    iota(v1.begin(),v1.end(),1);
    int p1 = find_1(1,n);
    vector<int> ans(n,0);
    ans[0] = p1;
    s.insert({0.0,p1});
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}