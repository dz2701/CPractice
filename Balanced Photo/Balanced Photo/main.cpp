//
//  main.cpp
//  Balanced Photo
//
//  Created by Shin Lee on 2/24/21.
//

#include <bits/stdc++.h>
using namespace std;

int n;
const int MAX = 1e6+5;
vector<pair<int,int>>arr;
int cnt[MAX];
int fw[MAX];

int query(int p){
    int ret = 0;
    for(;p;p-=p&-p){
        ret+=fw[p];
    }return ret;
}
void update(int p, int v){
    for(;p<MAX;p+=p&-p){
        fw[p]+=v;
    }
}

int Right[MAX], Left[MAX];
int main(){
    freopen("bphoto.in","r",stdin);
    freopen("bphoto.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        int temp; cin >> temp;
        arr.push_back({temp,i});
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        cnt[arr[i].second] = i+1;
    }
    for(int i=1;i<=n;i++){
        //update value
        update(cnt[i],1);
        //now query for values bigger than this: this will give he number of values bigger than i to the LEFT
        Left[i] = i-query(cnt[i]);
    }
    fill(&fw[0],&fw[MAX-1],0);//reset fenwick tree
    for(int i=n;i>=1;i--){
        //update value
        update(cnt[i],1);
        //now query, but this time it is values larger to the RIGHT
        Right[i] = (n-i+1)-query(cnt[i]);
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(Right[i]>Left[i]*2 or Left[i]>Right[i]*2){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
