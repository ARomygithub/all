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

const int mxn=1e6;
const int inf=1e9;
int n,t;
int a[mxn+1];

namespace SA {
    const int mxm = 1e6;
    int rk[mxm], sa[mxm], height[mxm];

    void pre(int *r, int n, int m) {
        static int _sa[mxm], ai[mxm], bi[mxm], cnt[mxm];
        for(int i=0;i<=m;i++) {
            cnt[i] = 0;
        }
        for(int i=1;i<=n;i++) {
            cnt[r[i]]++;
        }
        for(int i=1;i<=m;i++) {
            cnt[i] +=cnt[i-1];
        }
        for(int i=n;i>=1;i--) {
            sa[cnt[r[i]]--] = i;
        }
        rk[sa[1]] = 1;
        for(int i=2;i<=n;i++) {
            rk[sa[i]] = rk[sa[i-1]]+(r[sa[i]]!=r[sa[i-1]]);
        }

        for(int l=1;l<n&&(m=rk[sa[n]])<n;l<<=1) {
            for(int i=1;i<=n;i++) ai[i]=(i+l<=n)?rk[i+l]:0;
            for(int i=1;i<=n;i++) bi[i] = rk[i];
            int p=0;
            for(int i=n-l+1;i<=n;i++) _sa[++p] = i;
            for(int i=1;i<=n;i++) {
                if(sa[i]>l) _sa[++p]=sa[i]-l;
            }
            for(int i=0;i<=m;i++) {
                cnt[i]=0;
            }
            for(int i=1;i<=n;i++) {
                cnt[bi[_sa[i]]]++;
            }
            for(int i=1;i<=m;i++) {
                cnt[i] +=cnt[i-1];
            }
            for(int i=n;i>=1;i--) {
                sa[cnt[bi[_sa[i]]]--] = _sa[i];
            }
            rk[sa[1]] = 1;
            for(int i=2;i<=n;i++) {
                rk[sa[i]] = rk[sa[i-1]]+(ai[sa[i]]!=ai[sa[i-1]]||bi[sa[i]]!=bi[sa[i-1]]);
            }
        }
        for(int i=1;i<=n;i++) {
            if(rk[i]==1) {
                height[rk[i]] = 0;
                continue;
            }
            int l = max(0,height[rk[i-1]]-1), p=sa[rk[i]-1];
            for(;max(i,p)+l<=n&&a[i+l]==a[p+l];l++);
            height[rk[i]] = l;
        }
    }
}
using namespace SA;

struct node {
    int v,cnt,l;
    ll val;
};
int top;
node stk[mxn];
ll sum[mxn];

int find(int x) {
    int l=0,r=top,res=0;
    while(l<=r) {
        int mid=(l+r)/2;
        if(stk[mid].l>x) {
            res = mid, l = mid+1;
        } else {
            r = mid-1;
        }
    }
    return res;
}

void solve() {
    cin >>n;
    int mx = 0;
    for(int i=1;i<=n;i++) {
        cin >>a[i];
        max_self(mx,a[i]);
    }
    pre(a,n,mx);
    stk[top=0]= (node) {inf,0,n+1,0};
    ll ans = 0;
    for(int i=n;i>=1;i--) {
        while(top>0&&stk[top].v<=a[i]) top--;
        stk[top+1] = (node) {a[i],stk[top].l-i,i,1ll*(stk[top].l-i)*a[i]};
        top++;
        sum[top] = sum[top-1] + stk[top].val;

        int s = rk[i], h=height[s];
        int st = i+h;
        int nr = find(st);
        ans += sum[nr]+1ll*stk[nr+1].v*(stk[nr].l-st);
    }
    cout <<ans <<"\n";
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