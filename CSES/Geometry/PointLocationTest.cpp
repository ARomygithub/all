#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
typedef ll C;
typedef complex<C> P;
#define x real()
#define y imag()

const int mxn=1e5;
int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cin >>t;
    while(t--) {
        int a,b,c,d,e,f;
        cin >>a >>b >>c >>d >>e >>f;
        P p1, p2, p3;
        p1 = {a,b}; p2={c,d}; p3={e,f};
        C cp = (conj(p3-p1)*(p3-p2)).y;
        if(cp>0) {
            cout <<"LEFT\n";
        } else if(cp==0) {
            cout <<"TOUCH\n";
        } else if(cp<0) {
            cout <<"RIGHT\n";
        }
    }
}
