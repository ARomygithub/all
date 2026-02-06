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

string ask(int r1, int c1, int r2, int c2) {
    // assert((r2>=r1) && (c2>=c1));
    // assert(r2-r1+c2-c1>=n-1);
    cout <<"? " <<r1 <<" " <<c1 <<" " <<r2 <<" " <<c2 <<"\n";
    cout <<flush;
    string ret; cin >>ret;
    return ret;
}

void solve() {
    cin >>n;
    string ans = "";
    pii u = {1,1};
    // vector<pii> vu;
    while(u.fi!=n || u.se!=n) {
        // vu.push_back(u);
        vector<pii> tmp;
        if(u.fi<n) {
            tmp.push_back({u.fi+1,u.se});
        }
        if(u.se<n) {
            tmp.push_back({u.fi,u.se+1});
        }
        if(abs(tmp[0].fi-n)+abs(tmp[0].se-n)<n-1) {
            break;
        }
        pii r = {n,n};
        for(auto un: tmp) {
            auto [mn,mx] = minmax(un,r);
            auto ret = ask(mn.fi,mn.se,mx.fi,mx.se);
            assert(ret[0]!='B');
            if(ret[0]=='Y') {
                if(un.fi-u.fi>0) {
                    ans += 'D';
                } else {
                    ans += 'R';
                }
                u = un;
                break;
            }
        }
    }
    string ans2 = "";
    pii u1 = {n,n};
    while(u1!=u) {
        vector<pii> tmp;
        if(u1.se>1) {
            tmp.push_back({u1.fi,u1.se-1});
        }
        if(u1.fi>1) {
            tmp.push_back({u1.fi-1,u1.se});
        }
        pii r = {1,1};
        for(auto un : tmp) {
            auto [mn,mx] = minmax(un,r);
            string ret = ask(mn.fi,mn.se,mx.fi,mx.se);
            if(ret[0]=='Y') {
                if(u1.fi-un.fi!=0) {
                    ans2 += 'D';
                } else {
                    ans2 += 'R';
                }
                u1 = un;
                break;
            }
        }
    }
    per(i,sz(ans2)-1,-1) {
        ans += ans2[i];
    }
    // int ctd = 0,ctr=0;
    // for(auto c : ans) {
    //     if(c=='D') {
    //         ctd++;
    //     } else if(c=='R') {
    //         ctr++;
    //     }
    // }
    // assert(ctd==n-1);
    // assert(ctr==n-1);
    // assert(u.fi==n && u.se==n);
    cout <<"! " <<ans <<"\n";
    cout <<flush;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}