//
//  main.cpp
//  River Hopscotch
//
//  Created by Shin Lee on 24/03/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, d, m; int arr[50005];int dist[50005];
int main(){
    cin >> d >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    arr[n]=0; arr[n+1]=d;
    sort(arr,arr+n+2);
    
    int hi = d, lo = 1;
    while(hi>lo){
       // printf("hi = %d, lo = %d\n",hi,lo);
        int mid = (hi+lo+1)/2;
        int pos=0;int cnt=0;
        for(int i=1;i<=n+1;i++){
            if(arr[i]-arr[pos]<mid){

                cnt++;
            }else {
                pos = i;
            }
        }
        if(cnt<=m){
            lo = mid;
        }else hi = mid-1;
        
    }
    cout << lo;
    
}
