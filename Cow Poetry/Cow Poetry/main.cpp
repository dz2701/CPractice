//
//  main.cpp
//  Cow Poetry
//
//  Created by Shin Lee on 2/5/21.
//

#include <bits/stdc++.h>
using namespace std;

long long n, m, k;
const long long MAX = 5e3+5;
const long long FAC = 1e9+7;
vector<long long>words[MAX];
set<long long>seq;
long long dp[MAX], cnt[MAX];
long long sum[MAX];
long long get_power_value(long long x, long long n){
    if(n==0)return 1;
    if(n==1)return x%FAC;
    if(n%2==0)return get_power_value(x*x%FAC,n/2)%FAC;
    else return x*get_power_value(x*x%FAC,(n-1)/2)%FAC;
}
int main(){
    freopen("poetry.in","r",stdin);
    freopen("poetry.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    for(long long i=1;i<=n;i++){
        long long a, b; cin >> a >> b;
        words[b].push_back(a);
    }
    for(long long i=1;i<=m;i++){
        char t; cin >> t;
        long long temp = t - 'A';
        cnt[temp]++;
    }
    dp[0]=1;
    for(long long i=1;i<=k;i++){
        for(long long j=1;j<=n;j++){
            for(auto c:words[j]){
                if(i-c>=0)dp[i]+=dp[i-c]%FAC; dp[i]%=FAC;
            }
        }
    }
    
    for(long long i=1;i<=n;i++){
        for(auto c:words[i]){
            sum[i]+=dp[k-c]%FAC; sum[i]%=FAC;
        }
    }
    long long ans = 1;
    for(long long i=0;i<='Z'-'A';i++){
        long long temp=0;
        for(long long j=1;j<=n;j++){
            //consider all types
            temp+=cnt[i]!=0?get_power_value(sum[j],cnt[i])%FAC:0; temp%=FAC;
        }
        if(temp!=0)ans*=temp%FAC; ans%=FAC;
    }
    cout << ans%FAC;
}
