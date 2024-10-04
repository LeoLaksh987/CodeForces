#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    
    string s, t;
    cin>>s;
    cin>>t;

    int len1 = s.length();
    int len2 = t.length();

    int matched = 0;
    int next = 0;
    bool flag = false;
    for(int i=0;i<len2;i++){
        for(int j=next;j<len1;j++){
            if(t[i] == s[j] || (s[j] == '?' && t[i] == s[j])){
                matched++;
                next = j+1;
                if(s[j] == '?' && t[i] == s[j]){
                    s[j] = t[i];
                    flag = true;
                }
                break;
            }
        }
    }

    if(flag == false && matched == len2){
        for(int i=0;i<len1;i++){
            if(s[i] == '?'){
                s[i] = 'a';
            }
        }
    }

    if(matched == len2){
        cout<<"YES"<<'\n';
        cout<<s<<'\n';
        return;
    }
    cout<<"NO"<<'\n';
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