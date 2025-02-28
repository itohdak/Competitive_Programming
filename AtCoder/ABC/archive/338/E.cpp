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
  vector<int> A(n), B(n);
  rep(i, n) {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
  }
  vector<tuple<int, int, int>> Q;
  rep(i, n) {
    int a = min(A[i], B[i]);
    int b = max(A[i], B[i]);
    Q.push_back({a, +1, i});
    Q.push_back({b, -1, i});
  }
  sort(all(Q));
  int cur = 0;
  bool ok = true;
  vector<int> cnt(n);
  for(auto [p, t, i]: Q) {
    if(t == -1) {
      cur--;
      if(cur != cnt[i]) {
	ok = false;
      }
    } else {
      cnt[i] = cur;
      cur++;
    }
  }
  cout << (ok ? "No" : "Yes") << endk;
  return 0;
}
