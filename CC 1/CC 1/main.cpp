//
//  main.cpp
//  CC 1
//
//  Created by Shin Lee on 2/6/21.
//

#include <bits/stdc++.h>
using namespace std;
int n, x;
const int MAX = 1e6+6;
const int FAC = 1e9+7;
int arr[101];
int dp[MAX]; //i make method number dp[i] += all coin dp[i-coin#]
int main(){
    cin >> n >>x ;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    dp[0]=1;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=n;j++){
            if(i-arr[j]>=0)dp[i]+=dp[i-arr[j]]%FAC;
        }
    }
    cout << dp[x];
}
