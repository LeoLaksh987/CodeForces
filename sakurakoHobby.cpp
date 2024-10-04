#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    
    int n;
    cin>>n;

    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    string str;
    cin>>str;

    vector<bool> vis(n+1, false);
    vector<int> ans(n+1);
    

    for(int i=1;i<=n;i++){
        int cnt = 0;
        vector<int> idxs;

        if(i == v[i]){
            if(str[i-1] == '0'){
                ans[i] = 1;
            }

            else{
                ans[i] = 0;
            }
        }

        while(i != v[i] && vis[i] != true){
            int nextIdx = v[i];
            vis[i] = true;
            idxs.push_back(i);

            // cout<<i<<'\n';

            if(str[i-1] == '0'){
                cnt++;
            }
            i = nextIdx;
        }

        // cout<<cnt<<'\n';

        if(cnt != 0){
            for(int j=0;j<(int)idxs.size();j++){
                ans[idxs[j]] = cnt;
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }cout<<'\n';
    return;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t=1;
    cin>>t;
    
    while(t--){
        solve();
    }
    
    return 0;
}