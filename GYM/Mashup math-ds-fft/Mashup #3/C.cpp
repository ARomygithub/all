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
ll n;
int k;

string ask(ll l, ll r) {
    cout <<l <<" " <<r <<"\n";
    cout <<flush;
    string ret; cin >>ret;
    return ret;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
    cin >>n >>k;
    int mn = max(1,k*5);
    ll le = 1, ri=n;
    while(true) {
        ll len = ri-le+1;
        if(len>mn) {
            ll mid = (le+ri)/2;
            auto ans = ask(le,mid);
            if(ans[0]=='B') {
                return;
            } else if(ans[0]=='Y') {
                if(le==mid) {
                    return;
                }
                le = max(1ll,le-k);
                ri = min(n,mid+k);
            } else {
                le = max(1ll, mid+1-k);
                ri = min(n,ri+k);
            }
        } else {
            ll rnd = le + rng()%len;
            auto ans = ask(rnd,rnd);
            // cout <<ans <<endl;
            if(ans[0]=='Y') {
                // cout <<"TEs" <<endl;
                return;
            } else if(ans[0]=='B') {
                return;
            } else {
                le = max(1ll,le-k);
                ri = min(n,ri+k);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}