#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N, A, R, M;
  cin >> N >> A >> R >> M;
  vector<ll> H(N);
  rep(i, N) cin >> H[i];
  sort(all(H));
  ll sum = accumulate(all(H), 0LL);
  ll ans = longinf;
  vector<ll> cnt(N+1);
  rep(i, N) cnt[i+1] = cnt[i] + H[i];
  {
    ll h = sum/N;
    int i = lower_bound(all(H), h) - begin(H);
    i--;
    ll lower = (i+1)*h-cnt[i+1];
    ll higher = (cnt[N]-cnt[i+1])-(N-i-1)*h;
    ll tmp = 0;
    if(lower < higher) {
      tmp += (higher-lower)*R;
      tmp += lower*min(M, A+R);
    } else {
      tmp += (lower-higher)*A;
      tmp += higher*min(M, A+R);
    }
    ans = min(tmp, ans);
  }
  {
    ll h = sum/N+1;
    int i = lower_bound(all(H), h) - begin(H);
    i--;
    ll lower = (i+1)*h-cnt[i+1];
    ll higher = (cnt[N]-cnt[i+1])-(N-i-1)*h;
    ll tmp = 0;
    if(lower < higher) {
      tmp += (higher-lower)*R;
      tmp += lower*min(M, A+R);
    } else {
      tmp += (lower-higher)*A;
      tmp += higher*min(M, A+R);
    }
    ans = min(tmp, ans);
  }
  rep(i, N) {
    ll lower = (i+1)*H[i]-cnt[i+1];
    ll higher = (cnt[N]-cnt[i+1])-(N-i-1)*H[i];
    ll tmp = 0;
    if(lower < higher) {
      tmp += (higher-lower)*R;
      tmp += lower*min(M, A+R);
    } else {
      tmp += (lower-higher)*A;
      tmp += higher*min(M, A+R);
    }
    ans = min(tmp, ans);
  }
  cout << ans << endl;
  return 0;
}
