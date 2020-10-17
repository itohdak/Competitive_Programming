#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

ll solve(ifstream& fin) {
  ll n, k; fin >> n >> k;
  vector<ll> L(n); rep(i, k) fin >> L[i];
  ll lparam[4]; rep(i, 4) fin >> lparam[i];
  vector<ll> W(n); rep(i, k) fin >> W[i];
  ll wparam[4]; rep(i, 4) fin >> wparam[i];
  vector<ll> H(n); rep(i, k) fin >> H[i];
  ll hparam[4]; rep(i, 4) fin >> hparam[i];
  REP(i, k, n) {
    ll a, b, c, d;
    a = lparam[0], b = lparam[1], c = lparam[2], d = lparam[3];
    L[i] = (a*L[i-2]%d+b*L[i-1]%d+c)%d+1;
    a = wparam[0], b = wparam[1], c = wparam[2], d = wparam[3];
    W[i] = (a*W[i-2]%d+b*W[i-1]%d+c)%d+1;
    a = hparam[0], b = hparam[1], c = hparam[2], d = hparam[3];
    H[i] = (a*H[i-2]%d+b*H[i-1]%d+c)%d+1;
  }
  ll ans = 1;
  ll p = 0;
  set<pair<pair<ll, int>, ll>> st;
  vector<ll> P(n);
  rep(i, n) {
    // cerr << st << endk;
    ll l = L[i], r = L[i]+W[i];
    auto itrl = st.lower_bound({{l, -1}, 0});
    auto itrr = st.upper_bound({{r, 1}, longinf});
    if(itrl == st.end() || itrr == st.begin()) {
      st.insert({{l, -1}, H[i]}); // out
      st.insert({{r, 1}, H[i]}); // in
      (p += (H[i]+r-l)*2) %= mod;
    } else if(itrl == itrr) {
      if(itrl == st.begin() || itrr == st.end()) {
        st.insert({{l, -1}, H[i]}); // out
        st.insert({{r, 1}, H[i]}); // in
        (p += (H[i]+r-l)*2) %= mod;
      } else {
        --itrl;
        if(itrl->first.second == -1) {
        } else {
          ++itrl;
          st.insert({{l, -1}, H[i]}); // out
          st.insert({{r, 1}, H[i]}); // in
          (p += (H[i]+r-l)*2) %= mod;
        }
      }
    } else {
      ll ml, mr;
      if(itrl->first.second == -1) { // out
        ml = l;
      } else { // in
        assert(itrl != st.begin());
        --itrl;
        ml = itrl->first.first;
      }
      --itrr;
      if(itrr->first.second == 1) { // in
        mr = r;
      } else { // out
        ++itrr;
        assert(itrr != st.end());
        mr = itrr->first.first;
      }
      ++itrr;
      ll mh = 0;
      ll tmpl, tmpr, tmph=H[i];
      for(auto itr=itrl; itr!=itrr; itr++) {
        chmax(mh, itr->second);
        if(itr->first.second == -1) {
          tmpl = itr->first.first;
          (p += 2*(min(tmph, itr->second)-H[i])) %= mod;
        } else {
          tmpr = itr->first.first;
          ll w = tmpr-tmpl;
          ll h = itr->second;
          tmph = h;
          // cerr << w << ' ' << h << endk;
          (p += mod - 2*(w+h)%mod) %= mod;
        }
      }
      st.erase(itrl, itrr);
      (p += 2*(mr-ml+mh)%mod) %= mod;
      st.insert({{ml, -1}, mh}); // out
      st.insert({{mr, 1}, mh}); // in
    }
    (ans *= p) %= mod;
    P[i] = p;
    // cerr << ans << endk;
  }
  // cerr << st << endk;
  // cerr << P << endk;
  return ans;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream fin("/home/itohdak/facebook/2020/R1/input/perimetric_chapter_2_validation_input.txt");
  ofstream fout("/home/itohdak/facebook/2020/R1/output/perimetric_chapter_2_validation_output.txt");
  int t; fin >> t;
  rep(i, t) {
    fout << "Case #" << i+1 << ": " << solve(fin) << endk;
  }
  return 0;
}
