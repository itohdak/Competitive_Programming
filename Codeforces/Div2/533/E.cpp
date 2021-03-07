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
  int n, m; cin >> n >> m;
  map<string, int> mp;
  vector<int> T(n);
  vector<string> S(n);
  rep(i, n) {
    cin >> T[i];
    if(T[i] == 2) {
      cin >> S[i];
      mp[S[i]] = 0;
    }
  }
  vector<vector<int>> G(n);
  int cnt = 0;
  for(auto& ele: mp) ele.second = cnt++;
  vector<int> v;
  rep(i, n) {
    if(T[i] == 1) {
      rep(j, v.size()) rep(k, v.size()) {
        if(j != k) G[j].push_back(k);
      }
      v.clear();
    } else {
      v.push_back(i);
    }
  }
  rep(j, v.size()) rep(k, v.size()) {
    if(j != k) G[j].push_back(k);
  }
  
  return 0;
}
