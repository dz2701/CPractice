//
//  main.cpp
//  9571 Crowded Cows
//
//  Created by dz2701 on 7/23/20.
//  Copyright © 2020 dz2701. All rights reserved.
//  Using Two Pointer

#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e4+1;
int n, d;
pair<long long,long long> arr[MAX];
bool cmp(pair<long long,long long> a, pair<long long,long long> b){return a.first < b.first;}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> d;
    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr,arr+n,cmp);
    long long lo = 0, hi = 1;
    set<long long> s1, s2;
    long long ans = 0;
    s2.insert(arr[0].second);
    
    //not looking at 0 or n-1, since they are endpoints and would not be 'crowded'
    
    for(int i=1;i<n-1;i++){
        //looking at cow i.
        //update lo and hi
        //move up until bigger
        s1.erase(arr[i-1].second); //not seeing this anymore
        while(hi < n and arr[hi].first-arr[i].first<=d){
            s1.insert(arr[hi].second);
            hi++;
        }
        //remove until bigger
        s2.insert(arr[i].second);
        while(lo<i and arr[i].first - arr[lo].first>d){
            s2.erase(arr[lo].second);
            lo++;
        }
        if(s1.empty() or s2.empty())continue; // not going to work...
        if(*s1.rbegin()>=arr[i].second*2 and *s2.rbegin()>=arr[i].second*2){
            ans++;
        }
    }
    cout << ans;
}
