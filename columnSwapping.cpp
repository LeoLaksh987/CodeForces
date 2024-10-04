#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    
    ll n, m;
    cin>>n>>m;

    vector<vector<ll>> v(n, vector<ll> (m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }

    set<ll> s;

    vector<vector<ll>> copy = v;
    for(int i=0;i<n;i++){
        sort(copy[i].begin(), copy[i].end());
        for(int j=0;j<m;j++){
            if(v[i][j] != copy[i][j]){
                s.insert(j);
            }
        }
    }

    if(s.size() == 2){
        for(int i=0;i<n;i++){
            int col1 = *s.begin();
            int col2 = *s.rbegin();
            swap(v[i][col1], v[i][col2]);

            if(is_sorted(v[i].begin(), v[i].end())){
                cout<<col1+1<<" "<<col2+1<<'\n';
                return;
            }
        }

        cout<<-1<<'\n';
        return;
    }

    else if(s.size() == 0){
        cout<<2<<" "<<2<<'\n';
        return;
    }

    else{
        cout<<-1<<'\n';
        return;
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