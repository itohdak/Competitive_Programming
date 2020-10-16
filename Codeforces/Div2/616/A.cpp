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
  string s; cin >> s;
  vector<int> d(n);
  ll sum = 0;
  rep(i, n) {
    d[i] = s[i]-'0';
    sum += d[i];
  }
  int r = 0;
  rrep(i, n) {
    if(d[i]%2 == 0) {
      sum -= d[i];
    } else {
      r = i;
      break;
    }
  }
  if(sum == 0) {
    cout << -1 << endk;
  } else if(sum%2 == 0) {
    rep(i, r+1) cout << d[i];
    cout << endk;
  } else {
    int odd = 0;
    rep(i, r) if(d[i] % 2 == 1) odd++;
    if(odd == 0 || (odd == 1 && d[0]%2 && d[1] == 0)) {
      cout << -1 << endk;
    } else {
      bool done = false;
      vector<int> ans;
      ans.push_back(d[r]);
      rrep(i, r) {
        if(!done && d[i]%2) done = true;
        else ans.push_back(d[i]);
      }
      reverse(all(ans));
      for(int i: ans) cout << i;
      cout << endk;
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
