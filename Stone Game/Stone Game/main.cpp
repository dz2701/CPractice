//
//  main.cpp
//  Stone Game
//
//  Created by Shin Lee on 2/28/21.
//

#include <bits/stdc++.h>
using namespace std;
int n; const int MAX = 2e6+1;
int arr[MAX];
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int temp; cin >> temp; arr[temp]++;
    }
    for(int i=1;i<MAX;i++)arr[i]+=arr[i-1];
    
    long long ans = 0;
    
    for(int i=1;i<=1e6;i++){
        vector<int>v;
        vector<int>c;
        
        for(int j=i;j<=1e6;j+=i){
            //j~j+i -> same no.
            if((arr[j+i-1]-arr[j-1])%2==1){
                v.push_back(j); c.push_back(arr[j+i-1]-arr[j-1]);
            }
        }
        if(v.size()==1 and v[0]==i){
            ans+=c[0];
        }else if(v.size()==2 and v[0]==v[1]-i){
            ans+=c[1];
        }
    }
    cout << ans;
    return 0;
}
