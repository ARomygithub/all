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

const int mxn=2e3;
int n;
string s,t;

void solve() {
    cin >>n;
    cin >>s >>t;
    vi cts(26,0), ctt(26,0);
    rep(i,0,n) {
        cts[s[i]-'a']++;
        ctt[t[i]-'a']++;
    }
    rep(i,0,26) {
        if(cts[i]!=ctt[i]) {
            cout <<"-1\n";
            return;
        }
    }
    // cout <<s.substr(0,0) <<endl;
    vi ans;
    bool rev = 0;
    int l = (n/2)-1, r=l+1;
    string u = s;
    auto mv = [&](int sh) -> void {
        if(sh==0) return;
        ans.push_back(sh);
        string bt = u.substr(n-sh,sh);
        reverse(all(bt));
        u = bt + u.substr(0,n-sh);
    };
    while(l>=0 && r<n) {
        char x = rev?t[r]:t[l];
        char y = rev?t[l]:t[r];
        int ix = -1;
        rep(i,0,n) {
            if(u[i]==x) {
                ix = i;
                break;
            }
        }
        mv(n-ix-1);
        mv(n);
        mv(r-l-1);
        int iy = -1;
        per(i,n-1,-1) {
            if(u[i]==y) {
                iy = i;
                break;
            }
        }
        mv(n-iy);
        mv(iy-r+l);
        rev ^=1;
        l--, r++;
        // cout <<u <<endl;
    }
    if(l>=0) {
        if(rev) {
            // cout <<l <<endl;
            mv(n-1);
            mv(1);
            rev ^= 1;
        }
        l--;
    }
    // cout <<u <<endl;
    if(r<n) {
        if(!rev) {
            mv(n);
            mv(1);
            rev ^= 1;
        }
        r++;
    }
    // cout <<u <<endl;
    if(rev) {
        mv(n);
    }
    // cout <<u <<endl;
    assert(u==t);
    cout <<sz(ans) <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i] <<" \n"[i==sz(ans)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}