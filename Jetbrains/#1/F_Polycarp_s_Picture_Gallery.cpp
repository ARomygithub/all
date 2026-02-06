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

const int mxm=40;
int n,m,t;
int a[mxm+1];

void solve() {
    cin >>n >>m;
    // assert(n<=1000);
    // assert(m<=40);
    rep(i,1,m+1) {
        cin >>a[i];
        // assert(a[i]>=1 && a[i]<=1000);
    }
    vi ans(n,0);
    set<pii> s;
    rep(i,1,m+1) {
        s.insert({a[i],i});
    }
    rep(i,0,n) {
        if(sz(s)==0) {
            cout <<"-1\n";
            return;
        }
        if(i==n-1) {
            auto it = --s.end();
            if((it->se == ans[i-1]) || (it->se == ans[0])) {
                if(it==s.begin()) {
                    cout <<"-1\n";
                    return;
                }
                it--;
                if((it->se == ans[i-1]) || (it->se == ans[0])) {
                    if(it==s.begin()) {
                        cout <<"-1\n";
                        return;
                    }
                    it--;
                }
            }
            auto [ct,val] = *it;
            s.erase(it);
            ct--;
            ans[i] = val;
            if(ct>0) {
                s.insert({ct,val});
            }            
        } else {
            auto it = --s.end();
            if(i>0) {
                if(it->se == ans[i-1]) {
                    if(it==s.begin()) {
                        cout <<"-1\n";
                        return;
                    }
                    it--;
                }
            } 
            auto [ct,val] = *it;
            s.erase(it);
            ct--;
            ans[i] = val;
            if(ct>0) {
                s.insert({ct,val});
            }
        }
    }
    rep(i,0,n) {
        assert(ans[i]!= ans[(i+1)%n]);
        assert(ans[i]!= ans[(i-1+n)%n]);
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}