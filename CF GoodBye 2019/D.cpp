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
int n,k;

pii ask(vector<int>& v) {
    cout <<"? ";
    rep(i,0,sz(v)) {
        cout <<v[i] <<" \n"[i==sz(v)-1];
    }
    cout <<flush;
    pii ret; cin >>ret.fi >>ret.se;
    return ret;
}

void solve() {
    cin >>n >>k;
    vector<int> v;
    rep(i,1,k+1) {
        v.push_back(i);
    }
    auto [b1, v1] = ask(v);
    v.erase(v.begin()+b1-1);
    v.push_back(k+1);
    auto [ax, vx] = ask(v);
    int ct0 = 0;
    rep(i,0,k) {
        if(v[i]==ax) continue;
        swap(v[i], b1);
        auto res = ask(v);
        if((res.fi==ax && v1<vx) || (res.fi!=ax && v1>vx) ) {
            ct0++;
        }
        swap(v[i], b1);
    }
    cout <<"! " <<ct0+1 <<"\n";
    cout <<flush;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}