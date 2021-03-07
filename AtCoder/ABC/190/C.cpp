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
  vector<int> A(m), B(m);
  rep(i, m) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
  }
  int k; cin >> k;
  vector<int> C(k), D(k);
  rep(i, k) {
    cin >> C[i] >> D[i];
    C[i]--; D[i]--;
  }
  int ans = 0;
  rep(i, 1<<k) {
    vector<int> cnt(n);
    rep(j, k) {
      if((i>>j)&1) cnt[C[j]]++;
      else cnt[D[j]]++;
    }
    int tmp = 0;
    rep(j, m) {
      if(cnt[A[j]] && cnt[B[j]]) tmp++;
    }
    chmax(ans, tmp);
  }
  cout << ans << endk;
  return 0;
}
