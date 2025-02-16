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
  int n, k; cin >> n >> k;
  int M = 1000001;
  vector<int> cnt(M);
  vector<int> A(n);
  rep(i, n) {
    cin >> A[i];
    cnt[A[i]]++;
  }
  vector<int> cnt2(M);
  REP(i, 1, M) {
    for(int j=i; j<M; j+=i) {
      cnt2[i] += cnt[j];
    }
  }
  vector<int> ans(M);
  REP(i, 1, M) {
    if(cnt2[i] < k) continue;
    for(int j=i; j<M; j+=i) {
      chmax(ans[j], i);
    }
  }
  rep(i, n) {
    cout << ans[A[i]] << endk;
  }
  return 0;
}
