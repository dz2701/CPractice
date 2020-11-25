//
//  main.cpp
//  Why Did the Cow Cross the Road III (Gold)
//
//  Created by dz2701 on 11/23/20.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e4+1;
int n; int arr[2*MAX];
int check[MAX];
int fw[2*MAX];
int query(int p){
    int ret = 0;
    for(; p; p-=p&-p){
        ret+=fw[p];
    }
    return ret;
}
void update(int p, int v){
    for(; p<MAX; p+=p&-p){
        fw[p] += v;
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int ans =0;
    for(int i=1;i<=2*n;i++){
        int now;
        cin >> now;
        //if not included...
        if(!check[now]){
            check[now]=i;
            update(i,1);
        }else{
            ans += query(i-1) - query(check[now]);
            update(i,-1 * (query(i)-query(i-1)));
            update(check[now],-1 * (query(check[now])-query(check[now]-1)));
        }
    }
    cout << ans;
}
