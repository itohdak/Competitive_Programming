#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, p; cin >> n >> p;
  string s; cin >> s;
  rep(i, p) {
    set<int> st;
    map<char, vector<int>> mp;
    for(int j=i; j<n; j+=p) {
      mp[s[j]].push_back(j);
    }
    // cout << mp << endk;
    if(mp.size() >= 2) {
      if(mp.count('.')) {
        for(int p: mp['.']) {
          if(mp.count('0')) s[p] = '1';
          else              s[p] = '0';
        }
        rep(k, n) if(s[k] == '.') s[k] = '0';
        cout << s << endk;
        return 0;
      } else {
        rep(k, n) if(s[k] == '.') s[k] = '0';
        cout << s << endk;
        return 0;
      }
    } else {
      if(mp.count('.') && mp['.'].size() >= 2) {
        s[mp['.'][0]] = '0';
        s[mp['.'][1]] = '1';
        rep(k, n) if(s[k] == '.') s[k] = '0';
        cout << s << endk;
        return 0;
      }
    }
  }
  cout << "No" << endk;
  return 0;
}
