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
int n;

void solve() {
    cin >>n;
    set<pii> s;
    vi val(n);
    rep(i,0,n) {
        int ai; cin >>ai;
        val[i] = ai;
        s.insert({ai,i});
    }
    vector<pii> ans;
    int id = 0;
    auto add = [&](int i, int j) -> void {
        ans.push_back({i+1,j+1});
        ans.push_back({j+1,i+1});
        ans.push_back({i+1,j+1});
    };
    while(sz(s)) {
        auto [vali,i] = *s.begin();
        if(i!=id) {
            int j = id;
            s.erase({val[j],j});
            s.erase(s.begin());
            s.insert({val[j],i});
            swap(val[j],val[i]);
            add(i,j);
            id++;
        } else {
            s.erase(s.begin());
            id++;
        }
    }
    cout <<sz(ans) <<"\n";
    for(auto [i,j]: ans) {
        cout <<i <<" " <<j <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}