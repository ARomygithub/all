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

const int mxn=2e5;
int n,t;
int x[mxn];

int ask(int i, int j) {
    cout <<"? " <<i+1 <<" " <<j+1 <<"\n";
    cout <<flush;
    int ret; cin >>ret;
    return ret;
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>x[i];
    }
    set<int> st;
    rep(i,1,n+1) {
        st.insert(i);
    }
    rep(i,0,n) {
        st.erase(x[i]);
    }
    if(sz(st)) {
        auto it = (*st.begin());
        int lain = (it==1? 2: 1);
        int ret1 = ask(lain-1,it-1);
        int ret2 = ask(it-1,lain-1);
        if(ret1==0 || ret2==0) {
            cout <<"! A\n";
            cout <<flush;
        } else {
            cout <<"! B\n";
            cout <<flush;
        }
    } else {
        int id0 = -1, idn = -1;
        rep(i,0,n) {
            if(x[i]==1) {
                id0 = i;
            } else if(x[i]==n) {
                idn = i;
            }
        }
        int ret1 = ask(id0, idn);
        int ret2 = ask(idn, id0);
        int isA = -1;
        if(max(ret1,ret2)>=n) {
            isA = 0;
        } else {
            if(ret1==n-1 && ret1==ret2) {
                isA = 0;
            } else {
                isA = 1;
            }
        }
        if(isA) {
            cout <<"! A\n";
            cout <<flush;
        } else {
            cout <<"! B\n";
            cout <<flush;
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