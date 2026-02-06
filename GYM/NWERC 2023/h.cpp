#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i< (b); ++i)
#define per(i, a, b) for(int i = a; i> (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
#define fi first
#define se second

const int mxn=1e5;
int n;

void solve() {
    cin >>n;
    int ct1 = 0,ct2=0;
    vi v;
    rep(i,0,n) {
        int ai; cin >>ai;
        if(ai==1) {
            ct1++;
        } else if(ai==2) {
            ct2++;
        } else {
            v.push_back(ai);
        }
    }
    sort(all(v),greater<int>());
    if(ct1>1) {
        vector<string> ans;
        int cur = 0;
        rep(i,0,min(ct1,ct2)) {
            ans.push_back("(2+1)");
        }
        rep(i,min(ct1,ct2),ct2) {
            ans.push_back("2");
        }
        ct1 -= min(ct1,ct2);
        if(ct1>0) {
            if((ct1%3)==1) { // kl 1 ga gagitu
                if(sz(ans)) {
                    ans[0] = "(" + ans[0] + "+1)";
                    cur += 1;
                } else {
                    ans.push_back("(1+1+1+1)");
                    cur += 4;
                }
            } else if((ct1%3)==2) {
                ans.push_back("(1+1)");
                cur += 2;
            }
            while(cur < ct1) {
                ans.push_back("(1+1+1)");
                cur += 3;
            }
        }
        rep(i,0,sz(v)) {
            ans.push_back(to_string(v[i]));
        }
        rep(i,0,sz(ans)) {
            cout <<ans[i];
            if(i+1<sz(ans)) cout <<"*";
        }
        cout <<"\n";
    } else {
        rep(i,0,ct2) {
            v.push_back(2);
        }
        if(sz(v)>0) {
            per(i,sz(v)-1,-1) {
                if(i==sz(v)-1) {
                    string ans;
                    if(ct1>0) {
                        ans = "(1+" + to_string(v[i]) +  ")";
                    } else {
                        ans = to_string(v[i]);
                    }
                    cout <<ans;
                } else {
                    cout <<"*" <<to_string(v[i]);
                }
            }
            cout <<"\n";
        } else {
            cout <<"1\n";
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    solve();
}