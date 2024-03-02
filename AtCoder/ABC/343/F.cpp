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

struct S {
  int val[2], cnt[2];
};
S op(S a, S b) {
  map<int, int> mp;
  rep(i, 2) {
    mp[a.val[i]] += a.cnt[i];
    mp[b.val[i]] += b.cnt[i];
  }
  S ret;
  if(mp.size() == 1) {
    ret.val[0] = mp.begin()->first;
    ret.cnt[0] = mp.begin()->second;
  } else {
    auto itr = mp.end();
    --itr;
    ret.val[0] = itr->first;
    ret.cnt[0] = itr->second;
    --itr;
    ret.val[1] = itr->first;
    ret.cnt[1] = itr->second;
  }
  return ret;
};
S e() {
  return S{{0, 0}, {0, 0}};
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  vector<int> A(n); rep(i, n) cin >> A[i];
  segtree<S, op, e> seg(n);
  rep(i, n) seg.set(i, S{{A[i], 0}, {1, 0}});
  rep(i, q) {
    int t; cin >> t;
    if(t == 1) {
      int p, x; cin >> p >> x;
      p--;
      seg.set(p, S{{x, 0}, {1, 0}});
    } else {
      int l, r; cin >> l >> r;
      l--;
      cout << seg.prod(l, r).cnt[1] << endk;
    }
  }
  return 0;
}
