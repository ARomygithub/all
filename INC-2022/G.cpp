#include "bits/stdc++.h"
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
int n;
ll p;

void solve() {
    cin >>n >>p;
    set<ll> s;
    s.insert(p);
    ll mn=p,mx=p;
    while(n--) {
        char qt1,qt2; ll c1, c2;
        cin >>qt1 >>c1 >>qt2 >>c2;
        set<ll> new_s;
        ll new_mn=1e18, new_mx=-1e18; 
        if(qt1=='+') {
            for(auto a: s) {
                if(abs(a+c1)<=50000) {
                    new_s.insert(a+c1);
                }
                min_self(new_mn,a+c1);
                max_self(new_mx,a+c1);
            }
            if(abs(mn+c1)<=50000) {
                new_s.insert(mn+c1);
            }
            min_self(new_mn,mn+c1);
            max_self(new_mx,mn+c1);
            if(abs(mx+c1)<=50000) {
                new_s.insert(mx+c1);
            }
            min_self(new_mn,mx+c1);
            max_self(new_mx,mx+c1);
        } else {
            for(auto a: s) {
                if(abs(a*c1)<=50000) {
                    new_s.insert(a*c1);
                }
                min_self(new_mn,a*c1);
                max_self(new_mx,a*c1);
            }
            if(abs(mn*c1)<=50000) {
                new_s.insert(mn*c1);
            }
            min_self(new_mn,mn*c1);
            max_self(new_mx,mn*c1);
            if(abs(mx*c1)<=50000) {
                new_s.insert(mx*c1);
            }
            min_self(new_mn,mx*c1);
            max_self(new_mx,mx*c1);
        }

        if(qt2=='+') {
            for(auto a: s) {
                if(abs(a+c2)<=50000) {
                    new_s.insert(a+c2);
                }
                min_self(new_mn,a+c2);
                max_self(new_mx,a+c2);
            }
            if(abs(mn+c2)<=50000) {
                new_s.insert(mn+c2);
            }
            min_self(new_mn,mn+c2);
            max_self(new_mx,mn+c2);
            if(abs(mx+c2)<=50000) {
                new_s.insert(mx+c2);
            }
            min_self(new_mn,mx+c2);
            max_self(new_mx,mx+c2);
        } else {
            for(auto a: s) {
                if(abs(a*c2)<=50000) {
                    new_s.insert(a*c2);
                }
                min_self(new_mn,a*c2);
                max_self(new_mx,a*c2);
            }
            if(abs(mn*c2)<=50000) {
                new_s.insert(mn*c2);
            }
            min_self(new_mn,mn*c2);
            max_self(new_mx,mn*c2);
            if(abs(mx*c2)<=50000) {
                new_s.insert(mx*c2);
            }
            min_self(new_mn,mx*c2);
            max_self(new_mx,mx*c2);
        }  
        swap(s,new_s);
        mn = new_mn;
        mx = new_mx;  
    }
    cout <<mx <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}