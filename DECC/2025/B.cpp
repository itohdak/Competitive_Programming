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

string solve(string s) {
  deque<char> q1;
  deque<char> q2;
  for (char c: s) {
    if ('a' <= c && c <= 'z') {
      if (q2.size() == 2 && q2.back() == c && q2.front() == c) {
        q2.pop_back();
        if (q1.size()) {
          q2.push_front(q1.back());
          q1.pop_back();
        }
        q2.pop_back();
        if (q1.size()) {
          q2.push_front(q1.back());
          q1.pop_back();
        }
      } else {
        if (q2.size() == 2) {
          q1.push_back(q2.front());
          q2.pop_front();
        }
        q2.push_back(c);
      }
    } else {
      if (q2.size() >= 1 && q2.back() == c) {
        q2.pop_back();
        if (q1.size()) {
          q2.push_front(q1.back());
          q1.pop_back();
        }
      } else {
        if (q2.size() == 2) {
          q1.push_back(q2.front());
          q2.pop_front();
        }
        q2.push_back(c);
      }
    }
  }
  while (q2.size()) {
    q1.push_back(q2.front());
    q2.pop_front();
  }
  string ans;
  while (q1.size()) {
    ans += q1.front();
    q1.pop_front();
  }
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  std::string input;
  std::vector<string> result;

  bool end = false;
  while (!end && std::getline(std::cin, input)) {
    if (input.empty()) continue;

    if (input[input.size()-1] == ',') {
      input.erase(0, 1);
      input.erase(input.size() - 2 , 2);
    } else {
      input.erase(0, 1);
      input.erase(input.size() - 1 , 1);
      end = true;
    }

    result.push_back(input);
  }

  bool first = true;
  for (const string s: result) {
    string ans = s;
    rep(i, s.size()) {
      string t = s.substr(i) + s.substr(0, i);
      string tmp = solve(t);
      if(tmp.size() < ans.size()) ans = tmp;
    }
    if (!first) {
      cout << ",";
    }
    cout << "\"" << ans << "\"";
    first = false;
  }
  cout << endk;

  return 0;
}
