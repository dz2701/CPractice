//
//  main.cpp
//  248
//
//  Created by Shin Lee on 2/24/21.
//

#include <bits/stdc++.h>
using namespace std;
int n; const int MAX = 249;
int arr[MAX];
int dp[MAX][MAX]; //i~j ALL ADD MAX

int Solve(int st, int ed){
    if(st==ed){
        dp[st][ed]=arr[st];
        return arr[st];
    }
    if(dp[st][ed])return dp[st][ed];
    int ret = -1e9; //if none of them works, it will be "impossible"
    for(int k=st;k<ed;k++){
        int temp = Solve(st, k);
        if(temp!=-1e9 and temp==Solve(k+1,ed))ret = max(ret, temp+1); //can merge!
    }
    dp[st][ed] = ret;
    return ret;
}
int main(){
    freopen("248.in","r",stdin);
    freopen("248.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    Solve(1,n);
    int ans = -1e9;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}
