//
//  main.cpp
//  Favorite Colors
//
//  Created by Shin Lee on 2/26/21.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5+5;
int n, m;
set<int>child[MAX];

int main(){
    //freopen("fcolor.in","r",stdin);
    //freopen("fcolor.out","w",stdout);
    cin >> n >> m;
    queue<int>q;
    for(int i=1;i<=m;i++){
        int a, b; cin >> a >> b;
        child[b].insert(a);
    }
    int arr[MAX];
    for(int i=1;i<=n;i++){
        arr[i]=i;q.push(i);
    }
    while(!q.empty()){
        int node = arr[q.front()]; q.pop();
        if(child[node].size()<=1)continue;
        int changed_node = *child[node].begin(); //this will be the one merged gigantic node
        for(int child_nodes : child[node]){
            child_nodes = arr[child_nodes];
            for(int connection : child[child_nodes]){
                child[changed_node].insert(arr[connection]);
            }
            arr[child_nodes] = changed_node;
        }
        q.push(changed_node);
        child[node].clear(); child[node].insert(changed_node);
    }
    int val[MAX]; int cnt = 1;
    for(int i=1;i<=n;i++){
        if(!val[arr[i]]){
            val[arr[i]]=cnt++;
        }
        printf("%d\n",val[arr[i]]);
    }
    return 0;
}
