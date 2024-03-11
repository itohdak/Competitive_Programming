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
  int n, q; cin >> n >> q;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> L(q), R(q);
  rep(i, q) {
    cin >> L[i] >> R[i];
    L[i]--;
  }
  vector<int> id(q);
  iota(all(id), 0);
  int b = 400;
  sort(all(id), [&](int i, int j) {
    if(L[i]/b == L[j]/b) return R[i] < R[j];
    else return L[i]/b < L[j]/b;
  });
  vector<ll> cnt(200001);
  vector<ll> ans(q);
  int l = 0, r = 0;
  ll sum = 0;
  for(int i: id) {
    while(L[i] < l) {
      l--;
      sum += cnt[A[l]] * (cnt[A[l]]-1) / 2;
      cnt[A[l]]++;
    }
    while(r < R[i]) {
      sum += cnt[A[r]] * (cnt[A[r]]-1) / 2;
      cnt[A[r]]++;
      r++;
    }
    while(l < L[i]) {
      cnt[A[l]]--;
      sum -= cnt[A[l]] * (cnt[A[l]]-1) / 2;
      l++;
    }
    while(R[i] < r) {
      r--;
      cnt[A[r]]--;
      sum -= cnt[A[r]] * (cnt[A[r]]-1) / 2;
    }
    ans[i] = sum;
  }
  rep(i, q) {
    cout << ans[i] << endk;
  }
  return 0;
}
