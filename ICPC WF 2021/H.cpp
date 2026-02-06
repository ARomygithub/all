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
typedef pair<pii,int> piii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n;

int val(char x) {
    return (x=='('?1:-1);
}

void solve() {
    cin >>n;
    vector<string> v(n);
    rep(i,0,n) {
        cin >>v[i];
    }
    vector<piii> v2(n);
    rep(i,0,n) {
        v2[i].se = i;
        int mn = 0, s=0;
        rep(j,0,sz(v[i])) {
            s += val(v[i][j]);
            min_self(mn, s);
        }
        v2[i].fi = {mn,s};
    }
    sort(v2.begin(),v2.end());
    int idx = n-1;
    ll s_now = 0;
    priority_queue<piii> pq;
    set<piii> st;
    vector<int> ans;
    while(true) {
        while(idx>=0 && v2[idx].fi.fi+s_now>=0) {
            pq.push({{v2[idx].fi.se,v2[idx].fi.fi},v2[idx].se});
            st.insert({{v2[idx].fi.fi-v2[idx].fi.se, v2[idx].fi.se},v2[idx].se});
            idx--;
        }
        if(sz(pq) && pq.top().fi.fi>=0) {
            auto cur = pq.top(); pq.pop();
            swap(cur.fi.fi,cur.fi.se);
            s_now += cur.fi.se;
            ans.push_back(cur.se);
            auto [mns, id] = cur;
            auto [mn, s] = mns;
            st.erase({{mn-s,s},id});
        } else {
            break;
        }
    }
    if(idx>=0) {
        cout <<"impossible\n";
        return;
    }
    for(auto cur : st) {
        auto [mnss, id] = cur;
        auto [mns, s] = mnss;
        if(s_now+ s< mns*(-1)) {
            cout <<"impossible\n";
            return;
        }
        s_now += s;
        ans.push_back(id);
    }
    if(s_now!=0) {
        cout <<"impossible\n";
        return;
    }
    ll tes = 0;
    sort(v2.begin(),v2.end(),[&](piii a, piii b) -> bool {
        return a.se<b.se;
    });
    rep(i,0,n) {
        assert(tes+v2[ans[i]].fi.fi>=0);
        tes += v2[ans[i]].fi.se;
        cout <<ans[i]+1 <<"\n";
    }
    assert(tes==0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}