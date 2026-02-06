#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand()%(b-a+1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); //atoi convert string to int
    int n = rand(6,6);
    cout <<"1\n";
    cout <<n <<"\n";
    for(int i=0;i<n;i++) {
        cout <<rand(0,n-1) <<" \n"[i==n-1];
    }
    return 0;    
}
