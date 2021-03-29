//
//  main.cpp
//  Circular Barn Revisited
//
//  Created by Shin Lee on 2/23/21.
//

#include <bits/stdc++.h>
using namespace std;
int N, K;
int dp[101][8], c[101];
int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        cin >> c[i];
    }
    int ans = 1e9;
    //dp[i][j] : ~i까지 보았고 j개의 문을 열었을 때, ~i까지 소들이 움직이는 최소 거리
    //for(int it=0;it<N;it++){
        fill(&dp[0][0], &dp[100][8], 1e9); dp[1][1] = 0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=K;j++){
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]); //새로운 문을 여기서 열자.
            
                for(int k=0;k<i;k++){ //예전에 연 문을 사용하고, 마지막으로 연 문이 k일때,
                    int temp=0;
                    for(int p=k+1;p<=i;p++){ //그 걸리는 비용들의 합
                        temp+=(p-k)*c[p];
                    }
                    dp[i][j] = min(dp[i][j], dp[k][j]+temp);
                }
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }
        ans = min(ans, dp[N][K]);
        int tp = c[1]; for(int i=1;i<N;i++)c[i]=c[i+1]; c[N]=tp;
    //}
    cout << ans;
    return 0;
}
