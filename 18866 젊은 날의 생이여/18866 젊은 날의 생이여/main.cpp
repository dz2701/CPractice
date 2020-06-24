//
//  main.cpp
//  18866 젊은 날의 생이여
//
//  Created by dz2701 on 6/18/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+5;

int n; pair<int,int>arr[MAX];
int minhappy[MAX], maxsad[MAX];
int main(){
    cin >> n;
    for(int i=1;i<=n;i++)cin >> arr[i].first >> arr[i].second;
    int a = 1e9, b = arr[1].second;
    for(int i=1;i<=n;i++){
        if(arr[i].first!=0)a = min(a,arr[i].first); //if it is zero, everything will be zero...
        else if(minhappy[i-1]==0)a=0;
        minhappy[i] = a;
        b= max(b,arr[i].second);
        maxsad[i] = b;
        
    }
    int hi = n-1, lo = 0;
    while(hi!=lo){
        int mid = (hi+lo+1)/2;
        //until mid is youth i guess
        bool yes = true;
        for(int i=mid;i<=n;i++){
            if(arr[i].first>minhappy[mid] or arr[i].second < maxsad[mid]){
                yes = false;
                break;
            }
        }
        if(yes){
            lo = mid;
        }else hi = mid-1;
        
    }
    if(hi!=0)cout << hi;
    else cout << -1;
    
    return 0;
}
