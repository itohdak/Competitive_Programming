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
  vector<pair<int, int>> ans;
  ll pw = n;
  ll next_pw = 1;
  vector<ll> pws;
  while(next_pw * 16 < n) next_pw *= 16;
  while(next_pw) {
    for(int i=pw-1; i>next_pw; i--) {
      if(i != 2) ans.push_back({i, pw});
    }
    if(next_pw > 1) ans.push_back({pw, next_pw}); // 16
    pws.push_back(pw);
    pw = next_pw;
    next_pw /= 16;
  }
  rep(i, pws.size()-1) {
    ans.push_back({pws[i], pws[i+1]});
  }
  ans.push_back({min(16, n), 2});
  ans.push_back({min(16, n), 2});
  ans.push_back({min(16, n), 2});
  ans.push_back({min(16, n), 2});
  vector<int> validate(n+1);
  for(int i=1; i<=n; i++) validate[i] = i;
  assert(ans.size() <= n+5);
  cout << ans.size() << endk;
  for(auto p: ans) {
    cout << p.first << ' ' << p.second << endk;
    validate[p.first] = (validate[p.first]+validate[p.second]-1) / validate[p.second];
    // for(int i=1; i<=n; i++) cout << validate[i] << ' ';
    // cout << endk;
  }
  // for(int i=1; i<=n; i++) cout << validate[i] << ' ';
  // cout << endk;
  for(int i=1; i<=n; i++) {
    if(i == 2) {
      if(validate[i] != 2) assert(false);
    } else {
      if(validate[i] != 1) assert(false);
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
