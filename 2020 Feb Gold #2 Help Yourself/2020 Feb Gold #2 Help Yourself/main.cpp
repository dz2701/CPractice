//
//  main.cpp
//  2020 Feb Gold #2 Help Yourself
//
//  Created by Shin Lee on 12/17/20.
//

#include <bits/stdc++.h>
using namespace std;
const int FAC = 1e9+7;
const int MAX = 1e5+5;
int n; pair<int,int>segments[MAX];
long long dp[MAX];
long long fwBegin[MAX], fwEnd[MAX];
long long queryBegin(int p){
    long long ret = 0;
    for(;p;p-=p&-p){
        ret+=fwBegin[p];
    }
    return ret;
}
long long queryEnd(int p){
    long long ret = 0;
    for(;p;p-=p&-p){
        ret+=fwEnd[p];
    }
    return ret;
}
void updateBegin(int p, long long v){
    for(;p<MAX;p+=p&-p){
        fwBegin[p]+=v;
    }
}
void updateEnd(int p, long long v){
    for(;p<MAX;p+=p&-p){
        fwEnd[p]+=v;
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("help.in","r",stdin);
    //freopen("help.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> segments[i].first >> segments[i].second;
        updateBegin(segments[i].first,1);
        updateEnd(segments[i].second,1);
    }
    long long cnt = 0;
    for(int i=1;i<=n;i++){
        //looking at segment i
        printf("looking at segment %d, %d\n",segments[i].first,segments[i].second);
        cnt+= n-1 - (n-queryBegin(segments[i].second+1)) - queryEnd(segments[i].first-1);
        printf("cnt+= %d - (%d - %lld) - %lld = %lld\n",n-1, n,queryBegin(segments[i].second+1),queryEnd(segments[i].first-1),cnt);
        cnt%=FAC;
    }
    long long ccnt = n*(n-1) - cnt;
    printf("ccnt = %lld\n",ccnt);
    long long ans=0;
    for(int i=1;i<=n;i++){
        long long temp = ccnt/i;
        long long temp2 = n/i;
        printf("ans+=%lld\n",i*temp + (temp2-temp));
        ans+= i*temp + (temp2 - temp);
        ans%=FAC;
    }
    cout << ans;
    return 0;
}
