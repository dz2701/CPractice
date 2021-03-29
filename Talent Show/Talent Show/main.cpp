//
//  main.cpp
//  Talent Show
//
//  Created by Shin Lee on 2/15/21.
//

#include <bits/stdc++.h>
using namespace std;
int n, w;
const int MAX = 250*1e3 + 1;
set<int>dp[251][MAX];
double ans[MAX];
int weight[251], talent[251];
int main(){
    cin >> n >> w;
    for(int i=1;i<=n;i++){
        cin >> weight[i] >> talent[i];
    }
    dp[0][0].insert(0);
    for(int k=1;k<=n;k++){
        for(int i=1;i<65;i++){
            for(int j=1;j<=n;j++){
                //when I use the cow this time
                if(i-talent[j]>=0 and !dp[k-1][i-talent[j]].empty()){
                    for(auto it=dp[k-1][i-talent[j]].begin();it!=dp[k-1][i-talent[j]].end();it++){
                        dp[k][i].insert(*it+weight[j]);
                    }
                }
                //when I don't use the cow this time
                if(!dp[k-1][i].empty())for(auto it=dp[k-1][i].begin();it!=dp[k-1][i].end();it++){
                    dp[k][i].insert(*it+weight[j]);
                }
            }
            printf("dp[%d] contains:\n",i);
            for(auto it = dp[i][k].begin();it!=dp[i][k].end();it++){
                printf("%d ",*it);
            }
            printf("\n");
            ans[i] = *dp[i][k].lower_bound(w-weight[i]);
            printf("ans[%d] = %f\n",i,ans[i]);
        }
    }
    
    double r = -1e9;
    for(int i=1;i<MAX;i++){
        r = max(r, ans[i]/double(i));
    }
    cout << r;
}
