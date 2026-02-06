#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5;
int a[mxn];

void oddBubbleSort(int a[]) {
    int N= *max_element(a,a+5);
    cout <<"N = " <<N <<"\n";
    for(int i=1; i<=N; i++) {
        cout <<"i = " <<i <<" :";
        for(int j=1; j<N; j++) {
            if(a[j-1]>a[j])
                swap(a[j-1],a[j]);
            else
                cout<<" " <<j;
        }
        cout <<"\n";
    }
    cout <<"---" <<"\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int b[5]={1,2,4,3,5};
        oddBubbleSort(b);
	return 0;
}
