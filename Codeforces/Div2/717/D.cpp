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

template<typename T>
vector<T> smallest_prime_factors(T n) {
  vector<T> spf(n + 1);
  for(int i=0; i<=n; i++) spf[i] = i;
  for(T i=2; i*i<=n; i++) {
    // 素数だったら
    if(spf[i] == i) {
      for(T j=i*i; j<=n; j+=i) {
        // iを持つ整数かつまだ素数が決まっていないなら
        if(spf[j] == j) {
          spf[j] = i;
        }
      }
    }
  }
  return spf;
}

template<typename T>
vector<T> factorization(T x, vector<T>& spf) {
  vector<T> ret;
  while(x != 1) {
    ret.push_back(spf[x]);
    x /= spf[x];
  }
  sort(ret.begin(), ret.end());
  return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  vector<int> A(n); rep(i, n) cin >> A[i];
  int logn = log2(n)+1;
  vector<vector<int>> next(logn, vector<int>(n, n));
  map<int, int> last;
  constexpr int MAX = 100050;
  auto spf = smallest_prime_factors(MAX);
  rrep(i, n) {
    if(i != n-1) next[0][i] = next[0][i+1];
    auto primes = factorization(A[i], spf);
    for(int p: primes) {
      if(last.count(p)) {
        chmin(next[0][i], last[p]);
      }
    }
    for(int p: primes) {
      last[p] = i;
    }
  }
  rep(i, logn) {
    if(i) {
      rep(j, n) {
        if(next[i-1][j] == n) next[i][j] = n;
        else next[i][j] = next[i-1][next[i-1][j]];
      }
    }
  }
  // cout << next << endk;
  rep(i, q) {
    int l, r; cin >> l >> r;
    l--;
    int tmp = l;
    int ans = 0;
    rrep(j, logn) {
      while(next[j][tmp] < r) {
        tmp = next[j][tmp];
        ans += (1<<j);
      }
    }
    cout << ans+1 << endk;
  }
  return 0;
}
