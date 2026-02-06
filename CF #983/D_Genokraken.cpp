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
int n,t;

int ask(int a, int b) {
    cout <<"? " <<a <<" " <<b <<"\n" <<flush;
    int ret; cin >>ret;
    return ret;
}

void solve() {
    cin >>n;
    int a1 = 2;
    while(true) {
        int ret = ask(1,a1);
        if(ret) {
            a1++;
        } else {
            break;
        }
    }
    vi p(n,-1);
    rep(i,1,a1) {
        p[i] = 0;
    }
    p[a1] = 1;
    set<int> st;
    rep(i,2,a1+1) {
        st.insert(i);
    }
    rep(i,a1+1,n) {
        while(true) {
            int ret = ask(i, (*st.begin()));
            int b = *st.begin();
            if(ret) {
                st.erase(b);
            } else {
                p[i] = b;
                st.erase(b);
                st.insert(i);
                break;
            }
        }
    }
    cout <<"! ";
    rep(i,1,n) {
        cout <<p[i] <<" \n"[i==n-1];
    }
    cout <<flush;
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