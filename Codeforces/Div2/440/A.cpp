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
  set<int> A, B;
  rep(i, n) {
    int a; cin >> a;
    A.insert(a);
  }
  rep(i, m) {
    int a; cin >> a;
    B.insert(a);
  }
  REP(i, 1, 10) {
    if(A.count(i) && B.count(i)) {
      cout << i << endk;
      return 0;
    }
  }
  if(*A.begin() < *B.begin()) {
    cout << *A.begin() * 10 + *B.begin() << endk;
  } else {
    cout << *B.begin() * 10 + *A.begin() << endk;
  }
  return 0;
}
