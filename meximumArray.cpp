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

    vector<int> remove(n+2, 0), remg(n+2, 0);
    vector<int> ans;

    for(int i=1;i<=n;i++){
        remg[v[i]]++;
    }

    int idx = 1;

    while(idx <= n){
        int mexVal = 0;
        int lastIdx = n;

        for(int i=idx;i<=n;i++){
            remove[v[i]]++;

            while(remove[mexVal]){
                mexVal++;
            }

            remg[v[i]]--;

            if(i == n || remg[mexVal] == 0){
                lastIdx = i;
                break;
            }
        }

        for(int j=idx; j<=lastIdx;j++){
            remove[v[j]] = 0;
        }

        ans.push_back(mexVal);
        idx = lastIdx + 1;
    }

    int sz = ans.size();
    cout<<sz<<'\n';
    for(int i=0;i<sz;i++){
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