#include <bits/stdc++.h>
// #include "/home/itohdak/AtCoder/000/print.hpp"
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
  int N;
  cin >> N;
  vector<ll> A(N);
  int Nmin = 0;
  ll summin = 0;
  rep(i, N) {
    cin >> A[i];
    if(A[i]<0) {
      Nmin++;
      summin += A[i];
    }
  }
  sort(all(A));
  if(Nmin == N) summin -= A[--Nmin];
  else if(Nmin == 0) summin += A[Nmin++];
  cout << accumulate(all(A), 0LL) - 2*summin << endl;
  rep(i, N-Nmin-1) {
    cout << A[0] << ' ' << A[N-2-i] << endl;
    A[0] -= A[N-2-i];
  }
  rep(i, Nmin) {
    cout << A[N-1] << ' ' << A[i] << endl;
    A[N-1] -= A[i];
  }
  return 0;
}
