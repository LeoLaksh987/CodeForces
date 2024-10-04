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
    }

    sort(v.begin(), v.end());
    if(k==0){
        ll aSum = 0;
        ll bSum = 0;

        for(int i=0;i<n;i+=2){
            aSum += v[i];
        }

        for(int i=1;i<n;i+=2){
            bSum += v[i];
        }

        cout<<abs(aSum - bSum)<<'\n';
        return;
    }

    reverse(v.begin(), v.end());

    ll ans = 0;
    for(int i=1;i<n;i+=2){
        ll diff = v[i-1] - v[i];
        if(diff <= k){
            k -= diff;
        }

        else{
            ans += diff - k;
            k = 0;
        }
    }

    if(n % 2 == 1){
        ans += v[n-1];
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