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
  ll a, b; cin >> a >> b;
  ll i = 1;
  ll sum1 = 0;
  set<ll> st1;
  while(sum1 < a) {
    st1.insert(i);
    sum1 += i;
    i++;
  }
  set<ll> st2;
  ll sum2 = 0;
  if(sum1 > a) {
    st1.erase(sum1-a);
    st2.insert(sum1-a);
    sum2 += sum1-a;
  }
  while(sum2 < b) {
    st2.insert(i);
    sum2 += i;
    i++;
  }
  if(sum2 > b) {
    if(st2.count(sum2-b)) st2.erase(sum2-b);
    else st2.erase(*st2.rbegin());
  }
  cout << st1.size() << endk;
  for(ll i: st1) cout << i << ' ';
  cout << endk;
  cout << st2.size() << endk;
  for(ll i: st2) cout << i << ' ';
  cout << endk;
  return 0;
}
