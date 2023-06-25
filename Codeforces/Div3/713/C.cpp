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
  int a, b; cin >> a >> b;
  string s; cin >> s;
  int n = s.size();
  if(n%2 == 0) {
    if(a%2 || b%2) {
      cout << -1 << endk;
      return;
    }
  } else {
    if(a%2) {
      if(s[n/2] == '?' || s[n/2] == '0') {
        s[n/2] = '0';
        a--;
      } else {
        cout << -1 << endk;
        return;
      }
    } else {
      if(s[n/2] == '?' || s[n/2] == '1') {
        s[n/2] = '1';
        b--;
      } else {
        cout << -1 << endk;
        return;
      }
    }
  }
  assert(a%2 == 0 && b%2 == 0);
  vector<int> spare;
  rep(i, n/2) {
    if(s[i] == '?' && s[n-1-i] == '?') {
      spare.push_back(i);
    } else if(s[i] == '?') {
      if(s[n-1-i] == '0') {
        s[i] = s[n-1-i] = '0';
        a -= 2;
      } else {
        s[i] = s[n-1-i] = '1';
        b -= 2;
      }
    } else if(s[n-1-i] == '?') {
      if(s[i] == '0') {
        s[i] = s[n-1-i] = '0';
        a -= 2;
      } else {
        s[i] = s[n-1-i] = '1';
        b -= 2;
      }
    } else {
      if(s[i] != s[n-1-i]) {
        cout << -1 << endk;
        return;
      }
      if(s[i] == '0') a -= 2;
      else b -= 2;
    }
  }
  if(a < 0 || b < 0) {
    cout << -1 << endk;
    return;
  }
  for(int i: spare) {
    if(a) {
      s[i] = s[n-1-i] = '0';
      a -= 2;
    } else {
      s[i] = s[n-1-i] = '1';
      b -= 2;
    }
  }
  assert(a == 0 && b == 0);
  cout << s << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
