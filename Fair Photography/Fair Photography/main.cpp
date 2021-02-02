//
//  main.cpp
//  Fair Photography
//
//  Created by Shin Lee on 1/7/21.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int n;
pair<int,char>cow[MAX];
bool cmp(pair<int,int>a,pair<int,int>b){return a.first<b.first;}
int psum[MAX];
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> cow[i].first >> cow[i].second;
    }
    sort(cow+1,cow+n,cmp);
    
    int temp = 0;
    for(int i=1;i<=n;i++){
        printf("cow[%d] = %d %c\n",i,cow[i].first,cow[i].second);
        temp+= cow[i].second=='W'? 1 : -1;
        psum[i]=temp;
    }
    
    for(int i=1;i<=n;i++){
        printf("%d ",psum[i]);
    }
    printf("\n\n\n");
    vector<int>val[2];
    int pos[2][MAX];
    //init "END"
    for(int i=n;i>=1;i--){
        if(val[i%2].empty() or *(val[i%2].rbegin()) < psum[i]){
            val[i%2].push_back(psum[i]);
            pos[i%2][val[i%2].size()-1] = cow[i].first;
        }
    }
    
    for(int i=0;i<=1;i++){
        printf("val[%d]:\n",i);
        for(int j=0;j<val[i].size();j++){
            printf("%d: %d ",pos[i][j],val[i][j]);
        }
        printf("\n");
    }
    
    
    int ans = 0;
    for(int i=1;i<=n;i++){
        int idx = (i+1)%2;
        ans = max(ans, pos[(i+1)%2][lower_bound(val[idx].begin(), val[idx].end(), psum[i]) - val[idx].begin()] - cow[i].first);
    }
    cout << ans;
}
