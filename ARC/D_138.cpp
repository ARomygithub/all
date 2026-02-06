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

const int mxn=18;
int n,k;
int basis[31], szi=0, awl[31];

void add(int x) {
    int awli = x;
    per(i,30,-1) {
        if((x>>i)&1) {
            if(basis[i]) {
                x ^= basis[i];
                if(!x) break;
            } else {
                basis[i] = x;
                szi++;
                awl[i] = awli;
                break;
            }
        }
    }
}

void solve() {
    cin >>n >>k;
    if(n==k) {
        if(n>1) {
            cout <<"No\n";
        } else {
            cout <<"Yes\n";
            cout <<"0 1\n";
        }
        return;
    }
    rep(i,1,(1<<n)) {
        if(__builtin_popcount(i)==k) {
            add(i);
            if(szi==n) break;
        }
    }
    if(szi!=n) {
        // assert(false);
        cout <<"No\n";
        return;
    }
    vector<int> ans;
    int s = 0;
    set<int> st;
    rep(i,0,(1<<n)-1) {
        bool ok = 0;
        rep(j,0,n) {
            int s2 = s^awl[j];
            if(s2==0) continue;
            if(!st.count(s2)) {
                ans.push_back(s2);
                st.insert(s2);
                s = s2;
                ok = 1;
                break;
            }
        }
        if(!ok) break;
    }
    if(sz(ans)==(1<<n)-1) {
        bool tes = 0;
        rep(j,0,n) {
            if(basis[j] == (ans.back())) {
                tes = 1;
                break;
            }
        }
        assert(tes);
        ans.push_back(0);
        cout <<"Yes\n";
        rep(i,0,sz(ans)) {
            cout <<ans[i] <<" \n"[i==sz(ans)-1];
        }
    } else {
        assert(false);
        cout <<"No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}