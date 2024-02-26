#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

int op(int a, int b) {
  return min(a, b);
}

int e() {
  return inf;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> P(n);
  rep(i, n) {
    cin >> P[i];
    P[i]--;
  }
  vector<int> id(n);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    return P[i] < P[j];
  });
  vector<int> ans(n, inf);
  {
    segtree<int, op, e> segl(n), segr(n);
    for(int i: id) {
      chmin(ans[i], min((P[i]+i)+segl.prod(0, i), (P[i]-i)+segr.prod(i+1, n)));
      segl.set(i, -P[i]-i);
      segr.set(i, -P[i]+i);
    }
  }
  reverse(all(id));
  {
    segtree<int, op, e> segl(n), segr(n);
    for(int i: id) {
      chmin(ans[i], min((-P[i]+i)+segl.prod(0, i), (-P[i]-i)+segr.prod(i+1, n)));
      segl.set(i, +P[i]-i);
      segr.set(i, +P[i]+i);
    }
  }
  rep(i, n) cout << ans[i] << ' ';
  cout << endk;
  return 0;
}
