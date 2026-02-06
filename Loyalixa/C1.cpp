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

const int mxn=1e6;
int n, a[mxn],q;

using piii = tuple<int,int,int>;

void solve() {
    cin >>n;
    int mx = 0;
    rep(i,0,n) {
        cin >>a[i];
        max_self(mx, a[i]);
    }
    vector id(mx+1, vi());
    rep(i,0,n) {
        id[a[i]].push_back(i);
    }
    cin >>q;
    vector<piii> qry;
    rep(i,0,q) {
        int x,k; cin >>x >>k; k--;
        qry.push_back({x,k,i});
    }
    sort(all(qry));
    vi ansq(q,-2);
    for(int i=0;i<q;) {
        int j = i;
        while(j<q && get<0>(qry[i])==get<0>(qry[j])) {
            j++;
        }
        int x = get<0>(qry[i]);
        vi ans;
        for(int l = x;l<=mx;l+=x) {
            for(auto idi: id[l]) {
                ans.push_back(idi);
            }
        }
        sort(all(ans));
        rep(l,i,j) {
            auto [xi, k, iq] = qry[l]; 
            if(k<sz(ans)) {
                ansq[iq] = ans[k];
            }
        }
        i = j;
    }
    rep(i,0,q) {
        cout <<ansq[i]+1 <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}