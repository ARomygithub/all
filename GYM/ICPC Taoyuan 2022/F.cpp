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

const int mxn=3e5;
int n,t;
int a[mxn*2-1],b[mxn*2-1];

void cek() {
    vi vc;
    rep(i,0,n*2-1) {
        assert(a[i]>0);
        assert(a[i]==b[i] || b[i]==0);
        if(sz(vc)<2) {
            vc.push_back(a[i]);
        } else {
            if(vc[sz(vc)-2]==a[i]) {
                vc.pop_back();
            } else {
                vc.push_back(a[i]);
            }
        }        
    }
    assert(sz(vc)==1);
    assert(vc[0]==1);
}

void solve() {
    cin >>n;
    rep(i,0,n*2-1) {
        cin >>a[i];
        b[i] = a[i];
    }
    set<int> blm;
    rep(i,1,n+1) {
        blm.insert(i);
    }
    a[0] =1, a[n*2-2] = 1;
    vi vl,vr;
    int id0 = -1;
    rep(i,0,n*2-1) {
        if(a[i]==0) {
            id0 = i;
            break;
        }
        blm.erase(a[i]);
        if(sz(vl)<2) {
            vl.push_back(a[i]);
        } else {
            if(vl[sz(vl)-2]==a[i]) {
                vl.pop_back();
            } else {
                vl.push_back(a[i]);
            }
        }
    }
    int id0r = -1;
    per(i,n*2-2,-1) {
        if(a[i]==0) {
            id0r = i;
            break;
        }
        blm.erase(a[i]);
        if(sz(vr)<2) {
            vr.push_back(a[i]);
        } else {
            if(vr[sz(vr)-2]==a[i]) {
                vr.pop_back();
            } else {
                vr.push_back(a[i]);
            }
        }
    }
    vector<bool> fl(n+1,0),fr(n+1,0);
    vi idl(n+1,-1), idr(n+1,-1);
    rep(i,0,sz(vl)) {
        fl[vl[i]] = 1;
        idl[vl[i]] = i;
    }
    rep(i,0,sz(vr)) {
        fr[vr[i]] = 1;
        idr[vr[i]] = i;
    }
    vi str;
    stack<int> st;
    per(i,sz(vl)-1,-1) {
        if(fr[vl[i]]) {
            str.push_back(vl[i]);
            int idri = idr[vl[i]];
            rep(j,idri+1,sz(vr)) {
                str.push_back(vr[j]);
            }
            break;
        } else {
            str.push_back(vl[i]);
        }
    }
    per(i,sz(str)-1,-1) {
        st.push(str[i]);
    }
    auto prv = [&]() -> int {
        // par, nxt. -1 if abis
        if(sz(st)>1) {
            auto u = st.top(); st.pop();
            auto ret = st.top();
            st.push(u);
            return ret;
        } else {
            return -1;
        }
    };
    if(id0!=-1) {
        int x0=id0;
        int u = st.top();
        int pr = prv();
        while(x0<=id0r) {
            if(sz(blm)) {
                int blmi = (*blm.begin());
                if(pr!=-1 && pr<blmi) {
                    a[x0] = pr;
                    x0++;
                    u = pr;
                    st.pop();
                    pr = prv();
                } else {
                    a[x0] = blmi;
                    st.push(blmi);
                    blm.erase(blmi);
                    u = blmi;
                    pr = prv();
                    x0++;
                }
            } else {
                a[x0] = pr;
                u = pr;
                st.pop();
                pr = prv();
                x0++;
            }
        }
    }
    rep(i,0,n*2-1) {
        cout <<a[i] <<" \n"[i==n*2-2];
    }
    // cout <<flush;
    // cek();
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