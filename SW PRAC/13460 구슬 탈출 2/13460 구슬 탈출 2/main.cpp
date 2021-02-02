#include <bits/stdc++.h>
using namespace std;
pair<int,int> ans[10005];
int arr[10005]; map<string,int>m; int temp = 1;
vector<string> genres; vector<int> plays;
bool cmp(int a, int b){return a>b;}
int main() {
    genres.push_back("classic"); genres.push_back("pop"); genres.push_back("classic"); genres.push_back("classic"); genres.push_back("pop");
    plays.push_back(500); plays.push_back(600); plays.push_back(150); plays.push_back(800); plays.push_back(2500);
    vector<int>answer;
    
    for(int i=0;i<genres.size();i++){
        if(m[genres[i]]==0){
            m[genres[i]]=temp++;
            arr[m[genres[i]]]=plays[i];
            ans[m[genres[i]]] = {-1e9, -1e9};
        }else{
            arr[m[genres[i]]]+=plays[i];
        }
        
        if(ans[m[genres[i]]].first < plays[i]){
            ans[m[genres[i]]].first = plays[i];
        }else if(ans[m[genres[i]]std].second < plays[i]){
            ans[m[genres[i]]].second = plays[i];
        }
        
    }
    for(int i=1;i<=temp-1;i++){
        printf("%d ",arr[i]);
        printf("%d %d\n",ans[i].first, ans[i].second);
    }
    
    sort(arr+1,arr+temp-1);
    for(int i=1;i<=temp-1;i++){
        printf("id = %d\n",i);
        answer.push_back(ans[i].first);
        answer.push_back(ans[i].second);
    }
    for(int i:answer)cout << i << " ";
    return 0;
}
