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

const int N = 1e6 + 9, B = 900;

struct query {
  int l, r, id;
  bool operator < (const query &x) const {
    if(l / B == x.l / B) return ((l / B) & 1) ? r > x.r : r < x.r;
    return l / B < x.l / B;
  }
} Q[N];
int a[N];
set<int> s;
multiset<int> ms;
void add(int idx) {
    if(sz(s)==0) {
        s.insert(a[idx]);
    } else if(sz(s)==1) {
        int x = *s.begin();
        ms.insert(abs(a[idx]-x));
        s.insert(a[idx]);
    } else {
        auto x = lower_bound(s.begin(),s.end(),a[idx]);
        if(x==s.begin()) {
            ms.insert(abs(*x-a[idx]));
            s.insert(a[idx]);
        } else {
            auto lx = --x; x++;
            if(x==s.end()) {
                ms.insert(abs(*lx-a[idx]));
                s.insert(a[idx]);
            } else {
                ms.erase(ms.find(abs(*x-*lx)));
                ms.insert(abs(a[idx]-*lx));
                ms.insert(abs(a[idx]-*x));
                s.insert(a[idx]);
            }
        }
    }
}
void rem(int idx) {
    auto x = upper_bound(s.begin(),s.end(),a[idx]);
    if(x==s.end()) {
        if(sz(s)>=2) {
            x--,x--;
            ms.erase(ms.find(abs(a[idx]-*x)));
            s.erase(a[idx]);
        } else {
            s.erase(a[idx]);
        }
    } else {
        int rx =*x;
        ms.erase(ms.find(abs(rx-a[idx])));
        x--;
        if(x==s.begin()) {
            s.erase(a[idx]);
        } else {
            x--;
            ms.erase(ms.find(abs(a[idx]-*x)));
            ms.insert(abs(rx-*x));
            s.erase(a[idx]);
        }
    }
}
int ans[N];

int n,q;

// https://codeforces.com/contest/765/submission/84902852

void solve() {
    cin >>n >>q;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    for(int i=0;i<q;i++) {
        cin >>Q[i].l >>Q[i].r; Q[i].l--, Q[i].r--;
        Q[i].id = i;
    }
    sort(Q,Q+q);
    int cur_l = 0,cur_r=-1;
    for(int i=0;i<q;i++) {
        while(cur_l > Q[i].l) {
            cur_l--;
            add(cur_l);
        }
        while(cur_r < Q[i].r) {
            cur_r++;
            add(cur_r);
        }
        while(cur_l<Q[i].l) {
            rem(cur_l);
            cur_l++;
        }
        while(cur_r>Q[i].r) {
            rem(cur_r);
            cur_r--;
        }
        ans[Q[i].id] = *ms.begin();
    }
    for(int i=0;i<q;i++) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}