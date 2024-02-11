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
  vector<string> S(n), T(n);
  map<string, int> cnt;
  rep(i, n) {
    cin >> S[i] >> T[i];
    cnt[S[i]]++;
    cnt[T[i]]++;
  }
  bool ok = true;
  rep(i, n) {
    if(S[i] == T[i]) {
      if(cnt[S[i]] > 2) ok = false;
    } else {
      if(cnt[S[i]] > 1 && cnt[T[i]] > 1) ok = false;
    }
  }
  cout << (ok ? "Yes" : "No") << endk;
  return 0;
}
