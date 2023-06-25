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
constexpr int MAX = 20000005;
auto spf = smallest_prime_factors(MAX);

template<typename T>
vector<T> factorization(T x, vector<T>& spf) {
  vector<T> ret;
  while(x != 1) {
    ret.push_back(spf[x]);
    x /= spf[x];
  }
  // sort(ret.begin(), ret.end());
  return ret;
}

void find_divisor(int N, vector<int>& divisor) {
  for(int i=1; i*i<=N; i++) {
    if(N % i == 0) {
      divisor.push_back(i);
    }
  }
  int n = divisor.size();
  for(int i=n-1; i>=0; i--) {
    if(N != divisor[i]*divisor[i]) {
      divisor.push_back(N / divisor[i]);
    }
  }
}

bool arr[20000005];
vector<int> cnt;
void Eratosthenes(int N) {
  cnt.assign(N+1, 0);
  for(int i=0; i<=N; i++) {
    arr[i] = true;
  }
  for(int i=2; i<=N; i++) {
    if(arr[i]) {
      for(int j=0; i*(j+2)<=N; j++) {
        arr[i*(j+2)] = false;
        cnt[i*(j+2)]++;
      }
    }
  }
  for(int i=2; i<=N; i++) {
    if(arr[i]) {
      cnt[i]++;
    }
  }
}

ll pw[20];
void solve() {
  int c, d, x; cin >> c >> d >> x;
  vector<int> div;
  find_divisor(x, div);
  int ans = 0;
  for(int g: div) {
    int abc = g + d;
    if(abc % c > 0) continue;
    int ab = abc / c;
    // auto ret = factorization(ab, spf);
    ans += pw[cnt[ab]];
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  pw[0] = 1;
  rep(i, 20) if(i) pw[i] = pw[i-1]*2;
  Eratosthenes(20000005);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
