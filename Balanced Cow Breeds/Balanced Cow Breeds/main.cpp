//
//  main.cpp
//  Balanced Cow Breeds
//
//  Created by Shin Lee on 1/10/21.
//

#include <bits/stdc++.h>
using namespace std;
const int FAC = 2012;
string s; int End;
const int INF = -1;
int dp[1001][1001];
int Solve(int n, pair<int,int>hg){
    if(n==s.size()-1)return 1;
    if(dp[n][hg.first]!=INF)return dp[n][hg.first];
    //if(g<0 or h<0)return 0;
    if(s[n] == '('){
        dp[n][hg.first]=Solve(n+1,{hg.first+1,hg.second}) + Solve(n+1,{hg.first,hg.second+1}); dp[n][hg.first]%=FAC;
        return dp[n][hg.first];
    }else{
        int temp = 0;
        if(hg.second)temp+=Solve(n+1, {hg.first, hg.second-1});  // use one of the Gs to move on
        if(hg.first)temp+=Solve(n+1,{hg.first-1, hg.second}); //use one of the Hs to move on
        return dp[n][hg.first]=temp%FAC;
    }
}
int main(){
    //freopen("bbreeds.in","r",stdin);
    //freopen("bbreeds.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    fill(&dp[0][0], &dp[1000][1001], INF);
    cout << Solve(0,{0,0})%FAC;
}
