#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
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
  int n, k; cin >> n >> k;
  string s; cin >> s;
  bool ok = true;
  auto check = [&](int i, int j) {
    if(s[i] == '?' && s[j] == '?') {
      return true;
    } else if(s[i] == '?') {
      s[i] = s[j];
      return true;
    } else if(s[j] == '?') {
      s[j] = s[i];
      return true;
    } else {
      if(s[i] == s[j]) return true;
      else return false;
    }
  };
  rep(i, n) {
    if(i+k >= n) continue;
    ok &= check(i, i+k);
  }
  rrep(i, n) {
    if(i+k >= n) continue;
    ok &= check(i, i+k);
  }
  // cout << s << endk;
  int cnt[2] = {0, 0};
  rep(i, k) {
    if(s[i] != '?') cnt[s[i]-'0']++;
  }
  if(cnt[0] > k/2 || cnt[1] > k/2) ok = false;
  REP(i, k, n) {
    if(s[i] != '?') cnt[s[i]-'0']++;
    if(s[i-k] != '?') cnt[s[i-k]-'0']--;
    if(cnt[0] > k/2 || cnt[1] > k/2) ok = false;
  }
  cout << (ok ? "YES" : "NO") << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
