#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)

vector<pair<int, int>> pruefer_decode(vector<int> const& code) {
    int n = code.size() + 2;
    vector<int> degree(n, 1);
    for (int i : code)
        degree[i]++;

    int ptr = 0;
    while (degree[ptr] != 1)
        ptr++;
    int leaf = ptr;

    vector<pair<int, int>> edges;
    for (int v : code) {
        edges.emplace_back(leaf, v);
        if (--degree[v] == 1 && v < ptr) {
            leaf = v;
        } else {
            ptr++;
            while (degree[ptr] != 1)
                ptr++;
            leaf = ptr;
        }
    }
    edges.emplace_back(leaf, n-1);
    return edges;
}

int rand(int a, int b) {
    return a + rand()%(b-a+1);
}
typedef vector<int> vi;

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); //atoi convert string to int
    int n = rand(6,6);
    int k = rand(1,7);
    int r = rand(1,n);
    vector<int> code(n-2);
    for(int i=0;i<n-2;i++) {
        code[i] = rand(0, n-1);
    }
    vector<pair<int,int>> edges = pruefer_decode(code);
    cout <<n <<" " <<k <<" " <<r <<"\n";
    for(auto [u,v] : edges) {
        cout <<u+1 <<" " <<v+1 <<" ";
        rep(i,0,k) {
            cout <<rand(1,20) <<" \n"[i==k-1];
        }
    }
    vector s(k, vi(n));
    rep(i,0,k) {
        rep(j,0,n) {
            s[i][j] = rand(1,20);
        }
    }
    rep(i,0,k) {
        rep(j,0,n) {
            cout <<s[i][j] <<" \n"[j==n-1];
        }
    }
    return 0;    
}
