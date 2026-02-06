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
int n;
int r1,r2,r3,r4,f1,f2,f3,f4;

string getCategory(int r, int f) {
    if(f==0) {
        return "None";
    }
    if(r<=r1 && f<=f1) {
        return "New Customer";
    } else if(r<=r2 && f<=f1) {
        return "Promising";
    } else if(r<=r2 && f<=f3) {
        return "Potential Loyalist";
    } else if(r<=r3 && f<=f2) {
        return "About to Sleep";
    } else if(r<=r3 && f<=f3) {
        return "Need Attention";
    } else if(r<=r1 && f>f4) {
        return "Champion";
    } else if(r<=r3 && f>f3) {
        return "Loyal Customer";
    } else if(r<=r4 && f>f1 && f<=f2) {
        return "Hibernating";
    } else if(f<=f2) {
        return "Lost";
    } else if(r<=r4 || f<=f4) {
        return "About to Leave";
    } else {
        return "Can't Lose Them";
    }
}

void solve() {
    cin >>r1 >>r2 >>r3 >>r4;
    cin >>f1 >>f2 >>f3 >>f4;
    cin >>n;
    map<string,int> mpf, mpl;
    for(int i=1;i<=n;i++) {
        int a; string s; cin >>a >>s;
        if(a==1) {
            mpf[s]++;
            mpl[s] = i;
        } else {
            cout <<getCategory(i-mpl[s],mpf[s]) <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}