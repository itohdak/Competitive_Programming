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
  vector<int> A(m); rep(i, m) cin >> A[i];
  vector<string> S(n); rep(i, n) cin >> S[i];
  vector<int> score(n);
  rep(i, n) {
    rep(j, m) {
      if(S[i][j] == 'o') score[i] += A[j];
    }
    score[i] += i+1;
  }
  int mx = *max_element(all(score));
  rep(i, n) {
    vector<int> tmp;
    rep(j, m) {
      if(S[i][j] == 'x') tmp.push_back(A[j]);
    }
    sort(all(tmp), greater<int>());
    vector<int> cum(tmp.size()+1);
    rep(j, tmp.size()) {
      cum[j+1] = cum[j] + tmp[j];
    }
    int need = mx - score[i];
    int ans = lower_bound(all(cum), need) - begin(cum);
    cout << ans << endk;
  }
  return 0;
}
