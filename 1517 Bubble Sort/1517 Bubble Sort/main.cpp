//
//  main.cpp
//  1517 Bubble Sort
//
//  Created by dz2701 on 7/15/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const long long MAX = 5e5+5;
long long arr[MAX]; long long n;
long long fw[MAX];
long long ans = 0;
long long sum(long long p){
    long long rt = 0;
    for(;p;p-=p&-p){
        rt+=fw[p];
    }
    return rt;
}
void add(long long p, long long v){
    for(;p<MAX;p+=p&-p){
        fw[p]+=v;
    }
}
bool cmp(pair<long long,long long>a,pair<long long,long long>b){
    return a.second<b.second;
}
vector<pair<long long,long long>>v;
long long idx[MAX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(long long i=1;i<=n;i++)cin >> arr[i];
    for(long long i=1;i<=n;i++){
        v.push_back(make_pair(i,arr[i]));
    }
    sort(v.begin(),v.end(),cmp);
    long long id = 1;
    for(auto adj:v){
        idx[id++]=adj.first;
    }
    //find number of inversions in this array
    //fw stores the number of inversions in previous numbers
    //makes error when two adjacent numbers are equal.. this should be fixed.
    for(long long i=n;i>0;i--){
        long long temp = sum(idx[i]-1);
        if(arr[idx[i]]==arr[idx[i]-1] or arr[idx[i]]==arr[idx[i]+1])continue;
        ans+=temp;
        add(idx[i],1);
    }
    cout << ans;
    return 0;
}
    
