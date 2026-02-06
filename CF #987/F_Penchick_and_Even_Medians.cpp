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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pii ask(vi& v) {
    pii ret;
    cout <<"? " <<sz(v) <<" ";
    rep(i,0,sz(v)) {
        cout <<v[i]+1 <<" \n"[i==sz(v)-1];
    }
    cout <<flush;
    cin >>ret.fi;
    if(ret.fi==-1) exit(0);
    cin >>ret.se;
    return ret;
}

void solve() {
    cin >>n;
    int l=-1,r=-1;
    int m = n/2;
    while(true) {
        l = rng()%n;
        r = rng()%n;
        if(l==r) continue;
        vi v;
        rep(i,0,n) {
            if(i!=l && i!=r) {
                v.push_back(i);
            }
        }
        pii ret = ask(v);
        if(ret.fi==m && ret.se==m+1) {
            break;
        }
    }
    vi v;
    rep(i,0,n) {
        if(i!=l && i!=r) {
            v.push_back(i);
        }
    }
    vector<pii> tg(2);
    for(int i=0;i<sz(v);i+=2) {
        vi v2;
        v2.push_back(l); v2.push_back(r);
        v2.push_back(v[i]); v2.push_back(v[i+1]);
        pii ret = ask(v2);
        bool ada1 = (ret.fi==m || ret.se==m);
        bool ada2 = (ret.fi==m+1 || ret.se==m+1);
        if(ada1 && ada2) {
            cout <<"! " <<v[i]+1 <<" " <<v[i+1]+1 <<"\n" <<flush;
            return;
        } else if(ada1) {
            tg[0] = {v[i],v[i+1]};
        } else if(ada2) {
            tg[1] = {v[i],v[i+1]};
        }
    }
    auto cek = [&](int id1,int id2) -> pii {
        vi v2;
        v2.push_back(l); v2.push_back(r);
        v2.push_back(id1); v2.push_back(id2);
        return ask(v2);
    };
    int i1 = -1,i2=-1;
    auto ret1 = cek(tg[0].fi,tg[1].fi);
    if(ret1.fi==m || ret1.se==m) {
        i1 = tg[0].fi;
    } else {
        i1 = tg[0].se;
    }
    if(ret1.fi==m+1 || ret1.se==m+1) {
        i2 = tg[1].fi;
    } else {
        i2 = tg[1].se;
    }
    cout <<"! " <<i1+1 <<" " <<i2+1 <<"\n";
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