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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
const ll mod = 998244353;
ll x,l,r;

void solve() {
    cin >>x >>l >>r;
    ll ans = 0;
    for(ll a = 1;a*(a+1)*(a+2)*(a+3)<=x;a++) {
        for(ll b = a+1; b*(b+1)*(b+2)<=(x/a);b++) {
            if((b+1) >= (x/(a*b*(b+1)))) continue;
            ll mni = (ll)(sqrt(1.0*x/(a*b)));
            if(a+b>=l && a+b<r) {
                ll li = b+1, ri = mni;
                ll ci = b+1;
                while(li<=ri) {
                    ll mid = (li+ri)/2;
                    ll d = x/(a*b*mid);
                    if(mid<d) {
                        ci = mid;
                        li = mid+1;
                    } else {
                        ri = mid-1;
                    }
                }
                ans += ci-b;
                ans %= mod;
            }
            ll li2 = max(l-a,b+1), ri2 = r-a-1;
            if(li2<=ri2 && (li2) < (x/(a*b*li2))) {
                ll ci = li2;
                while(li2<=ri2) {
                    ll mid = (li2+ri2)/2;
                    ll d = x/(a*b*mid);
                    if(mid<d) {
                        ci = mid;
                        li2 = mid+1;
                    } else {
                        ri2 = mid-1;
                    }
                }
                ans += ci-b;
                ans %= mod;
            }
            ll li3 = b+1, ri3 = mni;
            ll ci3r = -1, ci3l = -1;
            while(li3<=ri3) {
                ll mid = (li3+ri3)/2;
                ll d = x/(a*b*mid);
                bool lebih = mid >= d;
                if(lebih) {
                    ri3 = mid-1;
                } else if(d < r-a) {
                    ci3r = mid;
                    ri3 = mid-1;
                } else {
                    li3 = mid+1;
                }
            }
            li3 = b+1, ri3 = mni;
            while(li3<=ri3) {
                ll mid = (li3+ri3)/2;
                ll d = x/(a*b*mid);
                bool lebih = mid >= d;
                if(lebih) {
                    ri3 = mid-1;
                } else if(d >=l-a) {
                    ci3l = mid;
                    li3 = mid+1;
                } else {
                    ri3 = mid -1;
                }
            }
            if(ci3r!=-1 && ci3l!=-1) {
                ans += ci3l-ci3r+1;
                ans %= mod;
            }
            ll li4 = max(l-b,b+1), ri4 = r-b-1;
            if(li4<=ri4 && (li4) < (x/(a*b*li4))) {
                ll ci = li4;
                while(li4<=ri4) {
                    ll mid = (li4+ri4)/2;
                    ll d = x/(a*b*mid);
                    if(mid<d) {
                        ci = mid;
                        li4 = mid+1;
                    } else {
                        ri4 = mid-1;
                    }
                }
                ans += ci-b;
                ans %= mod;
            }            
            ll li5 = b+1,  ri5 = mni;
            ll ci5r = -1, ci5l = -1;
            while(li5<=ri5) {
                ll mid = (li5+ri5)/2;
                ll d = x/(a*b*mid);
                bool lebih = mid >= d;
                if(lebih) {
                    ri5 = mid-1;
                } else if(d < r-b) {
                    ci5r = mid;
                    ri5 = mid-1;
                } else {
                    li5 = mid+1;
                }
            }
            li5 = b+1, ri5 = mni;
            while(li5<=ri5) {
                ll mid = (li5+ri5)/2;
                ll d = x/(a*b*mid);
                bool lebih = mid>=d;
                if(lebih) {
                    ri5 = mid-1;
                } else if(d >=l-b) {
                    ci5l = mid;
                    li5 = mid+1;
                } else {
                    ri5 = mid-1;
                }
            }
            if(ci5r!=-1 && ci5l!=-1) {
                ans += ci5l-ci5r+1;
                ans %= mod;
            }
            ll li6 = b+1, ri6 = mni;
            if(li6<=mni) {
                ll cir = -1, cil = -1;
                ri6 = mni;
                while(li6<=ri6) {
                    ll mid = (li6+ri6)/2;
                    ll d = x/(a*b*mid);
                    bool lebih = mid>=d;
                    if(lebih) {
                        ri6 = mid-1;
                    } else if(mid+d < r) {
                        cir = mid;
                        ri6 = mid-1;
                    } else {
                        li6 = mid+1;
                    }
                }
                li6 = b+1, ri6 = mni;
                while(li6<=ri6) {
                    ll mid = (li6+ri6)/2;
                    ll d = x/(a*b*mid);
                    bool lebih = mid>=d;
                    if(lebih) {
                        ri6 = mid-1;
                    } else if(mid+d >=l) {
                        cil = mid;
                        li6 = mid+1;
                    } else {
                        ri6 = mid-1;
                    }
                }
                if(cir!=-1 && cil!=-1) {
                    ans += cil-cir+1;
                    ans %= mod;
                }
            }
            // ri6 = x/(a*b);
            // if(mni+1<=ri6) {
            //     ll cil=-1, cir=-1;
            //     li6 = mni+1;
            //     while(li6<=ri6) {
            //         ll mid = (li6+ri6)/2;
            //         ll d = x/(a*b*mid);
            //         bool lebih = mid >=d;
            //         if(lebih) {
            //             ri6 = mid-1;
            //         } else if(mid+d>=l) {
            //             cil = mid;
            //             ri6 = mid-1;
            //         } else {
            //             li6 = mid+1;
            //         }
            //     }
            //     li6 = mni+1, ri6=x/(a*b);
            //     while(li6<=ri6) {
            //         ll mid = (li6+ri6)/2;
            //         ll d = x/(a*b*mid);
            //         bool lebih = mid>=d;
            //         if(lebih) {
            //             ri6 = mid-1;
            //         } else if(mid+d<r) {
            //             cir = mid;
            //             li6 = mid+1;
            //         } else {
            //             ri6 = mid-1;
            //         }
            //     }
            //     if(cil!=-1 && cir!=-1) {
            //         ans +=cir-cil+1;
            //         ans %= mod;
            //     }
            // }
        }
    }
    ans =ans*4ll%mod;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}