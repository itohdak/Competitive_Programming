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
  int n, m; cin >> n >> m;
  set<pair<int, int>> st1, st2;
  rep(i, m) {
    int a, b; cin >> a >> b;
    a--; b--;
    st1.insert({min(a, b), max(a, b)});
  }
  rep(i, m) {
    int a, b; cin >> a >> b;
    a--; b--;
    st2.insert({min(a, b), max(a, b)});
  }
  vector<int> id(n);
  iota(all(id), 0);
  do {
    bool ok = true;
    rep(i, n) REP(j, i+1, n) {
      if(st1.count({i, j}) ^ st2.count({min(id[i], id[j]), max(id[i], id[j])})) ok = false;
    }
    if(ok) {
      cout << "Yes" << endk;
      return 0;
    }
  } while(next_permutation(all(id)));
  cout << "No" << endk;
  return 0;
}