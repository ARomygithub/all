#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n;
int p[mxn+1], q[mxn+1], ip[mxn+1],iq[mxn+1];

void solve() {
    cin >>n;
    for(int i=1;i<=n;i++) {
        cin >>p[i];
        ip[p[i]] = i;
    }
    for(int i=1;i<=n;i++) {
        cin >>q[i];
        iq[q[i]] = i;
    }
    vector<pii> pp(n+1),qq(n+1);
    for(int i=1;i<=n;i++) {
        pp[i] = {ip[i],ip[i]};
        if(i>1) min_self(pp[i].fi,pp[i-1].fi);
        if(i>1) max_self(pp[i].se,pp[i-1].se);
    }
    for(int i=1;i<=n;i++) {
        qq[i] = {iq[i],iq[i]};
        if(i>1) min_self(qq[i].fi,qq[i-1].fi);
        if(i>1) max_self(qq[i].se,qq[i-1].se);
    }
    ll ans=0;
    for(int i=1;i<=n+1;i++) {
        if(i==1) {
            int x = min(pp[1].fi,qq[1].fi), y = max(pp[1].fi,qq[1].fi);
            ans += 1ll*(x-1)*(x)/2;
            ans += 1ll*(n-y)*(n-y+1)/2;
            ans += 1ll*(y-x-1)*(y-x)/2;
            // cout <<ans <<"\n";
        } else if(i==n+1) {
            ans +=1ll;
        } else {
            int li=min(pp[i-1].fi,qq[i-1].fi), ri = max(pp[i-1].se,qq[i-1].se);
            int x=0, y = n+1;
            if(ip[i]>=li && ip[i]<=ri) {
                continue;
            } else if(ip[i]<li) {
                max_self(x,ip[i]);
            } else if(ip[i]>ri) {
                min_self(y,ip[i]);
            }
            if(iq[i]>=li && iq[i]<=ri) {
                continue;
            } else if(iq[i]<li) {
                max_self(x,iq[i]);
            } else if(iq[i]>ri) {
                min_self(y,iq[i]);
            }
            ans +=1ll*(li-x)*(y-ri);
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