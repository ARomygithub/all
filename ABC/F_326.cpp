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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=80;
int n,x,y;
int a[mxn];

void solve() {
    cin >>n >>x >>y;
    int sx=0, sy=0;
    rep(i,0,n) {
        cin >>a[i];
        if(i%2) {
            sx +=a[i];
        } else {
            sy +=a[i];
        }
    }
    if((sx%2)!=(abs(x)%2) || (sy%2)!=(abs(y)%2)) {
        cout <<"No\n";
        // cout <<sx <<" " <<x <<" " <<sy <<" " <<y <<"\n";
        return;
    }
    int subx = (sx-x)/2, suby = (sy-y)/2;
    map<int,int> mp[2][2];
    vector<int> aa[2][2];
    int ctx = n/2;
    int cty = n-ctx;
    rep(i,0,n) {
        if(i%2) {
            if(sz(aa[0][0])<(ctx/2)) {
                aa[0][0].push_back(a[i]);
            } else {
                aa[0][1].push_back(a[i]);
            }
        } else {
            if(sz(aa[1][0])<(cty/2)) {
                aa[1][0].push_back(a[i]);
            } else {
                aa[1][1].push_back(a[i]);
            }
        }
    }
    rep(i,0,2) {
        rep(j,0,2) {
            mp[i][j][0] = 0;
            rep(k,0,sz(aa[i][j])) {
                vector<pii> temp;
                for(auto [key,val]: mp[i][j]) {
                    temp.push_back({key+aa[i][j][k], val+(1<<k)});
                }    
                for(auto [key,val]: temp) {
                    mp[i][j][key] = val;
                }
            }
        }
    }
    ll statex = -1;
    for(auto [k,v]: mp[0][0]) {
        if(mp[0][1].count(subx-k)) {
            statex = 1ll*v + 1ll*(mp[0][1][subx-k])*(1<<(sz(aa[0][0])));
            break;
        }
    }
    if(statex==-1) {
        cout <<"No\n";
        return;
    }
    ll statey = -1;
    for(auto [k,v]: mp[1][0]) {
        if(mp[1][1].count(suby-k)) {
            statey = 1ll*v + 1ll*(mp[1][1][suby-k])*(1<<(sz(aa[1][0])));
        }
    }
    if(statey == -1) {
        cout <<"No\n";
        return;
    }
    cout <<"Yes\n";
    int isPos = 1;
    int idx = 0, idy=0;
    // cout <<statex <<" " <<statey <<"\n";
    string ans = "";
    rep(i,0,n) {
        if(i%2) {
            int isPosNext = !((statex>>idx)&1);
            idx++;
            if(isPos!=isPosNext) {
                ans +='L';
            } else {
                ans +='R';
            }
            isPos = isPosNext;
        } else {
            int isPosNext = !((statey>>idy)&1);
            idy++;
            if(isPos==isPosNext) {
                ans +='L';
            } else {
                ans +='R';
            }
            isPos = isPosNext;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}