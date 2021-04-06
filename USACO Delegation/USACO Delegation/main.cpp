//
//  main.cpp
//  USACO Delegation
//
//  Created by Shin Lee on 12/8/20.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int n;
vector<int>adj[MAX];
int dfs(int now, int parent, int k){
    //printf("looking at dfs(%d,%d,%d):\n",now,parent,k);
    if(!adj[now].size()){
        //printf("dfs(%d,%d,%d)=0\n",now,parent,k);
        return 0;
    }
    multiset<int>s;
    for(int con: adj[now]){
        if(con != parent){
            int temp = dfs(con,now,k);
            if(temp==-1){
                return -1;
            }
            s.insert((temp+1)%k);
        }
    }
    //printf("s size = %d\n",s.size());
    vector<int>v;
    while(!s.empty()){
        int l = *s.begin(); s.erase(s.begin());
        if(l==0)continue;
        auto it = s.find(k-l);
        if(it!=s.end()){
            s.erase(it);
        }else{
            v.push_back(l); //no matching pair
        }
    }
    if(v.size()==1){
        //printf("dfs(%d,%d,%d) = %d\n",now,parent,k,*v.begin());
        return *v.begin();
    }
    else if(v.size()>1){
        //printf("dfs(%d,%d,%d) = -1\n",now,parent,k);
        return -1;
    }
    else if(!v.size()){
        //printf("dfs(%d,%d,%d) = 0 c3\n",now,parent,k);
        return 0;
    }else return NULL;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("deleg.in","r",stdin);
    freopen("deleg.out","w",stdout);
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    string ans = "1";
    for(int k=2;k<=n-1;k++){
        if((n-1)%k!=0){
            ans.push_back('0');
            continue;
        }
        if(dfs(1,-1,k)==0)ans.push_back('1');
        else ans.push_back('0');
    }
    cout << ans;
    return EXIT_SUCCESS;
}

