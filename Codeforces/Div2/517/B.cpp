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
  int n; cin >> n;
  vector<int> A(n-1); rep(i, n-1) cin >> A[i];
  vector<int> B(n-1); rep(i, n-1) cin >> B[i];
  map<tuple<int, int, int>, int> mp;
  rep(t1, 4) rep(t2, 4) {
    mp[{t1, t1|t2, t1&t2}] = t2;
  }
  rep(i, 4) {
    vector<int> tmp(n);
    tmp[0] = i;
    bool ok = true;
    rep(j, n-1) {
      if(!mp.count({tmp[j], A[j], B[j]})) {
        ok = false;
        break;
      }
      tmp[j+1] = mp[{tmp[j], A[j], B[j]}];
    }
    if(ok) {
      cout << "YES" << endk;
      rep(i, n) cout << tmp[i] << ' ';
      cout << endk;
      return 0;
    }
  }
  cout << "NO" << endk;
  return 0;
}
