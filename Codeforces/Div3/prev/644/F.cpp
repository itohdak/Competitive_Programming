#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int N, M;
  cin >> N >> M;
  vector<string> A(N);
  rep(i, N) cin >> A[i];
  string ans = "";
  rep(j, M) {
    map<char, int> mp;
    rep(i, N) mp[A[i][j]]++;
    if(mp.size() == 1) {
      ans += mp.begin()->first;
      continue;
    }
    for(auto m: mp) {
      set<string> se;
      rep(i, N) {
        if(A[i][j] != m.first) se.insert(A[i].substr(j+1));
      }
      if(se.size() == 1) {
        string tmp = ans + m.first + *se.begin();
        bool ok = true;
        rep(i, N) {
          int cnt = 0;
          rep(k, M) {
            if(A[i][k] != tmp[k]) cnt++;
          }
          if(cnt > 1) {
            ok = false;
            break;
          }
        }
        if(!ok) continue;
        cout << tmp << endl;
        return;
      } else {
        continue;
      }
    }
    cout << -1 << endl;
    return;
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
