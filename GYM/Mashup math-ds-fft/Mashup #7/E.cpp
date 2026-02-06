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
vector<pll> v(3);

ll ask(ll x) {
    cout <<x <<"\n";
    cout <<flush;
    ll ret; cin >>ret;
    if(ret==0 || ret==-1) exit(0);
    return ret;
}

void solve() {
    cout <<"First\n";
    cout <<flush;
    rep(i,0,3) {
        v[i].se = i+1;
        cin >>v[i].fi;
    }
    sort(all(v));
    ll ret1 = ask(v[2].fi*2 - v[1].fi-v[0].fi);
    rep(i,0,3) {
        if(ret1==v[i].se) {
            v[i].fi += v[2].fi*2 - v[1].fi-v[0].fi;
            break;
        }
    }
    if(ret1==v[2].se) {
        sort(all(v));
        ll ret2 = ask(v[2].fi*2 - v[1].fi-v[0].fi);  
        rep(i,0,3) {
            if(ret2==v[i].se) {
                v[i].fi += v[2].fi*2 - v[1].fi-v[0].fi;
                break;
            }
        }     
        sort(all(v));
        ask(v[2].fi-v[1].fi);         
    } else {
        sort(all(v));
        ask(v[2].fi-v[1].fi);
    }
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}