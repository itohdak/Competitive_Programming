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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int q; cin >> q;
  fenwick_tree<ll> bit(q);
  int next = 0;
  int front = 0;
  rep(i, q) {
    int t; cin >> t;
    if(t == 1) {
      int l; cin >> l;
      bit.add(next++, l);
    } else if (t == 2) {
      front++;
    } else {
      int k; cin >> k;
      k--;
      cout << bit.sum(front, front+k) << endk;
    }
  }
  return 0;
}
