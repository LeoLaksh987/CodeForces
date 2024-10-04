#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll oper(ll x){
    ll ops = 0;

    while(x != 0){
        x /= 3;
        ops++;
    }

    return ops;
}


void solve(vector<ll> &v){

    ll l, r;
    cin>>l>>r;

    ll a = v[r] - v[l-1];
    ll b = v[l] - v[l-1];
    cout<<a+b<<'\n'; 
    return;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t=1;
    cin>>t;

    ll n = 2e5;
    vector<ll> v(n+2, 0);

    for(ll i=1;i<=n;i++){
        ll ops = oper(i);
        v[i] = ops + v[i-1];
    }
    
    while(t--){
        solve(v);
    }
    
    return 0;
}