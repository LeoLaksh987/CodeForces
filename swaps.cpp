#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    
    int n;
    cin>>n;

    vector<int> a(n), b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        cin>>b[i];
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