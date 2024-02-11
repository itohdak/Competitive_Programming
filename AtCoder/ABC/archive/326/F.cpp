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

map<ll, string> calc_sub(vector<ll> A) {
  ll n = A.size();
  map<ll, string> mp;
  rep(i, 1<<n) {
    ll tmp = 0;
    string str;
    rep(j, n) {
      if((i>>j)&1) {
	tmp += A[j];
	str += '+';
      } else {
	tmp -= A[j];
	str += '-';
      }
    }
    mp[tmp] = str;
  }
  return mp;
};
string calc(vector<ll> A, ll x) {
  ll n = A.size();
  vector<ll> A1, A2;
  rep(i, n) (i < n/2 ? A1 : A2).push_back(A[i]);
  map<ll, string> mp1 = calc_sub(A1), mp2 = calc_sub(A2);
  for(auto& [k, v]: mp1) {
    if(mp2.empty()) {
      if(x-k == 0) {
	return v;
      }
    } else {
      if(mp2.count(x-k)) {
	return v + mp2[x-k];
      }
    }
  }
  return "-1";
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, x, y; cin >> n >> x >> y;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> V, H;
  rep(i, n) {
    (i&1 ? H : V).push_back(A[i]);
  }
  auto dx = calc(H, x);
  auto dy = calc(V, y);
  if(dx == "-1" || dy == "-1") {
    cout << "No" << endk;
  } else {
    string ans;
    char prev = '+';
    rep(i, n) {
      char next = (i&1 ? dx : dy)[i/2];
      ans += ((prev == '+') ^ (next == '+') ^ (i&1) ? 'R' : 'L');
      prev = next;
    }
    cout << "Yes" << endk;
    cout << ans << endk;
  }
  return 0;
}
