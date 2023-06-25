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
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<ll> B(m);
  vector<set<int>> st(m);
  rep(i, m) {
    cin >> B[i];
    int c; cin >> c;
    rep(j, c) {
      int k; cin >> k;
      k--;
      st[i].insert(k);
    }
  }
  vector<int> member;
  int ans = 0;
  auto dfs = [&](auto dfs, int cur) -> void {
    if(cur == n) {
      if(member.size() < 9) return;
      int point = 0;
      for(int i: member) point += A[i];
      rep(j, m) {
        int cnt = 0;
        for(int i: member) {
          if(st[j].count(i)) cnt++;
        }
        if(cnt >= 3) point += B[j];
      }
      chmax(ans, point);
      return;
    }
    dfs(dfs, cur+1);
    if(member.size() < 9) {
      member.push_back(cur);
      dfs(dfs, cur+1);
      member.pop_back();
    }
  };
  dfs(dfs, 0);
  cout << ans << endk;
  return 0;
}
