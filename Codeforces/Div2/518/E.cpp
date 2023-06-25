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
  int n; ll k; cin >> n >> k;
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<vector<int>> buff(2);
  int flag = 0;
  set<int> done;
  rep(i, n) {
    if(G[i].size() == 1) {
      buff[1].push_back(i);
      done.insert(i);
    }
  }
  while(1) {
    k--;
    map<int, int> cnt;
    buff[flag].clear();
    for(int i: buff[1-flag]) {
      int tmp = 0;
      for(int ne: G[i]) {
        if(!done.count(ne)) {
          buff[flag].push_back(ne);
          cnt[ne]++;
          tmp++;
        }
      }
      if(tmp == 0) {
        cout << "No" << endk;
        return 0;
      }
    }
    if(cnt.size() == 1) {
      if(cnt.begin()->second < 3) {
        cout << "No" << endk;
        return 0;
      } else {
        if(k == 0 && done.size()+1 == n) {
          cout << "Yes" << endk;
          return 0;
        } else {
          cout << "No" << endk;
          return 0;
        }
      }
    } else if(cnt.size() >= 3) {
      for(auto ele: cnt) {
        if(ele.second < 3) {
          cout << "No" << endk;
          return 0;
        }
      }
      sort(all(buff[flag]));
      buff[flag].erase(unique(all(buff[flag])), end(buff[flag]));
      for(int i: buff[flag]) done.insert(i);
    } else {
      cout << "No" << endk;
      return 0;
    }
    flag = 1-flag;
  }
  return 0;
}
