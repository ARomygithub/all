#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5;
int k;
string s;
int is1, c2, c3,c5,c7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cout.tie(0);
    int t; cin >>t;
    while(t--) {
        cin >>k;
        cin >>s;
        is1=0, c2=0,c3=0,c5=0,c7=0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='2') {
                c2++;
            } else if(s[i]=='3') {
                c3++;
            } else if(s[i]=='5') {
                c5++;
            } else if(s[i]=='7') {
                c7++;
            } else {
                is1=(int)(s[i]-'0');
            }
        }
        if(is1) {
            cout <<"1\n";
            cout <<is1 <<"\n";
        } else {
            if(c2>1) {
                cout <<"2\n";
                cout <<"22\n";
            } else if(c3>1) {
                cout <<"2\n";
                cout <<"33\n";
            } else if(c5>1) {
                cout <<"2\n";
                cout <<"55\n";
            } else if(c7>1) {
                cout <<"2\n";
                cout <<"77\n";
            } else {
                if(k==4) {
                    for(int i=0;i<4;i++) {
                        if(s[i]=='2') {
                            cout <<"2\n";
                            cout <<"25\n";
                            break;
                        } else if(s[i]=='5') {
                            cout <<"2\n";
                            cout <<"52\n";
                            break;
                        }
                    }
                } else {
                    if(s[1]=='2' || s[1]=='5' ||s[2]=='2' ||s[2]=='5') {
                        cout <<"2\n";
                        cout <<s[0];
                        if(s[1]=='2' ||s[2]=='2') {
                            cout <<"2\n";
                        } else {
                            cout <<"5\n";
                        }
                    } else {
                        cout <<"2\n";
                        cout <<s[0] <<"7\n";
                    }
                }
            }
        }
    }
}
