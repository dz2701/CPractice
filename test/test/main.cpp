//
//  main.cpp
//  6068 Time Management
//
//  Created by dz2701 on 6/16/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
#define MAX 1005
using namespace std;
int n; pair<int,int>p[MAX];
bool cmp(pair<int,int>a, pair<int,int>b){return a.second!=b.second?a.second>b.second:a.first>b.first;}
int main(){
    cin >> n;
    for(int i=1;i<=n;i++)cin >> p[i].first >> p[i].second;
    sort(p+1,p+n+1,cmp);
    int e=-1;
    for(int i=1;i<=n;i++){
        printf("%d %d\n",p[i].first,p[i].second);
        e = max(e,p[i].first+p[i].second);
    }
    auto it = lower_bound(p+1,p+n+1,7);

    
    
    

}
