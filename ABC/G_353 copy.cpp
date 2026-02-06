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
typedef pair<int,ll> pil;
typedef pair<pii,pil> piil;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
ll n,c, m;
ll t[mxn],p[mxn];

void solve() {
    cin >>n >>c;
    cin >>m;
    rep(i,0,m) {
        cin >>t[i] >>p[i];
        t[i]--;
    }
    set<piil> st;
    rep(i,0,n) {
        st.insert({{i,i},{i,0ll}});
    }
    auto get_i = [&](int i) -> ll {
        auto it = st.upper_bound({{i,n},{0ll,0ll}});
        it--;
        return it->se.se - c*abs(it->se.fi-i);
    };
    per(i,m-1,-1) {
        ll qry = get_i(t[i]) + p[i];
        int le = t[i];
        int ri = t[i];
        int l = 0, r = le;
        while(l<r) {
            int mid = (l+r)/2;
            ll val = get_i(mid);
            if(val < qry - c*abs(t[i]-mid)) {
                le = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        l = ri, r = n-1;
        while(l<r) {
            int mid = (l+r)/2;
            ll val = get_i(mid);
            if(val < qry - c*abs(t[i]-mid)) {
                ri = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        vector<piil> v;
        auto it = st.upper_bound({{le,n},{0,0ll}});
        it--;
        if(it->fi.fi < le) {
            v.push_back({{it->fi.fi,le-1},it->se});
        }
        it = st.upper_bound({{ri,n},{0,0ll}});
        it--;
        if(it->fi.se > ri) {
            v.push_back({{ri+1,it->fi.se},it->se});
        }
        vector<piil> erase;
        it = st.upper_bound({{le,n},{0,0ll}});
        it--;
        while(it!=st.end() && it->fi.fi <= ri) {
            erase.push_back(*it);
            it++;
        }
        for(auto itt: erase) {
            st.erase(itt);
        }
        for(auto itt: v) {
            st.insert(itt);
        }
        st.insert({{le,ri},{t[i],qry}});
        // cout <<le <<" " <<ri <<" " <<qry <<endl;
    }
    cout <<get_i(0) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}