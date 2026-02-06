#include <bits/stdc++.h>
using namespace std;

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

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); //atoi convert string to int
    int n = rand(2,10);
    vector<int> code(n-2);
    for(int i=0;i<n-2;i++) {
        code[i] = rand(0, n-1);
    }
    vector<pair<int,int>> edges = pruefer_decode(code);
    cout <<n <<"\n";
    for(auto [u,v] : edges) {
        cout <<u <<" " <<v <<"\n";
    }
    return 0;    
}
