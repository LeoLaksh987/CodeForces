#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    
    int n;
    cin>>n;

    string s, t;
    cin>>s;
    cin>>t;

    if(n==1){
        if(s[0] != t[0]){
            cout<<"NO"<<'\n';
            return;
        }

        cout<<"YES"<<'\n';
        return;
    }

    bool flag = true;

    for(int i=0;i<n;i++){
        if(s[i] != t[i]){
            flag = false;
            break;
        }
    }

    if(flag){
        cout<<"YES"<<'\n';
        return;
    }

    bool f = false;

    for(int i=0;i<n;i++){
        if(s[i] == '0' && t[i] == '1'){
            f = true;
            break;
        }

        if(s[i] == '1'){
            break;
        }
    }

    if(f){
        cout<<"NO"<<'\n';
        return;
    }


    cout<<"YES"<<'\n';
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