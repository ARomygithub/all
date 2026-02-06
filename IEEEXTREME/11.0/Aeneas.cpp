#define _USE_MATH_DEFINES
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
#define double long double

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
double r;
int angle[26];

void solve() {
    string s;
    getline(cin, s);
    stringstream ss0(s);
    ss0 >> r;
    for(int i=0;i<26;i++) {
        getline(cin, s);
        stringstream ss1(s);
        char c; double angi; ss1 >>c >>angi;
        angle[c-'A'] = angi;
    }
    getline(cin, s);
    bool first = 1;
    double ans = 0;
    int pos=-1;
    for(int i=0;i<sz(s);i++) {
        if(s[i]>='a' && s[i]<='z') {
            if(s[i]-'a' == pos) continue;
            if(first) {
                // cout <<s[i] <<"\n";
                ans +=1.0;
                first = 0;
                pos = s[i]-'a';
            } else {
                // cout <<s[i] <<"\n";
                double diff1 = angle[s[i]-'a']-angle[pos];
                double diff2 = angle[pos]-angle[s[i]-'a'];
                if(diff1<0.0) diff1+=360.0;
                if(diff2<0.0) diff2+=360.0;
                // ans +=r*min(diff1,diff2)*2*M_PI/360.0;
                ans += 2.0*sin(min(diff1,diff2)*M_PI/360.0);
                // ans += r*2*sin(diff2*M_PI/360.0);
                pos = s[i]-'a';
            }
        } else if(s[i]>='A' && s[i]<='Z') {
            if(s[i]-'A' == pos) continue;
            if(first) {
                ans +=1.0;
                first = 0;
                pos = s[i]-'A';
                // cout <<s[i] <<"\n";
            } else {
                // cout <<s[i] <<"\n";
                double diff1 = angle[s[i]-'A']-angle[pos];
                double diff2 = angle[pos]-angle[s[i]-'A'];
                if(diff1<0.0) diff1+=360.0;
                if(diff2<0.0) diff2+=360.0;
                // ans +=r*min(diff1,diff2)*2*M_PI/360.0;
                ans += 2.0*sin(min(diff1,diff2)*M_PI/360.0);
                // ans += r*2*sin(diff2*M_PI/360.0);
                pos = s[i]-'A';
            }
        }
    }
    ans *=r;
    // cout <<fixed <<setprecision(8) <<ans <<"\n";
    cout <<(ll)(ceil(ans)+0.5) <<"\n";
    // cout <<ceil(ans) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}