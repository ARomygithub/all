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
int n,k,t;
string s,a,b;

bool doAns(vi& pi, vi& ipi, int id, int md) {
    int l = -1, r = k;
    if(md==0 || md==1) {
        l = a[id]-'a';
    }
    if(md==0 || md==2) {
        r = b[id]-'a';
    }
    // l,r, udh
    auto cur = [&](int nc) -> bool {
        int c = s[id]-'a';
        if(ipi[nc]!=-1 && ipi[nc]!=c) return 0;
        if(nc>=l && nc<=r) {
            int pic = pi[c];
            int ipinc = ipi[nc];
            pi[c] = nc;
            ipi[nc] = c;
            if(nc>l && nc<r) {
                return true;
            }
            if(id+1<n) {
                int nmd = md;
                if(nmd==0 && nc>l) {
                    nmd = 2;
                }
                if(nmd==0 && nc<r) {
                    nmd = 1;
                }
                bool ok = doAns(pi,ipi,id+1,nmd);
                if(ok) {
                    return true;
                } else {
                    pi[c] = pic;
                    ipi[nc] = ipinc;
                    return false;
                }
            } else {
                return true;
            }
        } else {
            return false;
        }
    };
    if(pi[s[id]-'a']!=-1) {
        return cur(pi[s[id]-'a']);
    }
    rep(c,l+1,r) {
        if(ipi[c]==-1) {
            ipi[c] = s[id]-'a';
            pi[s[id]-'a'] = c;
            return true;
        }
    }
    if(l>=0 && cur(l)) return 1;
    if(r<k && cur(r)) return 1;
    return 0;
}

void solve() {
    cin >>k;
    cin >>s;
    cin >>a;
    cin >>b;
    n = sz(s);
    vi p(k,-1), ip(k,-1);
    bool ok = doAns(p,ip,0,0);
    if(ok) {
        cout <<"YES\n";
        vi sblm, tblm;
        rep(i,0,k) {
            if(p[i]==-1) {
                sblm.push_back(i);
            }
            if(ip[i]==-1) {
                tblm.push_back(i);
            }
        }
        // assert(sz(sblm))
        rep(i,0,sz(sblm)) {
            p[sblm[i]] = tblm[i];
        }
        string ans = "";
        rep(i,0,k) {
            ans += (char)('a'+p[i]);
        }
        cout <<ans <<"\n";
    } else {
        cout <<"NO\n";
    }
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