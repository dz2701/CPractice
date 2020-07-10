//
//  main.cpp
//  2457 공주님의 정원
//
//  Created by dz2701 on 6/24/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
int n;
struct date{int month, day;};
int days[13]= {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
date convert(int m, int d){
    date rt;
    if(d!=1)rt = {m,d-1};
    else rt = {m-1, days[m-1]};
    return rt;
}
bool cmp_date(date a, date b){return a.month==b.month?a.day>b.day:a.month>b.month;}; //is a bigger than b?
bool same_date(date a, date b){return a.month==b.month && a.day==b.day;};
bool cmp(pair<date,date>a, pair<date,date>b){return cmp_date(a.second,b.second);};
pair<date,date> dates[MAX];
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> dates[i].first.month >> dates[i].first.day >> dates[i].second.month >> dates[i].second.day;
        dates[i].second = convert(dates[i].second.month, dates[i].second.day);
    }
    sort(dates+1, dates+n+1, cmp);
    
    date prev = {11,30};
    date next = {int(1e9),int(1e9)};
    int ans =0;
    //cout << cmp_date({3,1},{1,3}); ==> 1
    //cout << cmp_date({11,30},{3,1});
    for(int i=1;i<=n and cmp_date(prev,{3,1});i=i){
        while(i<=n and (cmp_date(dates[i].second,prev) or same_date(dates[i].second,prev))){
            if(cmp_date(next,dates[i].first) or same_date(next,dates[i].first)){
                next = dates[i].first;
            }
            i++;
        }
        prev = next;
        ans++;
    }
    /*while(i<n+1 and cmp_date(prev,{3,1})){
        while(i<n+1 and cmp_date(dates[i].second,prev)){
            if(cmp_date(next,dates[i].first)){
                next = dates[i].first;
            }
            i++;
        }
        prev = next;
        ans++;
    }*/
    
    cout << ans;
    
    
    
}
