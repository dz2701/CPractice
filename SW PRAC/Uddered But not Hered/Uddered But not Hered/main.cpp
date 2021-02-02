#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
int dp[MAX];
int last[30];
string s;
string check;
int Solve(string p){
    int ret = 0;
    if(p.size()==s.size()){
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                if(p.find(s[i])<p.find(s[j])){
                    ret++;
                }
            }
        }
    }
    else{
        for(int i=0;i<s.size();i++){
            if(p.find(s[i])== s.end() - s.begin()){
                ret= min(ret, Solve(p+s[i]));
            }
        }
    }
    return ret;
}
int main(){
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(check.find(s[i])){
            check.insert(char(s[i]));
        }
    }
    cout << Solve(s);
    
}
