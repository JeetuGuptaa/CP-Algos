#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Hash{
    vector<pair<int, int>> power;
    vector<pair<int, int>> prefixHash;
    string s;
    static const int B1 = 683; 
    static const int B2 = 401;
    static const int M = 1000000209;
    
    void buildHash(){
        for(int i = 0; i<s.size(); i++){
            int P1 = ((ll)power[i].first * B1)%M;
            int P2 = ((ll)power[i].second * B2)%M;
            power[i+1] = {P1, P2};
            int H1 = ((ll)prefixHash[i].first*B1)%M + (s[i] - 'a');
            int H2 = ((ll)prefixHash[i].second*B2)%M + (s[i] - 'a');
            prefixHash[i+1] = {H1, H2};
            cout<<H1<<" "<<H2<<endl; 
        }
        
    }
    
    public:
    Hash(string s){
        this -> s = s;
        power = vector<pair<int, int>>(s.size() + 1, {1, 1});
        prefixHash = vector<pair<int, int>>(s.size() + 1, {0, 0});
        buildHash();
    }
    
    pair<int, int> getHash(int L, int R){
        L++;
        R++;
        int size = R - L + 1;
        int subtractor1 = ((ll)prefixHash[L-1].first * (ll)power[size].first)%M;
        int subtractor2 = ((ll)prefixHash[L-1].second *  (ll)power[size].second)%M;
        
        int H1 = (prefixHash[R].first - subtractor1 + M)%M;
        int H2 = (prefixHash[R].second - subtractor2 + M)%M;
        
        return {H1, H2};
    }
};

int main(){
  string s;
  cin>>s;
  Hash h(s);
  return 0;
}