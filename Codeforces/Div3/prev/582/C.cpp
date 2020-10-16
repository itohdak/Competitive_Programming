#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

class DoublingVal {
public:
  int N;
  int logK;
  vector<vector<pair<int, ll>>> next;

  DoublingVal(int N, vector<int>& ini, vector<ll>& A, ll K) {
    logK = log2(K);
    next = vector<vector<pair<int, ll>>>(logK+1, vector<pair<int, ll>>(N));
    rep(i, N) {
      next[0][i].first = ini[i];
      next[0][i].second = A[i];
    }
    rep(k, logK) {
      rep(i, N) {
        next[k+1][i].first = next[k][next[k][i].first].first;
        next[k+1][i].second = next[k][i].second + next[k][next[k][i].first].second;
      }
    }
  }

  pair<int, ll> query(int p, ll q) {
    ll sum = 0;
    for(int k=logK; k>=0; k--) {
      if(p == -1) break;
      if((q>>k)&1) {
        sum += next[k][p].second;
        p = next[k][p].first;
      }
    }
    return make_pair(p, sum);
  }
};
void solve() {
  ll n, m; cin >> n >> m;
  vector<int> ini(10);
  vector<ll> A(10);
  rep(i, 10) {
    ini[i] = (i+m)%10;
    A[i] = i;
  }
  DoublingVal dbl(10, ini, A, longinf);
  cout << dbl.query(0, n/m+1).second << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
