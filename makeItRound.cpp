#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    
    ll n, m;
    cin>>n>>m;

    ll num2 = 0;
    ll num5 = 0;
    ll val = n;

    ll k = 1;

    while(n > 0 && n%2 == 0){
        num2++;
        n /= 2;
    }

    while(n > 0 && n%5 == 0){
        num5++;
        n /= 5;
    }

    while(num5 > num2 && k * 2 <= m){
            k *= 2;
            num2++;
    }

    while(num2 > num5 && k*5 <= m){
            k *= 5;
            num5++;
    }

    while(k * 10 <= m){
        k = k * 10;
    }

    if(k == 1){
        cout<<val * m<<'\n';
        return;
    }

    k = k * (m/k);
    cout<<val * k<<'\n';

    
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