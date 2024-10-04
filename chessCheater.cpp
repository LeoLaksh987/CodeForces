#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    
    int n, k;
    cin>>n>>k;

    string s;
    cin>>s;

    // int cntL = 0;

    // for(int i=0;i<n;i++){
    //     if(s[i] == 'L'){
    //         cntL++;
    //     }
    // }

    int cnt = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'L'){
            cnt++;
        }

        else{
            ans++;
            if(i>0 && s[i-1] == 'W'){
                ans++;
            }
        }
    }

    k = min(k, cnt);

    if(k == cnt){
        cout<<2*n - 1<<'\n';
        return;
    }

    if(cnt == n){
        cout<<max(2*k-1, 0)<<'\n';
        return;
    }

    ans += 2*k;

    vector<int> vec;
    for(int i=1;i<n;i++){
        if(s[i] == 'W'){
            continue;
        }

        if(s[i-1] != 'W'){
            continue;
        }

        int idx = i;
        while(idx<n && s[idx] == 'L'){
            idx++;
        }

        if(idx < n){
            vec.push_back(idx-i);
        }

        i = idx - 1;
    }

    sort(vec.begin(), vec.end());

    for(int it: vec){
        if(k >= it){
            ans++;
            k -= it;
        }
    }
    

    cout<<ans<<'\n';
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