#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef vector<int> vi;
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,m,t;
using pcii = pair<char,pii>;

void do_b(vector<pcii>& v, int i, int j, int ct) {
    rep(k,0,(ct/2)) {
        v.push_back({'B', {i+k,j+k}});
    }
    per(k,(ct/2),0) {
        v.push_back({'B', {i+k, j+k-2}});
    }
}

void solve() {
    cin >>n >>m;
    if(n%2) {
        cout <<"No\n";
        return;
    }
    if(m%2) {
        if(n==0) {
            cout <<"No\n";
            return;
        }
        vector<pcii> v;
        rep(i,1,(n/2)+1) {
            v.push_back({'R',{1,i}});
        }
        do_b(v, 1, (n/2)+1, m+1);
        v.pop_back();
        per(i,(n/2),0) {
            v.push_back({'R',{2,i}});
        }
        cout <<"Yes\n";
        for(auto [c, ij]: v) {
            auto [i,j] = ij;
            cout <<c <<" " <<i <<" " <<j <<"\n";
        }
    } else {
        vector<pcii> v;
        rep(i,1,(n/2)+1) {
            v.push_back({'R', {i, 2}});
        }
        do_b(v, max((n/2),1), 3, m);
        per(i,(n/2),0) {
            v.push_back({'R', {i,1}});
        }
        cout <<"Yes\n";
        for(auto [c, ij]: v) {
            auto [i,j] = ij;
            cout <<c <<" " <<i <<" " <<j <<"\n";
        }        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}