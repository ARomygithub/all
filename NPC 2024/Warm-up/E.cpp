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
using piii = pair<pii,int>;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e3;
int n,hp,reg;

void solve() {
    cin >>n >>hp >>reg;
    vector<piii> v(n);
    rep(i,0,n) {
        cin >>v[i].fi.fi >>v[i].fi.se;
        v[i].se = i;
    }
    sort(all(v),greater<piii>());
    int t = 1;
    int idx = 0;
    set<pii> ms;
    int mhp = hp;
    vector<pii> ans;
    while(true) {
        while(idx<sz(v) && v[idx].fi.fi>=hp) {
            ms.insert({v[idx].fi.se,v[idx].se});
            idx++;
        }
        if(sz(ms)) {
            auto it = --ms.end();
            auto [dps, id] = *it;
            reg -= dps;
            ans.push_back({t,id});            
            ms.erase(it);
        }
        hp = min(mhp, hp+reg);
        if(hp<=0) {
            break;
        }
        if(sz(ms)==0 && reg>=0) {
            cout <<"Pisi butuh bantuan Elsi\n";
            cout <<mhp <<"\n";
            return;
        }
        t++;
    }
    cout <<"Pisi dapat melakukan sendiri\n";
    cout <<t <<" " <<sz(ans) <<"\n";
    for(auto [ti,id]: ans) {
        cout <<ti <<" " <<id+1 <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}