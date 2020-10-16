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
  cin >> N;
  int K = (N+1)/2;
  vector<ll> A(K);
  rep(i, K) cin >> A[i];
  ll X;
  cin >> X;
  vector<ll> P(N-K+1);
  rep(i, N-K+1) {
    if(i == 0) P[i] = accumulate(all(A), 0LL);
    else P[i] = X-A[i-1];
  }
  ll ans = -1;
  return 0;
}
