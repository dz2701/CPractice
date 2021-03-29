//
//  main.cpp
//  Teamwork
//
//  Created by Shin Lee on 2/10/21.
//

#include <bits/stdc++.h>
using namespace std;
int n, k;
const int MAX = 1e4+5;
int arr[MAX], max_val[MAX][MAX];
int dp[MAX];
int main(){
    //ifstream fin("teamwork.in");
    //ofstream fout("teamwork.out");
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<=n;i++){
        int temp = arr[i];
        for(int j=i;j<=n;j++){
            temp = max(temp, arr[j]);
            max_val[i][j] = temp;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=min(i,k);j++){
            dp[i] = max(dp[i], dp[i-j]+max_val[i-j+1][i]*j);
        }
    }
    cout << dp[n];
    return 0;
}
