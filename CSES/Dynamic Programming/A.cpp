#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 2e5;
int a,b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>a >>b;
    for(int n=a; n<=b; n++) {
        if(n>5){
            if(n>8) {
                if(n>9) {
                    if(n%2)
                        cout <<"odd\n";
                    else
                        cout <<"even\n";
                }
                else
                    cout <<"nine\n";
            }
            else {
                if(n>7)
                    cout <<"eight\n";
                else if (n==7)
                    cout <<"seven\n";
                else
                    cout <<"six\n";
            }
        }
        else {
            if(n>3) {
                if(n>4)
                    cout <<"five\n";
                else
                    cout <<"four\n";
            }
            else {
                if(n>2)
                    cout <<"three\n";
                else if(n==2)
                    cout <<"two\n";
                else
                    cout <<"one\n";
            }
        }
    }
}
