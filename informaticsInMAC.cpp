#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    bool flag = false;
    for(int i=0;i<n-1;i++){
        if(v[i] != v[i+1]){
            flag = true;
        }
    }

    if(flag == false){
        for(int i=0;i<n;i++){
            cout<<i+1<<" "<<i+1<<'\n';
        }cout<<'\n';
        return;
    }

    set<int> s;

    // int k = 0;
    // for(int i=0;i<=n;i++){
    //     if(s.find(i) == s.end()){
    //         mexVal = i;
    //         break;
    //     }
    // }


    int mexVal = 0;
    vector<int> prefmex(n, 0), suffmex(n,0);

    for(int i=0;i<n;i++){
        s.insert(v[i]);
        while(s.find(v[i]) != s.end()){
            mexVal++;
        }

        prefmex[i] = mexVal;
    }

    mexVal = 0;
    s.clear();

    for(int i=n-1;i>=0;i--){
        s.insert(v[i]);
        while(s.find(v[i]) != s.end()){
            mexVal++;
        }

        suffmex[i] = mexVal;
    }

    int idx = -1;

    for(int i=0;i<n;i++){
        if(prefmex[i] == suffmex[i+1]){
            idx = i+1;
            break;
        }
    }

    if(idx == -1){
        cout<<-1<<'\n';
    }

    else{
        cout<<2<<'\n';
        cout<<1<<" "<<idx<<'\n';
        cout<<idx + 1<<" "<<n<<'\n';
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