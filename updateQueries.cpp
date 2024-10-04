#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    
    int n, m;
    cin>>n>>m;

    string s;
    cin>>s;

    vector<int> v(m);
    set<int> s;
    for(int i=0;i<m;i++){
        cin>>v[i];
        s.insert(v[i]-1);
    }

    string c;
    cin>>c;

    sort(c.begin(), c.end());

    // int sz = s.size();

    int cnt = 0;
    for(auto &it: s){
        int idx = *s.begin();
        s[idx] = c[cnt];
        cnt++;
    }

    cout<<s<<'\n';
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