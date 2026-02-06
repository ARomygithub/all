#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string S, s;

int main() {
	// your code goes here
	int N;
	cin >> N;
	cin >> S >> s;
	if(S.size()==1&&S[0]!=s[0]){
		cout << 1 << endl;
	}
	else if (S==s){
		cout << 0 << endl;
	}
	else {
		for(int i=0; i<N; i++){
			if(s[i]==S[i]){
				s.erase(i, 1);
				S.erase(i, 1);
			}
		}
		N = (int)S.size();
		int sum = 0;
		int temp = N;
		for(int i=0; i<N-1; i++){
			if(s[i]==S[i]){
				continue;
			}
			for(int j=i+1; j<N; j++){
				if(S[i]==s[j]&&S[j]==s[i]){
					swap(s[i], s[j]);
					swap(S[i], S[j]);
					sum++;
					temp -= 2;
					break;
				}
			}
		}
		cout << sum+temp << endl;
	}
	return 0;
}
