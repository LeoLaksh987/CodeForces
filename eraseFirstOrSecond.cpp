#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    
    int n;
    cin>>n;

    string s;
    cin>>s;

    vector<int> dp(n, 0);

    dp[n-1] = 1;
    int eleAfter = 1;

    unordered_map<char, int> mp;
    mp[s[n-1]] = n-1;

    for(int i=n-2;i>=0;i--){

        int prev = mp[s[i]];

        mp[s[i]] = i;

        if(s[i] == s[i+1]){
            dp[i] = dp[i+1] + 1;
        }

        else{
            dp[i] = dp[i+1] + eleAfter + 1;
        }

        if(prev){
            dp[i] = dp[i+1] + (prev - i);
        }


        eleAfter++;
    }

    cout<<dp[0]<<'\n';
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