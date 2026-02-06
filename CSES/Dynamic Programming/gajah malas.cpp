#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 2e5;
int n;
deque<int> dq;
vector<int> v;
bool e[4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n;
    for(int i=0; i<n; i++) {
        int a;
        cin >>a;
        v.push_back(a);
        dq.push_back(a);
    }
    sort(v.begin(),v.end());
    auto f=v.begin();
    auto l=--v.end();
    for(int i=0; i<4; i++) {
        e[i]=1;
    }
    while(dq.size()>2) {
        int a,b;
        a=dq.front();
        b=dq.back();
        if(a!=*f&&a!=*l&&b!=*f&&b!=*l) {
            cout <<"Tidak\n";
            return 0;
        }
        else {
            if(a==*f &&e[2]) {
                dq.pop_front();
                ++f;
                e[0]=0;
            }
            else if(a==*l &&e[3]) {
                dq.pop_front();
                --l;
                e[1]=0;
            }
            else if(b==*f &&e[0]) {
                dq.pop_back();
                ++f;
                e[2]=0;
            }
            else if(b==*l && e[1]) {
                dq.pop_back();
                --l;
                e[3]=0;
            }
            else {
                cout <<"Tidak\n";
                return 0;
            }
        }
    }
    cout <<"Ya\n";
}
