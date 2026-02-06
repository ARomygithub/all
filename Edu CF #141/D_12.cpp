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

const int mxn=1e3;
const int mxa=2e6;
int n;
int a[mxn];
bool notPrime[mxa+1];

void solve() {
    cin >>n;
    int ct1=0;
    set<int> s;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        if(a[i]==1) ct1++;
        s.insert(a[i]);
    }
    int ans = 0;
    vector<int> v;
    for(int ai : s) {
        for(int bi : s) {
            if((ai%2)!=(bi%2)) {
                if(!notPrime[ai+bi]) {
                    if(ans < 2) {
                        ans = 2;
                        v.clear();
                        v.push_back(ai);
                        v.push_back(bi);
                        break;
                    }
                }
            }
        }
    }
    if(ct1>0) {
        int temp = ct1;
        vector<int> vtemp;
        for(int i=0;i<temp;i++) {
            vtemp.push_back(1);
        }
        for(int ai : s) {
            if(ai!=1 && !notPrime[ai+1]) {
                temp++;
                vtemp.push_back(ai);
                break;
            }
        }
        if(temp>ans) {
            ans = temp;
            v.swap(vtemp);
        }
    }
    if(ans<1) {
        ans = 1;
        v.push_back(*s.begin());
    }
    cout <<ans <<"\n";
    for(int i=0;i<sz(v);i++) {
        if(i==0) {
            cout <<v[i];
        } else {
            cout <<" " <<v[i];
        }
    }
    cout <<"\n";
}

void init() {
    for(int i=2;i<=mxa;i++) {
        if(!notPrime[i]) {
            for(int j=i+i;j<=mxa;j+=i) {
                notPrime[j] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}