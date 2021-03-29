//
//  main.cpp
//  Dance Mooves Gold
//
//  Created by Shin Lee on 2/26/21.
//

#include <bits/stdc++.h>
using namespace std;
long long n, k, m;
const long long MAX = 1e5+5;
set<pair<long long,long long>>s[MAX];
long long arr[MAX];
long long visit[MAX];
long long endpos[MAX];
vector<long long>cycle;
map<long long,long long>cnt;
long long val;
void dfs(long long node){
    if(visit[node])return;
    visit[node]=1;
    cycle.push_back(node);
    for(pair<long long,long long> dest:s[node]){
        if(!cnt[dest.first])val++;
        cnt[dest.first]++;
    }
    dfs(endpos[node]);
}
long long ans[MAX];
int main(){
    cin >> n >> k >> m;
    long long num = m/k;
    for(long long i=1;i<=n;i++){
        arr[i]=i; s[i].insert({i,1});
    }
    for(long long i=1;i<=k;i++){
        long long a, b; cin >> a >> b;
        swap(arr[a],arr[b]);
        s[arr[a]].insert({a,i}); s[arr[b]].insert({b,i});
    }
    for(long long i=1;i<=n;i++)endpos[arr[i]]=i;
    for(long long i=1;i<=n;i++){
        if(visit[i])continue;
        cnt.clear(); cycle.clear(); val = 0;
        dfs(i);
        //if the period is smaller or equal to M
        if(cycle.size() <= num){
            for(long long node:cycle){
                ans[node] = val;
            }
        }else{
            long long rem = m%k;
            //for each member of cycle i,
            //it can reach until ci~ci+num, and for ci+num+1 it can reach its dest from 1~rem.
            //printf("value = %d\n",val);
            //0~num-1.
            //initial calculation of ci. get rid of unused cycles..
           // printf("initial calculation: deleting cycle...\n");
            for(long long i=num;i<cycle.size();i++){
                //printf("at step %d: %d\n",i,cycle[i]);
                for(auto dest:s[cycle[i]]){
                    //printf("getting rid of dest %d\n",dest.first);
                    if(cnt[dest.first]==1){
                        //printf("value decreased!!\n");
                        val--;
                    }
                    cnt[dest.first]--;
                    //printf("cnt[%d]: %d -> %d\n",dest.first,cnt[dest.first]+1, cnt[dest.first]);
                }
            }
            //then consider the remainder of cycle that's in M
            //printf("adding remainder cycle: %d\n",num);
            for(auto dest:s[cycle[num]]){
                if(dest.second<=rem){
                    if(cnt[dest.first]==0){
                        val++;
                        //printf("value increased!!\n");
                    }
                    cnt[dest.first]++;
                    //printf("cnt[%d]: %d -> %d\n",dest.first,cnt[dest.first]-1, cnt[dest.first]);
                }
                
            }
            ans[cycle[0]]=val;
            
            //then go through loop for values 1~num+1, 2~num+2, ..., cycle.size()-num~cycle.size();
            
            for(long long i=1;i<cycle.size();i++){
                //i~i+num
                //printf("looking at step %d: window %d~%d\n",i,i,i+num);
                
                //subtract all values from cycle i-1
                //printf("removing values from cycle %d\n",i-1);
                for(auto dest:s[cycle[i-1]]){
                    if(cnt[dest.first]==1){
                        val--;
                        //printf("value decreased!!\n");
                    }
                    cnt[dest.first]--;
                    //printf("cnt[%d]: %d -> %d\n",dest.first,cnt[dest.first]+1, cnt[dest.first]);
                }
                
                //add remaining values from cycle i+num
                //printf("adding remaining values from cycle %d\n",i+num-1);
                for(auto dest:s[cycle[(i+num-1)%cycle.size()]]){
                    if(dest.second>rem){
                        if(cnt[dest.first]==0){
                            val++;
                            //printf("value increased!!\n");
                        }
                        cnt[dest.first]++;
                        //printf("cnt[%d]: %d -> %d\n",dest.first,cnt[dest.first]-1, cnt[dest.first]);
                    }
                }
                
                //now add the remainder of cycle that's in M.
                for(auto dest:s[cycle[(i+num)%cycle.size()]]){
                    if(dest.second<=rem){
                        if(cnt[dest.first]==0){
                            val++;
                            //printf("value increased!!\n");
                        }
                        cnt[dest.first]++;
                        //printf("cnt[%d]: %d -> %d\n",dest.first,cnt[dest.first]-1, cnt[dest.first]);
                    }
                }
                //printf("final result: %d\n",val);
                ans[cycle[i]] = val;
            }
        }
        
    }
    for(long long i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
    
}
