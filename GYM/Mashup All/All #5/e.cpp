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
int n;
ll p;
ll t[mxn];

void solve() {
    cin >>n >>p;
    rep(i,0,n) {
        cin >>t[i];
    }
    vector<pii> awl;
    rep(i,0,n) {
        awl.push_back({t[i],i});
    }
    sort(all(awl));
    set<int> siap, sq;
    queue<pll> q;
    vector<ll> ans(n,-1);
    for(int i=0;i<n;) {
        int j = i;
        while(j<n && awl[j].fi==awl[i].fi) {
            j++;
        }
        while(sz(q) && q.front().se+p<=awl[i].fi) {
            auto [iq,ti] = q.front(); q.pop();
            ans[iq] = ti+p;
            sq.erase(iq);
            if(sz(q)) {
                q.front().se = ti+p;
            }
            if(ti+p<awl[i].fi && sz(siap)) {
                auto it = siap.begin();
                if(!(sz(sq) && (*sq.begin())<(*it))) {
                    q.push({*it,ti+p});
                    sq.insert(*it);
                    siap.erase(it);
                }
            }
        }
        rep(k,i,j) {
            auto [ti, ai] = awl[k];
            siap.insert(ai); 
        }
        if(sz(siap)) {
            auto it = siap.begin();
            if(!(sz(sq) && (*sq.begin())<(*it))) {
                q.push({*it,awl[i].fi});
                sq.insert(*it);
                siap.erase(it);
            }            
        }
        i = j;
    }
    while(sz(q)) {
        auto [iq,ti] = q.front(); q.pop();
        ans[iq] = ti+p;
        sq.erase(iq);
        if(sz(q)) {
            q.front().se = ti+p;
        }      
        if(sz(siap)) {
            auto it = siap.begin();
            if(!(sz(sq) && (*sq.begin())<(*it))) {
                q.push({*it,ti+p});
                sq.insert(*it);
                siap.erase(it);
            }            
        }        
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}