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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e2,mxm=5e5;
int n;
int r[mxn];

void solve() {
    cin >>n;
    int s=0;
    rep(i,0,n) {
        cin >>r[i];
        s +=r[i];
    }
    if(s%2) {
        cout <<"NO\n";
        return;
    }
    int mid = s/2;
    int ct1 = 1 + (n)/2;
    int ct11 = (ct1+1)/2, ct12 = ct1-ct11;
    vector<bool> b11(mid+1,0),b12(mid+1,0);
    vector<int> v11, v12;
    v11.push_back(r[0]);
    for(int i=1;i<n;i+=2) {
        int temp = r[i];
        if(i+1<n) r[i] +=r[i+1];
        if(sz(v11)<ct11) {
            v11.push_back(temp);
        } else {
            v12.push_back(temp);
        }
    }
    rep(i,0,(1<<ct11)) {
        int temp = 0;
        rep(j,0,ct11) {
            if((i>>j)&1) {
                temp +=v11[j];
            }
        }
        if(temp<=mid) {
            b11[temp] = 1;
        }
    }
    rep(i,0,(1<<ct12)) {
        int temp = 0;
        rep(j,0,ct12) {
            if((i>>j)&1) {
                temp +=v12[j];
            }
        }
        if(temp<=mid) {
            b12[temp] = 1;
        }
    }
    bool flag = 0;
    rep(i,0,mid+1) {
        flag |= (b11[i] && b12[mid-i]);
    }
    if(!flag) {
        cout <<"No\n";
        return;
    }
    int ct2 = (n+1)/2;
    int ct21 = (ct2+1)/2, ct22 = ct2-ct21;
    vector<bool> b21(mid+1,0), b22(mid+1,0);
    vector<int> v21,v22;
    for(int i=0;i<n;i+=2) {
        int temp = r[i];
        if(i+1<n) temp +=r[i+1];
        if(sz(v21)<ct21) {
            v21.push_back(temp);
        } else {
            v22.push_back(temp);
        }
    }
    rep(i,0,(1<<ct21)) {
        int temp = 0;
        rep(j,0,ct21) {
            if((i>>j)&1) {
                temp += v21[j];
            }
        }
        if(temp <= mid) {
            b21[temp] = 1;
        }
    }
    rep(i,0,(1<<ct22)) {
        int temp = 0;
        rep(j,0,ct22) {
            if((i>>j)&1) {
                temp += v22[j];
            }
        }
        if(temp <= mid) {
            b22[temp] = 1;
        }
    }
    flag = 0;
    rep(i,0,mid+1) {
        flag |= (b21[i] && b22[mid-i]);
    }
    if(!flag) {
        cout <<"No\n";
    } else {
        cout <<"Yes\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}