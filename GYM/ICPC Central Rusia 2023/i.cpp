#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef vector<int> vi;
#define all(x) (x).begin(), (x).end()

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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*
35
35
35 622 398 291 252 183 -1 141 111 -1 -1 73 -1 -1 -1 -1 -1 36 610 553 488 434 392 359 307 175 150 -1 118 67 70 28 37 49 25
38
38 759 480 352 276 232 194 156 -1 116 -1 -1 79 -1 -1 -1 -1 -1 -1 38 700 658 583 528 476 409 362 220 187 252 139 178 79 -1 36 36 41 35
42
42 923 614 439 345 299 257 215 170 -1 128 -1 -1 -1 86 -1 -1 -1 -1 -1 -1 42 861 819 733 661 596 543 468 427 380 236 216 257 124 209 78 143 44 46 38 44
44
44 1008 641 495 362 319 270 224 181 -1 -1 132 -1 -1 90 -1 -1 -1 -1 -1 -1 -1 44 960 880 794 727 654 615 543 479 303 257 350 210 174 94 141 96 96 45 44 44 47
45
45 1012 688 511 416 320 274 228 -1 182 -1 138 -1 -1 -1 92 -1 -1 -1 -1 -1 -1 46 994 931 857 774 713 635 590 537 475 434 277 239 318 187 126 148 95 53 45 47 63 20
48
48 1194 793 591 440 388 295 -1 243 198 -1 -1 146 -1 -1 -1 96 -1 -1 -1 -1 -1 -1 -1 49 1106 1049 956 863 799 729 680 611 575 518 322 277 368 224 159 106 143 54 106 50 52 48 44
49
49 1211 810 605 452 402 345 294 250 203 -1 -1 151 -1 -1 -1 99 -1 -1 -1 -1 -1 -1 -1 50 1206 1120 1002 966 867 816 752 661 599 545 347 452 297 259 -1 153 101 146 90 111 46 54 44 47
*/


void solve() {
    cin >>n;
    set<int> s = {35, 38, 42, 44, 45, 48, 49};
    while(true) {
        bool ok = 1;
        vi ans(n,-1);
        vi pos(n,0);
        while(true) {
            bool st = 1;
            rep(i,0,n) {
                if(pos[i]>=n) continue;
                st = 0;
                int ps = pos[i];
                if(ans[ps]==-1) {
                    if(s.count(n)) {
                        ans[ps] = (n-ps)*(i+1) + (rng()%(i+1));
                    } else {
                        ans[ps] = (n-ps)*(i+1) + i;
                    }
                }
                int aw = pos[i];
                pos[i] += (ans[ps]/(i+1));
                if(pos[i]>n || pos[i]==aw) {
                    ok = 0;
                    st = 1;
                    break;
                }
                // assert(pos[i]<=n);
                // assert(pos[i]!=aw);
            }
            if(st) break;
        }
        if(ok) {
            rep(i,0,n) {
                int cur = ans[i];
                if(cur==-1) cur = 1;
                cout <<cur <<" \n"[i==n-1];
            }
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}