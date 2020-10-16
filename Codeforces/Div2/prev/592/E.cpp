#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
template<class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template<class t> ostream& operator<<(ostream& os, const vector<t>& v) {
  os << "{";
  rep(i, v.size()) { if(i) os << ", "; os << v[i]; }
  return os << "}";
}
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

vector<ll> A;
int N;
vector<ll> sum;
bool test(ll t, ll k) {
  rep(i, N) {
    ll l = A[i];
    ll r = l + t;
    int lb = upper_bound(all(A), l-1) - A.begin();
    int ub = lower_bound(all(A), r+1) - A.begin();
    ll tmp = (l * lb - sum[lb]) + ((sum[N]-sum[ub]) - r * (N-ub));
    if(tmp <= k) return true;
    if(r > A[N-1]) break;
  }
  rrep(i, N) {
    ll r = A[i];
    ll l = r - t;
    int lb = upper_bound(all(A), l-1) - A.begin();
    int ub = lower_bound(all(A), r+1) - A.begin();
    ll tmp = (l * lb - sum[lb]) + ((sum[N]-sum[ub]) - r * (N-ub));
    if(tmp <= k) return true;
    if(l < A[0]) break;
  }
  return false;
}

ll binary_search(ll n, ll k) {
  ll ng = -1, ok = n;
  while(abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if(test(mid, k)) ok = mid;
    else ng = mid;
  }
  return ok;
}

int main() {
  ll K;
  cin >> N >> K;
  A = vector<ll>(N);
  sum = vector<ll>(N+1);
  rep(i, N) cin >> A[i];
  rep(i, N) sum[i+1] = sum[i] + A[i];
  sort(all(A));
  rep(i, N) sum[i+1] = sum[i] + A[i];
  cout << binary_search(A[N-1]-A[0], K) << endl;
  return 0;
}

