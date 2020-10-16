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
  int odd1=0, even1=0, odd2=0, even2=0;
  rep(i, n) {
    if(i%2==0) {
      if(int(s[i]-'0')%2) odd1++;
      else even1++;
    } else {
      if(int(s[i]-'0')%2) odd2++;
      else even2++;
    }
  }
  // cout << odd1 << even1 << odd2 << even2 << endk;
  if(n%2) {
    cout << (odd1 ? 1 : 2) << endk;
  } else {
    cout << (even2 ? 2 : 1) << endk;
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
