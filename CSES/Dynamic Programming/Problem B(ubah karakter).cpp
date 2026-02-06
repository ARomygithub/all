#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    string s;
    cin >> s;
    map<char, unsigned long long> m;
    for(auto a:s){
        m[a]++;
    }
    while(M--){
        char c;
        string S;
        cin >> c >> S;
        unsigned long long temp = m[c];
        m[c]=0;
        for(auto a:S){
            m[a]+=temp;
        }
    }
    unsigned long long sum = 0;
    for(int i=0; i<26; i++){
        char cr=i+'A';
        sum+=m[cr];
    }
    cout << sum << endl;
}
