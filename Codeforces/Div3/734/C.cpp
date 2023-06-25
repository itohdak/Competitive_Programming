#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; cin >> n;
  vector<string> S(n); rep(i, n) cin >> S[i];
  vector<vector<int>> cnt(n, vector<int>(5));
  rep(i, n) {
    for(auto c: S[i]) {
      cnt[i][c-'a']++;
    }
  }
  int ans = 0;
  rep(j, 5) {
    priority_queue<int> q;
    rep(i, n) {
      q.push(cnt[i][j]-(S[i].size()-cnt[i][j]));
    }
    int a = 0;
    int tmp = 0;
    while(q.size() && tmp + q.top() > 0) {
      a++;
      tmp += q.top(); q.pop();
    }
    chmax(ans, a);
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
