#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  string t1 = "abacaba";
  int n1 = t1.size();
  auto check = [&](string s) {
    int cnt = 0;
    rep(i, n) {
      if(i+n1>n) break;
      if(s.substr(i, n1) == t1) cnt++;
    }
    return cnt == 1;
  };
  rep(i, n) {
    if(i+n1>n) break;
    bool ok = true;
    rep(j, n1) {
      if(s[i+j] != '?' && s[i+j] != t1[j]) {
        ok = false;
        break;
      }
    }
    if(ok) {
      string t = s;
      rep(j, n1) t[i+j] = t1[j];
      rep(i, n) if(t[i] == '?') t[i] = 'z';
      if(check(t)) {
        cout << "YES" << "\n";
        cout << t << "\n";
        return;
      }
    }
  }
  cout << "NO" << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
