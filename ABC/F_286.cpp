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

const int mxm=108;
const int a[9]={4,9,5,7,11,13,17,19,23};
int n;
int aa[mxm],b[mxm], pref[9];

void ask() {
    int m=0;
    for(int i=0;i<9;i++) {
        m +=a[i];
    }
    // cout <<m <<"\n"; cout <<flush;
    assert(m==mxm);
    cout <<m <<"\n";
    cout <<flush;
    pref[0] = a[0];
    for(int i=1;i<9;i++) {
        pref[i] = pref[i-1]+a[i];
    }
    // cout <<pref[8] <<"\n";
    // cout <<flush;
    for(int i=0;i<9;i++) {
        int s = (i>0?pref[i-1]+1:1);
        for(int j=s;j<=pref[i];j++) {
            aa[j-1] = (j<pref[i]?j+1:s);
        }
    }
    for(int i=0;i<mxm;i++) {
        if(i==0) {
            cout <<aa[i];
        } else {
            cout <<" " <<aa[i];
        }
    }
    cout <<"\n";
    cout <<flush;
}

void solve() {
    ask();
    for(int i=0;i<mxm;i++) {
        cin >>b[i];
    }
    n = b[0]-1;
    int md = a[0];
    for(int i=1;i<9;i++) {
        // md *=a[i];
        while(true) {
            if((n%a[i]) == ((b[pref[i-1]]-(pref[i-1]+1))%a[i])) {
                break;
            }
            n +=md;
            assert(n<md*a[i]);
        }
        md *=a[i];
    }
    cout <<n <<"\n";
    cout <<flush;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}