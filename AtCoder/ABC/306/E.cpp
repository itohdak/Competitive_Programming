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
  int n, k, q; cin >> n >> k >> q;
  multiset<int> st1, st2;
  rep(i, n) {
    if(i < k) st1.insert(0);
    else st2.insert(0);
  }
  ll ans = 0;
  vector<int> A(n);
  rep(i, q) {
    int x, y; cin >> x >> y;
    x--;
    int a = A[x];
    A[x] = y;
    if(st1.count(a)) {
      st1.erase(st1.find(a));
      st1.insert(y);
      ans += y-a;
    } else {
      st2.erase(st2.find(a));
      st2.insert(y);
    }
    if(k < n) {
      while(*st1.begin() < *(--st2.end())) {
        int tmp1 = *st1.begin();
        st1.erase(st1.begin());
        int tmp2 = *(--st2.end());
        st2.erase(--st2.end());
        st1.insert(tmp2);
        st2.insert(tmp1);
        ans += tmp2-tmp1;
      }
    }
    cout << ans << endk;
  }
  return 0;
}
