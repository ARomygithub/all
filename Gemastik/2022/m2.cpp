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

const int mxn=3e5;
int n,t;
int a[mxn];

template<typename T>
int sgn(T A) { return (A>0) - (A<0); }

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vi pos;
    auto cek = [&]() -> void {
        rep(i,1,n) {
            if(a[i]==a[i-1]) {
                pos.push_back(i);
            } else {
                int i2 = i-2;
                if(sz(pos) && pos.back()>i-2) {
                    continue;
                }
                if(i2>=0 && sgn(a[i]-a[i-1])==sgn(a[i-1]-a[i2])) {
                    pos.push_back(i);
                }
            }
        }
    };
    cek();
    if(sz(pos)>2) {
        cout <<"-1 -1\n";
    } else if(sz(pos)==2) {
        int l = pos[0], r = pos[1];
        rep(i,0,2) {
            rep(j,0,2) {
                int li = l-i, ri = r-j;
                if(li==ri) continue;
                // cout <<li <<" " <<ri <<endl; 
                pos.clear();
                reverse(a+li,a+ri); // [li,ri-1]
                cek();
                reverse(a+li,a+ri);
                if(sz(pos)==0) {
                    cout <<li+1 <<" " <<ri <<"\n";
                    return;
                }
            }
        }
        cout <<"-1 -1\n";
    } else if(sz(pos)==1) {
        int idx = pos[0];
        vi v = {1,-1};
        rep(od,0,2) {
            rep(i,0,n) {
                if(i<idx) {
                    if(idx+1<n && sgn(a[idx+1]-a[idx])!=v[(idx+1+od)%2]) {
                        continue;
                    }
                    if(sgn(a[idx]-a[i])!= v[(idx+od)%2]) {
                        continue;
                    }
                    if(i+1<idx && sgn(a[i]-a[i+1])!= v[(idx-1+od)%2]) {
                        continue;
                    }
                    if(1<i && sgn(a[1]-a[0])!= v[(1+od)%2]) {
                        continue;
                    }
                    if(i-1>=0 && sgn(a[idx-1]-a[i-1])!= v[(i+od)%2]) {
                        continue;
                    }
                    pos.clear();
                    reverse(a+i,a+idx);
                    cek();
                    assert(sz(pos)==0);                    
                    cout <<i+1 <<" " <<idx <<"\n";
                    return;
                } else {
                    if(1<idx && sgn(a[1]-a[0])!=v[(1+od)%2]) {
                        continue;
                    }
                    if(sgn(a[i]-a[idx-1])!= v[(idx+od)%2]) {
                        continue;
                    }
                    if(i-1>=idx && sgn(a[i-1]-a[i])!= v[(idx+1+od)%2]) {
                        continue;
                    }
                    if(i+1<n && sgn(a[i+1]-a[idx])!= v[(i+1+od)%2]) {
                        continue;
                    }
                    if(i+2<n && sgn(a[i+2]-a[i+1])!= v[(i+2+od)%2]) {
                        continue;
                    }
                    pos.clear();
                    reverse(a+idx,a+i+1);
                    cek();
                    // assert(sz(pos)==0);                    
                    cout <<idx+1 <<" " <<i+1 <<"\n";
                    return;
                }
            }
        }
        // assert(false);
        idx--;
        if((!(a[idx+1]==a[idx])) && (!(idx+2<n && sgn(a[idx+1]-a[idx])==sgn(a[idx+2]-a[idx+1])))) {
            rep(od,0,2) {
                rep(i,0,n) {
                    if(i<idx) {
                        if(idx+1<n && sgn(a[idx+1]-a[idx])!=v[(idx+1+od)%2]) {
                            continue;
                        }
                        if(sgn(a[idx]-a[i])!= v[(idx+od)%2]) {
                            continue;
                        }
                        if(i+1<idx && sgn(a[i]-a[i+1])!= v[(idx-1+od)%2]) {
                            continue;
                        }
                        if(1<i && sgn(a[1]-a[0])!= v[(1+od)%2]) {
                            continue;
                        }
                        if(i-1>=0 && sgn(a[idx-1]-a[i-1])!= v[(i+od)%2]) {
                            continue;
                        }
                        pos.clear();
                        reverse(a+i,a+idx);
                        cek();
                        assert(sz(pos)==0);                        
                        cout <<i+1 <<" " <<idx <<"\n";
                        return;
                    } else {
                        if(1<idx && sgn(a[1]-a[0])!=v[(1+od)%2]) {
                            continue;
                        }
                        if(sgn(a[i]-a[idx-1])!= v[(idx+od)%2]) {
                            continue;
                        }
                        if(i-1>=idx && sgn(a[i-1]-a[i])!= v[(idx+1+od)%2]) {
                            continue;
                        }
                        if(i+1<n && sgn(a[i+1]-a[idx])!= v[(i+1+od)%2]) {
                            continue;
                        }
                        if(i+2<n && sgn(a[i+2]-a[i+1])!= v[(i+2+od)%2]) {
                            continue;
                        }
                        pos.clear();
                        reverse(a+idx,a+i+1);
                        cek();
                        assert(sz(pos)==0);                        
                        cout <<idx+1 <<" " <<i+1 <<"\n";                        
                        return;
                    }
                }
            }            
        }
        pos.clear();
        reverse(a+idx,a+idx+2);
        cek();
        if(sz(pos)==0) {
            cout <<idx+1 <<" " <<idx+2 <<"\n";
            return;
        }
        cout <<"-1 -1\n";
    } else {
        cout <<"1 " <<n <<"\n";
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