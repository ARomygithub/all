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
string s,t;
int q;

void solve() {
    cin >>s;
    cin >>t;
    cin >>q;
    vector<pii> prs(sz(s)+1,{0,0}), prt(sz(t)+1,{0,0});
    vi sb, tb;
    rep(i,1,sz(s)+1) {
        prs[i] = prs[i-1];
        if(s[i-1]=='A') {
            prs[i].se++;
        } else {
            sb.push_back(i);
            prs[i].fi++;
        }
    }
    rep(i,1,sz(t)+1) {
        prt[i] = prt[i-1];
        if(t[i-1]=='A') {
            prt[i].se++;
        } else {
            tb.push_back(i);
            prt[i].fi++;
        }
    }
    while(q--) {
        int a,b,c,d; cin >>a >>b >>c >>d;
        // cout <<s.substr(a-1,b-a+1) <<endl;
        // cout <<t.substr(c-1,d-c+1) <<endl;
        int dpn1 = b-a+1;
        if(sz(sb)) {
            int id1 = upper_bound(all(sb),b) - sb.begin(); id1--;
            if(id1>=0) {
                dpn1 = b - max(a-1,sb[id1]);
            }
        }
        int dpn2 = d-c+1;
        if(sz(tb)) {
            int id2 = upper_bound(all(tb),d) - tb.begin(); id2--;
            if(id2>=0) {
                dpn2 = d - max(c-1,tb[id2]);
            }
        }
        pii x = {prs[b].fi-prs[a-1].fi, prs[b].se-prs[a-1].se};
        pii y = {prt[d].fi-prt[c-1].fi, prt[d].se-prt[c-1].se};
        if(x.fi<y.fi && (x.fi%2)==(y.fi%2)) {
            if(dpn1>dpn2) {
                cout <<"1";
            } else {
                if(x.fi>0 && dpn1>=dpn2) {
                    cout <<"1";
                } else {
                    cout <<"0";
                }
            }
        } else {
            if(dpn1>=dpn2 && (dpn1%3)==(dpn2%3) && x.fi<=y.fi && (x.fi%2)==(y.fi%2)) {
                cout <<"1";
            } else {
                cout <<"0";
            }
        }
    }
    cout <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}