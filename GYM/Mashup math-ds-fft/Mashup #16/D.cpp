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
ll p,q;
using ps = pair<string,string>;

void solve() {
    cin >>p >>q;
    // str (-9,x)
    vector<ps> ans(19);
    ans[18].fi = "0-9";
    ans[18].se = ans[18].fi;
    reverse(all(ans[18].se));
    ps min2 = {"1-1-0","0-1-1"};
    for(int i=16;i>=0;i-=2) {
        ans[i].fi = ans[i+2].fi;
        ans[i].fi += '+';
        ans[i].fi += min2.fi;
        ans[i].se = ans[i].fi;
        reverse(all(ans[i].se));
    }
    ans[9].fi = "23";
    rep(i,0,4) {
        ans[9].fi += '+';
        ans[9].fi += ans[0].fi;
    }
    ans[9].fi += "+4";
    ans[9].se = ans[9].fi;
    reverse(all(ans[9].se));
    for(int i=7;i>=0;i-=2) {
        ans[i].fi = ans[i+2].fi;
        ans[i].fi += '+';
        ans[i].fi += min2.fi;
        ans[i].se = ans[i].fi;
        reverse(all(ans[i].se));        
    }
    ps ad2 = {"1+0-1","1-0+1"};
    for(int i=11;i<=18;i+=2) {
        ans[i].fi = ans[i-2].fi;
        ans[i].fi += '+';
        ans[i].fi += ad2.fi;
        ans[i].se = ans[i].fi;
        reverse(all(ans[i].se));
    }
    // parse p,q ke v
    string ret = "";
    vi vp,vq;
    bool negp = (p<0);
    bool negq = (q<0);
    p = abs(p), q= abs(q);
    while(p) {
        vp.push_back((p%9)*(negp?-1:1));
        p /= 9;
    }
    if(sz(vp)==0) vp.push_back(0);
    while(q) {
        vq.push_back((q%9)*(negq?-1:1));
        q /= 9;
    }
    if(sz(vq)==0) vq.push_back(0);
    per(i,max(sz(vp),sz(vq))-1,-1) {
        pii cur = {0,0};
        if(i<sz(vp)) {
            cur.fi = vp[i];
        }
        if(i<sz(vq)) {
            cur.se = vq[i];
        }
        int dif = cur.se-cur.fi;
        string mul = "";
        rep(j,0,i) {
            mul +="*9";
        }
        if(dif<0) {
            int szi = sz(ans[abs(dif)].se);
            rep(j,0,sz(ans[abs(dif)].se)) {
                char cc = j+1==szi?'+':ans[abs(dif)].se[j+1];
                ret += ans[abs(dif)].se[j];
                if(j+1==szi || (cc=='+' || cc=='-')) {
                    ret += mul;
                }
            }
        } else {
            int szi = sz(ans[abs(dif)].fi);
            rep(j,0,sz(ans[abs(dif)].fi)) {
                char cc = j+1==szi?'+':ans[abs(dif)].fi[j+1];
                ret += ans[abs(dif)].fi[j];
                if(j+1==szi || (cc=='+' || cc=='-')) {
                    ret += mul;
                }
            }
        }
        int kurg = 0;
        if(dif<0) {
            kurg = cur.se + 9;
        } else {
            kurg = cur.fi + 9;
        }
        while(kurg>0) {
            int temp = min(kurg,9);
            kurg -= temp;
            ret += '+';
            ret += (char)(temp + '0');
            ret += mul;
        }
        if(i>0) {
            ret += '+';
        }
    }
    cout <<ret <<"\n";
    cout <<sz(ret) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}