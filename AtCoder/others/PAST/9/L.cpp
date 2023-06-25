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

template<typename T>
vector<int> longest_increasing_subsequence(const vector<T>& a, bool strict=true) {
  vector<int> ret(a.size());
  vector<T> lis;
  rep(i, a.size()) {
    auto it = (strict ? lower_bound(all(lis), a[i]) : upper_bound(all(lis), a[i]));
    if(it == lis.end()) {
      lis.emplace_back(a[i]);
      ret[i] = lis.size();
    } else {
      *it = a[i];
      ret[i] = it - lis.begin() + 1;
    }
  }
  return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, p; cin >> n >> p;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> B;
  rep(i, n) {
    if(i <= A[n-1-i] && A[n-1-i] <= p-(n-1-i)) {
      B.push_back(A[n-1-i]-i);
    }
  }
  // reverse(all(A));
  // rep(i, n) A[i] -= i;
  auto ret = longest_increasing_subsequence(B, false);
  if(ret.size()) {
    cout << n - *max_element(all(ret)) << endk;
  } else {
    cout << n << endk;
  }
  return 0;
}
