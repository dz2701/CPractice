//
//  main.cpp
//  17192 Snakes
//
//  Created by dz2701 on 11/30/20.
//

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, k;
map<pair<pair<int,int>,int>,int>arr;
int snakes[401];
int Solve(int i, int j, int k){
    if(arr[{{i,j},k}]){
        return arr[{{i,j},k}];
    }
    int ret = 0;
    if(k==0){
        int sum = 0; int fac = -INF;
        for(int p=i;p<=j;p++){
            sum+=snakes[p];
            fac = max(fac,snakes[p]);
        }
        ret = fac * (j-i) - sum;
    }else{
        for(int p=i;p<j;p++){
            ret = min(ret, Solve(i,p,k-1)+Solve(p+1,j,k-1));
        }
    }
    arr[{{i,j},k}] = ret;
    return ret;
}
int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++)cin >> snakes[i];
    cout << Solve(1,n,k);
}
