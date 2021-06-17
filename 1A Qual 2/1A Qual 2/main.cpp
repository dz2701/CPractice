//
//  main.cpp
//  1A Qual 2
//
//  Created by Shin Lee on 4/9/21.
//

#include <bits/stdc++.h>
using namespace std;
int val[96]; int q[96]; int m;
long long Solve(int pos, long long sum, long long mul){
    if(pos==m){
        long long ret = -1e9;
        for(int i=0;i<=q[pos];i++){
            if(sum+val[pos]*i==mul*pow(val[pos],q[pos]-i)){
                ret = max(ret, sum+val[pos]*i);
            }
        }
        return ret;
    }
    if(pos>m){
        //this can only occur if there is only 1 prime number type
        if(sum==mul)return sum;
        else return 0;
    }
    long long ret = 0;
    for(int i=0;i<=q[pos];i++){
        ret = max(ret, Solve(pos+1,sum+val[pos]*i,mul*pow(val[pos],q[pos]-i)));
    }
    return ret;
}
int main(){
    int t; cin >> t;
    for(int testcase = 1; testcase<=t; testcase++){
        cin >> m;
        for(int i=1;i<=m;i++){
            cin >> val[i] >> q[i];
        }
        long long ans = 0;
        for(int i=0;i<=q[1];i++){
            ans = max(ans, Solve(2,val[1]*i,pow(val[1],q[1]-i)));
        }
        printf("Case #%lld: %lld\n",testcase,ans);
    }
    return 0;
}
