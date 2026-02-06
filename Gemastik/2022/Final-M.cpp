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
int n,t;
int a[mxn+1];

bool isValid(int l, int r) {
    // for(int i=l;i+2<=r;i++) {
    //     if(a[i]<a[i+1] && a[i+1])
    // }
}

void solve() {
    cin >>n;
    for(int i=1; i<=n; ++i) {
        cin >>a[i];
    }
    vector<int> same;
    vector<pii> consec;
    for(int i=1;i<=n;i++) {
        if(i+1<=n && a[i]==a[i+1]) {
            if(i+2<=n && a[i]==a[i+2]) {
                cout <<"-1 -1\n";
                return;
            } else {
                same.push_back(i);
            }
        }
    }
    for(int i=1;i<=n;i++) {
        if(i+2<=n) {
            if(a[i] < a[i+1] && a[i+1] < a[i+2]) {
                if(i+3<=n && a[i+2]<a[i+3]) {
                    if(i+4<=n && a[i+3]<a[i+4]) {
                        cout <<"-1 -1\n";
                        return;
                    }
                    consec.push_back({i,3});
                    i = i+3;
                } else {
                    consec.push_back({i,2});
                    i = i+2;
                }
            } else if(a[i] > a[i+1] && a[i+1] > a[i+2]) {
                if(i+3<=n && a[i+2]>a[i+3]) {
                    if(i+4<=n && a[i+3]>a[i+4]) {
                        cout <<"-1 -1\n";
                        return;
                    }
                    consec.push_back({i,3});
                    i = i+3;
                } else {
                    consec.push_back({i,2});
                    i = i+2;
                }
            }
        }
    }
    if(sz(same)==0 && sz(consec)==0) {
        cout <<"1 " <<n <<"\n";
        return;
    } 
    if(sz(same)+sz(consec)>2) {
        cout <<"-1 -1\n";
        return;
    }
    if(sz(same)==2) {
        // try [same[0], same[1]]
    } else if(sz(same)==1) {
        // try same[0] with {}
    } else {

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