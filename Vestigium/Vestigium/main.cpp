//
//  main.cpp
//  Vestigium
//
//  Created by Shin Lee on 2/27/21.
//

#include <bits/stdc++.h>
using namespace std;

int t;
int arr[101][101];
int check[101];
int main(){
    cin >> t;
    int idx=0;
    while(t--){
        printf("%d\n",idx);
        int hor=0, ver=0, ans=0;
        int n; cin >> n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)cin >> arr[i][j];
        }
        for(int i=1;i<=n;i++){
            printf("%d line\n",i);
            for(int p=1;p<=n;p++)check[p]=0;
            for(int j=1;j<=n;j++){
                if(check[arr[i][j]]){hor++;break;}
                check[arr[i][j]]++;
                for(int p=1;p<=n;p++)printf("%d ",check[p]);
                printf("\n");
            }
            printf("\n");
            
        }
        for(int i=1;i<=n;i++){
            printf("%d line\n",i);
            for(int p=1;p<=n;p++)check[p]=0;
            for(int j=1;j<=n;j++){
                if(check[arr[j][i]]){ver++;break;}
                check[arr[j][i]]++;
                for(int p=1;p<=n;p++)printf("%d ",check[p]);
                printf("\n");
            }
            printf("\n");
        }
        for(int i=1;i<=n;i++)ans+=arr[i][i];
        printf("Case #%d: %d %d %d\n",++idx,ans,hor,ver);
    }
    
    
}
