#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()


const int mxn=1e6;
const ll mod=998244353;
int n,m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n >>m;
    ll ans=0;
    vector<vector<int>> v(m,vector<int>(n));
    int mat[m][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int x; cin >>x;
            mat[j][i]=x;
            v[j][x]=i;
        }
    }
    for(int j=0;j<m-1;j++) {
        map<int,int> mp1, mp2;
        for(int i=0;i<n;i++) {
            mp1[mat[j][i]]++, mp1[mat[j+1][i]]--;
            if(mat[j][i]==mat[j+1][i]) {
                mp1.erase(mat[j][i]);
                ans +=mp1.size();
                mp2[mat[j][i]]++;
            } else {
                if((mp1[mat[j][i]]+2)%2==0) {
                    mp1.erase(mat[j][i]);
                    mp2[mat[j][i]]++;
                    ans +=mp1.size();
                }
                if((mp1[mat[j+1][i]]+2)%2==0) {
                    mp1.erase(mat[j+1][i]);
                    mp2[mat[j+1][i]]++;
                    ans +=mp1.size();
                }
            }
        }
    }
    cout <<ans;
}
