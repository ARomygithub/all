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
string s;

void solve() {
    cin >>s;
    const int mxk = 100;
    vector<int> pref(sz(s)+1,0);
    ll ans = 0;
    rep(i,0,sz(s)) {
        pref[i+1] = pref[i]+(s[i]-'0');
    }
    rep(k,1,mxk+1) {
        map<int,int> mp;
        rep(i,0,sz(pref)) {
            int cur = k*pref[i]-i;
            ans += mp[cur];
            mp[cur]++;
        }
    }
    vector<int> v;
    int tmp = 0;
    rep(i,0,sz(s)) {
        if(s[i]=='1') {
            v.push_back(tmp);
            tmp = 0;
        } else {
            tmp++;
        }
    }
    v.push_back(tmp);
    rep(len,1,2001) {
        int sm = 0;
        int l=0;
        rep(i,0,sz(v)) {
            if(i-l<=len) {
                sm += v[i];
            } else {
                sm += v[i];
                sm -= v[l];
                l++;
            }
            if(i-l==len) {
                if(sm+len<=mxk*len) continue;
                rep(j,0,v[i]+1) {
                    int cur = sm-v[i]-v[l];
                    if(v[l]+cur+j+len<=mxk*len) continue;
                    int minl = (len - (cur+j)%len)%len;
                    max_self(minl, (mxk+1)*len - (cur+j+len));
                    if(v[l]>=minl) {
                        ans += (v[l]-minl)/len+1;
                    }
                }
            }
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}