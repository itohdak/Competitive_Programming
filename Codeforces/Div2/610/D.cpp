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
  auto query = [&](string s) {
    cout << s << endl;
    int res; cin >> res;
    if(res == 0) exit(0);
    else return res;
  };
  int res;
  int na, nb, n;
  res = query(string(300, 'a'));
  na = 300-res;
  res = query(string(300, 'b'));
  nb = 300-res;
  n = na+nb;
  string ans(n, 'a');
  int prev = nb;
  int cntA = 0, cntB = 0;
  rep(i, n-1) {
    ans[i] = 'b';
    res = query(ans);
    if(res != prev-1) {
      ans[i] = 'a';
      cntA++;
    } else {
      prev = res;
      cntB++;
    }
  }
  if(cntA == na) {
    ans[n-1] = 'b';
    cntB++;
  } else {
    cntA++;
  }
  assert(cntA == na && cntB == nb);
  res = query(ans);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
