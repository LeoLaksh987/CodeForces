#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    
    ll n, k;
    cin>>n>>k;

    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        v[i] = pow(10 , v[i]);
    }

    ll ans = 0;

    for(ll i=0;i<n-1;i++){

        ll cur = v[i];
        ll nxt = v[i+1];

        if(k > cur * (cur * 10 - 1)){
            k -= cur * (cur* 10 - 1);
        }

        

    }




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