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


bool contains_three(string s) {
  for (char c: s) {
    if (c == '3') return true;
  }
  return false;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  std::string input;
  std::vector<std::pair<int, int>> result;

  bool end = false;
  while (!end && std::getline(std::cin, input)) {
    if (input.empty()) continue;

    // 文字列が"{1,10"のように始まるので、左中括弧を削除
    if (input[input.size()-1] == ',') {
      input.erase(0, 1);
      input.erase(input.size() - 2 , 2);
    } else {
      input.erase(0, 1);
      input.erase(input.size() - 1 , 1);
      end = true;
    }

    // カンマで分割して2つの整数を取得
    std::stringstream ss(input);
    std::string numStr;
    int first, second;

    // 最初の数字を取得
    std::getline(ss, numStr, ',');
    first = std::stoi(numStr);

    // 2番目の数字を取得
    std::getline(ss, numStr, ',');
    second = std::stoi(numStr);

    // 結果にペアとして格納
    result.push_back(std::make_pair(first, second));
  }

  bool first = true;
  for (const auto& p: result) {
    int ans = 0;
    int cnt = 0;
    REP(i, p.first, p.second+1) {
      string s = to_string(i);
      if (contains_three(s) || i % 3 == 0) {
        if (cnt % 3 != 2) {
          ans += i;
        }
        cnt++;
      }
    }
    if (first) {
      cout << ans;
      first = false;
    } else {
      cout << ',' << ans;
    }
  }
  cout << endk;

  return 0;
}
