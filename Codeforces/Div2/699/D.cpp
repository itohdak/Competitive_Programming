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
  int n, m; cin >> n >> m;
  vector<string> S(n);
  rep(i, n) cin >> S[i];
  if(m%2) {
    cout << "YES" << endk;
    rep(i, m+1) cout << (i%2 ? 2 : 1) << ' ';
    cout << endk;
    return;
  }
  bool ok = false;
  int a = -1, b = -1, c = -1;
  rep(i, n) {
    map<string, vector<int>> mp;
    rep(j, n) {
      if(j == i) continue;
      string s;
      s += S[i][j];
      s += S[j][i];
      mp[s].push_back(j);
    }
    if(mp["aa"].size()) {
      ok = true;
      a = i, b = mp["aa"][0], c = mp["aa"][0];
    }
    if(mp["bb"].size()) {
      ok = true;
      a = i, b = mp["bb"][0], c = mp["bb"][0];
    }
    if(mp["ab"].size() && mp["ba"].size()) {
      ok = true;
      a = i, b = mp["ab"][0], c = mp["ba"][0];
    }
    if(ok) {
      cout << "YES" << endk;
      if(m/2%2) {
        cout << b+1 << ' ';
        rep(i, m/2) cout << (i%2 ? b+1 : a+1) << ' ';
        rep(i, m/2) cout << (i%2 ? a+1 : c+1) << ' ';
        cout << endk;
      } else {
        cout << a+1 << ' ';
        rep(i, m/2) cout << (i%2 ? a+1 : b+1) << ' ';
        rep(i, m/2) cout << (i%2 ? a+1 : c+1) << ' ';
        cout << endk;
      }
      return;
    }
  }
  cout << "NO" << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
