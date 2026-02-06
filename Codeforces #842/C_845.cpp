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

const int mxn=1e5;
int n,m,t;
vector<int> v[mxn+1];
int a[mxn];

void solve() {
    cin >>n >>m;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    sort(a,a+n);
    int ans=1e9;
    int l=0, r=1e5-1;
    while (l<=r)
    {
        int mid = (l+r)/2;
        vector<int> ct(m+1,0);
        set<int> s;
        int li=0;
        for(auto vi: v[a[0]]) {
            if(vi>m) break;
            ct[vi]++;
            s.insert(vi);
        }
        if(sz(s)==m) {
            ans = mid;
            r = mid-1;
            continue;
        }
        bool flag=0;
        for(int i=1;i<n;i++) {
            for(auto vi: v[a[i]]) {
                if(vi>m) break;
                ct[vi]++;
                if(ct[vi]==1) {
                    s.insert(vi);
                }
            }
            while(a[i]-a[li]>mid) {
                for(auto vi: v[a[li]]) {
                    if(vi>m) break;
                    ct[vi]--;
                    if(ct[vi]==0) {
                        s.erase(vi);
                    }
                }
                li++;
            }
            if(sz(s)==m) {
                ans = mid;
                r = mid-1;
                flag=1;
                break;
            }
        }
        if(!flag) {
            l = mid+1;
        }
    }
    if(ans==1e9) {
        cout <<"-1\n";
    } else {
        cout <<ans <<"\n";
    }
}

void init() {
    for(int i=1;i<=mxn;i++) {
        for(int j=i;j<=mxn;j+=i) {
            v[j].push_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >>t;
    while(t--) {
        solve();
    }
}