#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<char> stk;
    int m1=0,m2=0,m3=0,m4=0,validity=1;
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(stk.empty()){
            stk.push(s[i]);
        }else{
            if(s[i] == '{' || s[i] == '[' || s[i] == '(' || s[i] == '<'){
                stk.push(s[i]);
            }else if(s[i] == '}'){
                if(!stk.empty() && stk.top() == '{'){
                    stk.pop();
                    m1++;
                }else{
                    validity = 0;
                    break;
                }
            }else if(s[i] == ']'){
                if(!stk.empty() && stk.top() == '['){
                    stk.pop();
                    m2++;
                }else{
                    validity = 0;
                    break;
                }
            }else if(s[i] == ')'){
                if(!stk.empty() && stk.top() == '('){
                    stk.pop();
                    m3++;
                }else{
                    validity = 0;
                    break;
                }
            }else if(s[i] == '>'){
                if(!stk.empty() && stk.top() == '<'){
                    stk.pop();
                    m4++;
                }else{
                    validity = 0;
                    break;
                }
                
            }
        }
    }
    if(validity == 1 && stk.empty()){
        cout << "1\n" << m1 << '\n' << m2 << '\n' << m3 << '\n' << m4 << '\n';
    }else{
        cout << "0\n0\n0\n0\n0\n";
    }
}