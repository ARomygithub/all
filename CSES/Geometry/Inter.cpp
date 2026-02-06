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

C loc(P p1, P p2, P p3) {
    return (conj(p3-p1)*(p3-p2)).y;
}

void solve() {
    P p[4];
    int x1,y1,x2,y2,x3,y3,x4,y4; cin >>x1 >>y1 >>x2 >>y2 >>x3 >>y3 >>x4 >>y4;
    p[0] = {x1,y1}; p[1]={x2,y2}; p[2]={x3,y3}; p[3]={x4,y4};
    if((conj(p[1]-p[0])*(p[3]-p[2])).y==0) {
        //paralel
        if(loc(p[0],p[1],p[2])!=0) {
            cout <<"NO\n";
        } else {
            // cek bounding boxes
            for(int rep=0;rep<2;rep++) {
                if(max(p[0].x,p[1].x)<min(p[2].x,p[3].x) || max(p[0].y,p[1].y)<min(p[2].y,p[3].y)) {
                    cout <<"NO\n";
                    return;
                }
                swap(p[0],p[2]); swap(p[1],p[3]);
            }
            cout <<"YES\n";
        }
    } else {
        for(int rep=0;rep<2;rep++) {
            if((loc(p[0],p[1],p[2])>0 && loc(p[0],p[1],p[3])>0) || (loc(p[0],p[1],p[2])<0 && loc(p[0],p[1],p[3])<0)) {
                cout <<"NO\n";
                return;
            }
            swap(p[0],p[2]); swap(p[1],p[3]);
        }
        cout <<"YES\n";
    }
    return;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}
