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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,x,t;
int a[mxn];

void solve() {
    cin >>n >>x;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<int> ct(30,0);
    int ans = 0;
    vector idx(30, vector<int>());
    rep(i,0,n) {
        rep(j,0,30) {
            if((a[i]>>j)&1) {
                ct[j]++;
                idx[j].push_back(i);
            }
        }
    }
    vector<int> r(n);
    iota(r.begin(),r.end(),0);
    per(bit,29,-1) {
        if(ct[bit]%2) {
            if(!((x>>bit)&1)) {
                if(ans>0) {
                    cout <<ans <<"\n";
                } else {
                    cout <<"-1\n";
                }
                return;
            }
        } else {
            if((x>>bit)&1) {
                vector<pii> oldr;
                for(int i=0;i<sz(idx[bit]);i+=2) {
                    oldr.push_back({idx[bit][i],r[idx[bit][i]]});
                    max_self(r[idx[bit][i]], idx[bit][i+1]);
                }
                int temp = 0;
                for(int i=0;i<n;) {
                    int en = r[i];
                    while(i<en) {
                        i++;
                        max_self(en, r[i]);
                    } 
                    temp++;
                    i++;
                }
                max_self(ans, temp);
                for(auto [ridx, ri]: oldr) {
                    r[ridx] = ri;
                }
            } else {
                for(int i=0; i< sz(idx[bit]); i+=2) {
                    max_self(r[idx[bit][i]], idx[bit][i+1]);
                }
            }
        }
    }
    int temp = 0;
    for(int i=0;i<n;) {
        int en = r[i];
        while(i<en) {
            i++;
            max_self(en, r[i]);
        } 
        temp++;
        i++;
    }
    max_self(ans, temp);    
    cout <<ans <<"\n";
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