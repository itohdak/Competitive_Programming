#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w, m; cin >> h >> w >> m;
  vector<int> T(m), A(m), X(m);
  rep(i, m) {
    cin >> T[i] >> A[i] >> X[i];
    A[i]--;
  }
  map<int, ll> cnt;
  set<int> col, row;
  rrep(i, m) {
    if(T[i] == 1) {
      if(row.count(A[i])) continue;
      cnt[X[i]] += w-col.size();
      row.insert(A[i]);
    } else {
      if(col.count(A[i])) continue;
      cnt[X[i]] += h-row.size();
      col.insert(A[i]);
    }
  }
  set<int> del;
  ll zero = 1LL*h*w;
  for(auto [k, v]: cnt) {
    if(v == 0) del.insert(k);
    if(k != 0) zero -= v;
  }
  if(zero) cnt[0] = zero;
  for(int d: del) cnt.erase(d);
  cout << cnt.size() << endk;
  for(auto [k, v]: cnt) cout << k << ' ' << v << endk;
  return 0;
}
