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
  ll a, b, c; cin >> a >> b >> c;
  vector<vector<int>> need(3, vector<int>(7));
  need[0] = {1, 0, 0, 1, 0, 0, 1};
  need[1] = {0, 1, 0, 0, 0, 1, 0};
  need[2] = {0, 0, 1, 0, 1, 0, 0};
  auto calc = [&](int s) {
    ll a_ = a, b_ = b, c_ = c;
    vector<vector<int>> sum(3, vector<int>(7));
    rep(i, 7) {
      rep(j, 3) {
        sum[j][i] += need[j][(s+i)%7];
        if(i) sum[j][i] += sum[j][i-1];
      }
    }
    ll week = min({a_/sum[0][6], b_/sum[1][6], c_/sum[2][6]});
    a_ -= week * sum[0][6];
    b_ -= week * sum[1][6];
    c_ -= week * sum[2][6];
    ll day = inf;
    chmin(day, upper_bound(all(sum[0]), a_)-begin(sum[0]));
    chmin(day, upper_bound(all(sum[1]), b_)-begin(sum[1]));
    chmin(day, upper_bound(all(sum[2]), c_)-begin(sum[2]));
    assert(day < 7);
    return 7*week+day;
  };
  ll ans = 0;
  rep(i, 7) chmax(ans, calc(i));
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
