#include <bits/stdc++.h>
using namespace std;

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

const int mxn=1e5;
int p,n,k;

void solve() {
    cin >>p >>n >>k;
    char c; cin >>c;
    int ans = -1e9;
    string np = "";
    for(int i=0;i<p;i++) {
        string npi;
        getline(cin, npi);
        vector<int> v1(n/2), v2(n- (n/2));
        for(int j=0;j<(n/2);j++) {
            cin >> v1[i];
        }
        for(int j=0;j<(n-(n/2));j++) {
            cin >>v2[i];
        }
        set<int> s1, s2;
        int ct1=n/2, ct2=n-ct1;
        for(int j=1;j<(1<<ct1);j++) {
            ll temp=0;
            for(int l=0;l<ct1;l++) {
                
            }
        }
        
        for(int j=0;j<n;j++) {
            int a; cin >>a;
            vector<int> vv;
            for(auto [ki,v]: mp) {
                if(ki<k) {
                    vv.push_back(ki+a);
                }
            }

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}