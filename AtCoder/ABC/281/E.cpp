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
  int n, m, k; cin >> n >> m >> k;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  multiset<ll> st1, st2;
  ll cum = 0;
  vector<ll> ans (n-m+1);
  auto add = [&](int i, ll x) {
    if(i == 1) {
      cum += x;
      st1.insert(x);
    } else {
      st2.insert(x);
    }
  };
  auto del = [&](int i, ll x) {
    if(i == 1) {
      assert(st1.count(x));
      cum -= x;
      st1.erase(st1.find(x));
    } else {
      assert(st2.count(x));
      st2.erase(st2.find(x));
    }
  };
  add(1, 0);
  add(2, inf);
  rep(i, m) add(1, A[i]);
  while(st1.size() > k+1) {
    ll x = *(--st1.end());
    del(1, x);
    add(2, x);
  }
  rep(i, n-m+1) {
    ans[i] = cum;
    // cout << st1 << ' ' << st2 << endk;
    if(i < n-m) {
      if(st2.count(A[i])) {
        del(2, A[i]);
      } else {
        del(1, A[i]);
        ll x = *st2.begin();
        del(2, x);
        add(1, x);
      }
      if(A[i+m] < *(--st1.end())) {
        ll x = *(--st1.end());
        del(1, x);
        add(1, A[i+m]);
        add(2, x);
      } else {
        add(2, A[i+m]);
      }
    }
  }
  rep(i, n-m+1) cout << ans[i] << ' ';
  cout << endk;
  return 0;
}
