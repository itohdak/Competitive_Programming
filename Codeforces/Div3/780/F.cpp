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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int ans = 0;
  for(int len=1; len<=n; len++) {
    deque<pair<char, int>> q;
    int cnt = 0;
    int sum = 0;
    auto add = [&](int i) {
      if(s[i] == '-') sum--;
      else sum++;
      if(q.size()) {
        if(q.back().first == s[i]) {
          auto back = q.back();
          q.pop_back();
          back.second++;
          if(back.first == '-' && back.second%2 == 0) cnt++;
          q.push_back(back);
        } else {
          q.push_back({s[i], 1});
        }
      } else {
        q.push_back({s[i], 1});
      }
    };
    auto del = [&]() {
      assert(q.size());
      if(q.front().first == '-') sum++;
      else sum--;
      auto front = q.front();
      q.pop_front();
      front.second--;
      if(front.first == '-' && front.second%2 == 1) {
        cnt--;
      }
      if(front.second > 0) {
        q.push_front(front);
      }
    };
    rep(i, len) {
      add(i);
    }
    auto check = [&]() {
      // cout << sum << ' ' << cnt << ' ' << 0 << ' ' << len << endk;
      return sum%3 == 0 && sum <= 0 && 0 <= sum+3*cnt;
    };
    if(check()) ans++;
    for(int i=len; i<n; i++) {
      add(i);
      del();
      if(check()) ans++;
    }
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
