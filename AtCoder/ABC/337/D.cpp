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
  int h, w, k; cin >> h >> w >> k;
  vector<string> S(h);
  rep(i, h) {
    cin >> S[i];
  }
  auto test = [&](vector<string>& T) -> int {
    int ret = inf;
    int h = T.size(), w = T[0].size();
    rep(i, h) {
      vector<int> cnt(w+1);
      vector<int> pos;
      rep(j, w) {
	cnt[j+1] = cnt[j] + (T[i][j] == 'o');
	if(T[i][j] == 'x') {
	  pos.push_back(j);
	}
      }
      pos.push_back(w);
      rep(j, w) {
	if(T[i][j] == 'x') continue;
	if(*lower_bound(all(pos), j) < j+k) continue;
	chmin(ret, k-(cnt[j+k]-cnt[j]));
      }
    }
    return ret;
  };
  int ans = inf;
  chmin(ans, test(S));
  vector<string> S2(w, string(h, ' '));
  rep(i, h) rep(j, w) S2[j][i] = S[i][j];
  chmin(ans, test(S2));
  cout << (ans == inf ? -1 : ans) << endk;
  return 0;
}
