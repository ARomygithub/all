#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int t;
string s;

void solve() {
    cin >>s;
    int n = sz(s);
    int last2=-1, last1=-1, first2=-1;
    for(int i=0;i<n-1;i++) {
        if((s[i]-'0')+(s[i+1]-'0')>=10) {
            last2 = i;
            if(first2==-1) {
                first2 = i;
            }
        } else {
            last1 = i;
        }
    }
    if(n==1) {
        cout <<s <<" " <<s <<"\n";
    } else {
        if(last2==-1) {
            string mx = "", mn="";
            char c = (char)((s[0]-'0')+(s[1]-'0')+'0');
            mx += c;
            for(int i=2;i<n;i++) {
                mx +=s[i];
            }
            c = (char)((s[n-2]-'0')+(s[n-1]-'0')+'0');
            for(int i=0;i<=n-3;i++) {
                mn +=s[i];
            }
            mn +=c;
            cout <<mx <<" " <<mn <<"\n";
        } else {
            string mx="";
            char c = (char)((s[last2]-'0')+(s[last2+1]-'0')-10+'0');
            for(int i=0;i<n;i++) {
                if(i<last2 || i>=last2+2) {
                    mx +=s[i];
                } else if(i==last2) {
                    mx +='1';
                } else if(i==last2+1) {
                    mx +=c;
                }
            }
            string mn="";
            // cout <<"last1: " <<last1 <<"\n";
            if(last1!=-1) {
                char c = (char)((s[last1]-'0')+(s[last1+1]-'0')+'0');
                for(int i=0;i<n;i++) {
                    if(i<last1 || i>=last1+2) {
                        mn +=s[i];
                    } else if(i==last1) {
                        mn +=c;
                    }
                }
                // cout <<"TES\n";
            } else {
                char c = (char)((s[first2]-'0')+(s[first2+1]-'0')-10+'0');
                for(int i=0;i<n;i++) {
                    if(i<first2 || i >=first2+2) {
                        mn +=s[i];
                    } else if(i==first2) {
                        mn +='1';
                    } else if(i==first2+1) {
                        mn +=c;
                    }
                }
            }
            cout <<mx <<" " <<mn <<"\n";
        }
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
