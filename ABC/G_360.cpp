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

const int mxn=2e5;
int n;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<int> v;
    vector<vector<pii>> elm;
    rep(i,0,n) {
        auto it = lower_bound(v.begin(),v.end(),a[i]);
        if(it==v.end()) {
            v.push_back(a[i]);
            vector<pii> elmi(1,{i,a[i]});
            elm.push_back(elmi);
        } else {
            *it = a[i];
            elm[it-v.begin()].push_back({i,a[i]});
        }
    }
    int ans = sz(v);
    per(i,sz(v),-1) {
        if(i==sz(v)) {
            for(auto [pos,val]: elm[i-1]) {
                if(pos<n-1) {
                    ans++;
                    cout <<ans <<"\n";
                    return;
                }
            }
            continue;
        }
        if(i==0) {
            for(auto [pos,val]: elm[i]) {
                if(pos>0) {
                    ans++;
                    cout <<ans <<"\n";
                    return;
                }
            }
            continue;
        }
        vector<pii> reached;
        rep(ib,0,sz(elm[i])) {
            int li = 0, ri=sz(elm[i-1])-1;
            int ia = -1;
            while(li<=ri) {
                int mid = (li+ri)/2;
                if(elm[i-1][mid].fi>elm[i][ib].fi-2) {
                    ri = mid-1;
                    continue;
                }
                if(elm[i-1][mid].se<=elm[i][ib].se-2) {
                    ia = mid;
                    break;
                } else {
                    li = mid+1;
                }
            }
            if(ia!=-1) {
                ans++;
                cout <<ans <<"\n";
                return;
            }
            li = 0, ri=sz(elm[i-1])-1;
            int ial=-1;
            while(li<=ri) {
                int mid = (li+ri)/2;
                if(elm[i-1][mid].fi>elm[i][ib].fi-1) {
                    ri = mid-1;
                    continue;
                }
                if(elm[i-1][mid].se <= elm[i][ib].se-1) {
                    ial = mid;
                    ri = mid-1;
                } else {
                    li = mid+1;
                }
            }
            li = 0, ri=sz(elm[i-1])-1;
            int iar = -1;
            while(li<=ri) {
                int mid = (li+ri)/2;
                if(elm[i-1][mid].fi>elm[i][ib].fi-1) {
                    ri = mid-1;
                    continue;
                }
                if(elm[i-1][mid].se<=elm[i][ib].se-1) {
                    iar = mid;
                    li = mid+1;
                } else {
                    li = mid+1;
                }
            }
            reached.push_back({ial,iar});
        }
        int idx = 0;
        vector<pii> elmi_new;
        rep(ia,0,sz(elm[i-1])) {
            bool ok = 1;
            while(!(reached[idx].fi<=ia && ia<=reached[idx].se)) {
                if(reached[idx].fi>ia || idx+1>=sz(reached)) {
                    ok = 0;
                    break;
                } else {
                    idx++;
                }
            }
            if(ok) {
                elmi_new.push_back(elm[i-1][ia]);
            }
        }
        elm[i-1].swap(elmi_new);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}