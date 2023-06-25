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
  string a, b; cin >> a >> b;
  bool swaped = (a.size() > b.size());
  if(swaped) swap(a, b);
  string a_ans, b_ans;
  int sum = inf;
  multiset<int> a_st, b_st;
  for(char c: a) a_st.insert(c-'0');
  for(char c: b) b_st.insert(c-'0');
  rep(i, 10) {
    if(i == 0 || !a_st.count(i)) continue;
    multiset<int> st1 = a_st, st2 = b_st;
    string a_tmp, b_tmp;
    bool carry = false;
    auto select_b = [&]() {
      auto itr = st2.lower_bound(10-carry-(a_tmp.back()-'0'));
      if(itr == st2.end()) {
        carry = false;
        b_tmp += char('0'+*st2.begin());
        st2.erase(st2.begin());
      } else {
        carry = true;
        b_tmp += char('0'+*itr);
        st2.erase(itr);
      }
    };
    st1.erase(st1.find(i));
    a_tmp += char('0'+i);
    select_b();
    while(st1.size()) {
      a_tmp += char('0'+*(--st1.end()));
      st1.erase(--st1.end());
      select_b();
    }
    while(st2.size()) {
      b_tmp += char('0'+*(--st2.end()));
      st2.erase(--st2.end());
    }
    auto calc_sum = [&]() {
      int ret = 0;
      int carry = 0;
      rep(i, a_tmp.size()) {
        int tmp = (a_tmp[i] + b_tmp[i] - '0' - '0') + carry;
        ret += tmp % 10;
        carry = tmp / 10;
      }
      REP(i, a_tmp.size(), b_tmp.size()) {
        int tmp = (b_tmp[i] - '0') + carry;
        ret += tmp % 10;
        carry = tmp / 10;
      }
      return ret + carry;
    };
    int sum_tmp = calc_sum();
    reverse(all(a_tmp));
    reverse(all(b_tmp));
    if(sum > sum_tmp) {
      sum = sum_tmp;
      a_ans = a_tmp;
      b_ans = b_tmp;
    }
  }
  if(swaped) swap(a_ans, b_ans);
  cout << a_ans << endk;
  cout << b_ans << endk;
  // cout << sum << endk;
  return 0;
}
