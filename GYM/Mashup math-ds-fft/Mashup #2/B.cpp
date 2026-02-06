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
int q;

ll get(ll l, ll r, ll pos) {
    ll len = r-l+1;
    if(len==1) {
        // cout <<"1 " <<pos <<endl;
        return l;
    } else if(len==2) {
        // cout <<"2 " <<pos <<endl;
        return l+pos-1;
    }
    if(pos%2) {
        return (pos-1)/2 + l;
    } else {
        if(len%2) {
            ll mid = (l+r)/2;
            return get(mid,r,pos/2 + 1);
        } else {
            ll mid = (l+r)/2;
            ll posn = (pos/2)==(mid-l+1)?1:(pos/2)+1;
            return get(mid,r,posn+1);
        }
    }
}

void solve() {
    cin >>n;
    cin >>q;
    while(q--) {
        ll xi; cin >>xi; 
        cout <<get(1,n,xi) <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}