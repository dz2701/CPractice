//
//  main.cpp
//  Load Balancing (silver)
//
//  Created by Shin Lee on 25/03/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3+5;
pair<int, int>c[MAX]; int n;
int getmin(int a, int b, int c, int d){
    return max(max(a,b),max(c,d));
}
int main(){
    //freopen("balancing.in","r",stdin);
    //freopen("balancing.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++)cin >> c[i].first >> c[i].second;
    sort(c,c+n);
    int ans = 1e9;
    for(int i=0;i<n;i++){
        int y = c[i].second+1;
        int up[2] = {0,0}, down[2] = {0,0};
        for(int j=0;j<n;j++){
            if(c[j].second>y)up[0]++;
            else down[0]++;
        }
        for(int j=0;j<n;j){
            //move the dots to the other side a.k.a move the axis
            int prev = c[j].first;
            while(c[j].first==prev){
                if(c[j].second<y){
                    down[1]++;
                    down[0]--;
                }else{
                    up[1]++;
                    up[0]--;
                }
                j++;
            }
            
            ans = min(ans, getmin(down[0],down[1],up[0],up[1]));
            
        }
        
    }
    
    cout << ans;
    
    return 0;
}
