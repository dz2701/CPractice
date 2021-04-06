//
//  main.cpp
//  Directory Traversal
//
//  Created by Shin Lee on 12/16/20.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
vector<int>adj[MAX], dir, leaf;
long long values[MAX], height[MAX], sz[MAX];;
int childcount[MAX], isleaf[MAX], n;

int dfs(int cur, int par, int vv, long long val){ //returns number of child
    for(int con : adj[cur]){
        if(con!=par){
            childcount[cur]+=dfs(con,cur,vv+1, val+sz[con]+1);
        }
    }
    height[cur] = vv;
    values[cur] = val;
    
    if(adj[cur].size()==0)return childcount[cur]+1;
    else return childcount[cur];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("dirtraverse.in","r",stdin);
    //freopen("dirtraverse.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        string temp; int m;
        cin >> temp >> m;
        if(m)dir.push_back(i);
        else {
            leaf.push_back(i);
            isleaf[i]=1;
        }
        sz[i] = temp.size();
        while(m--){
            int c; cin >> c;
            adj[i].push_back(c);
        }
    }
    
    dfs(1,-1,0,-1);
    long long value_from_root = 0;
    
    for(auto i:leaf)value_from_root+= values[i];
    long long ans = value_from_root;
    //now let's get the values from each directory
    for(int dirnum : dir){
        if(dirnum==1)continue;
        long long num_of_non_child = leaf.size() - childcount[dirnum];
        long long newval = value_from_root - childcount[dirnum]*(values[dirnum]+1) + num_of_non_child*3*height[dirnum];
        printf("newval at %d = %lld\n",dirnum,newval);
        //printf("case %d: newval = %d - %d*%d + %d * 3 * %lld = %d\n",dirnum,value_from_root,childcount[dirnum],values[dirnum],num_of_non_child,height[dirnum],newval);
        ans = min(newval, ans);
    }
    cout << ans;
    return 0;
}
