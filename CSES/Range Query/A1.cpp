#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define input "tc1.in"

const int mxn=1e5;
int n, w, k;
int ah,bh,ch,dh;
ifstream ff;

vector<int> read_seq(int n, int k) {
    vector<int> a(n);
    for(int i=0;i<k;i++) ff >>a[i];
    int al,bl,cl,dl;   
    ff >>al >>bl >>cl >>dl;
    for(int i=k;i<n;i++) {
        a[i]= (((ll)al*a[i-2] + (ll)bl*a[i-1] + cl)% dl) +1;
    }
    return a;
}

void solve() {
    ff >> n >>w >>k;
    vector<int> l = read_seq(n,k);
    vector<int> h = read_seq(n,k);
    vector<int> w1 (n,w);
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cout.tie(0);
    ff.open(input);
    int TC; cin >>TC;
    for(int nr=1;nr<=TC;nr++) {
        printf("Case #%d: ",nr);
        solve();
    }

    ff.close();
}
