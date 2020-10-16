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
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  ll X;
  cin >> N >> X;
  vector<ll> D(N), A(N);
  rep(i, N) {
    cin >> D[i];
    A[i] = D[i] * (D[i]+1) / 2;
  }
  vector<ll> sumD(2*N+1), sumA(2*N+1);
  rep(i, 2*N) {
    sumD[i+1] = sumD[i] + D[i%N];
    sumA[i+1] = sumA[i] + A[i%N];
  }
  // cout << sumD << endl;
  ll ans = 0;
  rep(i, N) {
    auto j = upper_bound(all(sumD), sumD[i]+X) - sumD.begin();
    ll rem = X - (sumD[j-1]-sumD[i]);
    ll tmp = (sumA[j-1]-sumA[i]) + rem*(rem+1)/2;
    // cout << i << ' ' << j << ' ' << rem << ' ' << tmp << endl;
    ans = max(tmp, ans);
  }
  rep(i, N) {
    auto j = lower_bound(all(sumD), sumD[N+i+1]-X) - sumD.begin();
    ll rem = X - (sumD[N+i+1]-sumD[j]);
    ll tmp = (sumA[N+i+1]-sumA[j]) + (2*D[(j-1)%N]-rem+1)*rem/2;
    // cout << i << ' ' << j << ' ' << rem << ' ' << tmp << endl;
    ans = max(tmp, ans);
  }
  cout << ans << endl;
  return 0;
}
