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
  string s; cin >> s;
  int n = s.size();
  vector<vector<int>> ans;
  deque<int> zero, one;
  rep(i, n) {
    if(s[i] == '0') {
      if(zero.empty()) {
        int j = ans.size();
        ans.push_back(vector<int>());
        ans[j].push_back(i);
        one.push_back(j);
      } else {
        int j = zero.front(); zero.pop_front();
        ans[j].push_back(i);
        one.push_back(j);
      }
    } else {
      if(one.empty()) {
        cout << -1 << endk;
        return 0;
      } else {
        int j = one.front(); one.pop_front();
        ans[j].push_back(i);
        zero.push_back(j);
      }
    }
  }
  if(zero.size()) {
    cout << -1 << endk;
  } else {
    cout << ans.size() << endk;
    for(auto v: ans) {
      cout << v.size() << ' ';
      for(auto i: v) cout << i+1 << ' ';
      cout << endk;
    }
  }
  return 0;
}
