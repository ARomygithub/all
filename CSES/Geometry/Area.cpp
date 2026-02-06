#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
typedef ll C;
typedef complex<C> P;
#define x real()
#define y imag()

const int mxn=1e5;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cin >>n;
    vector<P> polygon(n);
    for(P& p : polygon) {
        int a,b; cin >>a >>b;
        p = {a,b};
    }
    ll area=0;
    for(int i=0;i<n;i++) {
        area += (conj(polygon[i])*polygon[i+1==n?0:i+1]).y;
    }
    cout <<abs(area); // twice the area
}
