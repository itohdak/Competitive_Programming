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

template<int char_size, int base>
struct Trie {
  struct Node {
    vector<int> next;
    vector<int> accept;
    int c;
    int common;
    Node(int c_) : c(c_), common(0) {
      next.assign(char_size, -1);
    }
  };
  vector<Node> nodes;
  int root;
  Trie() : root(0) {
    nodes.push_back(Node(root));
  }

  void insert(const string& word, int word_id) {
    int node_id = 0;
    for(int i=0; i<(int)word.size(); i++) {
      int c = (int)(word[i] - base);
      int& next_id = nodes[node_id].next[c];
      if(next_id == -1) {
        next_id = (int)nodes.size();
        nodes.push_back(Node(c));
      }
      ++nodes[node_id].common;
      node_id = next_id;
    }
    ++nodes[node_id].common;
    nodes[node_id].accept.push_back(word_id);
  }
  void insert(const string& word) {
    insert(word, nodes[0].common);
  }

  bool search(const string& word, bool prefix=false) {
    int node_id = 0;
    for(int i=0; i<(int)word.size(); i++) {
      int c = (int)(word[i] - base);
      int& next_id = nodes[node_id].next[c];
      if(next_id == -1) return false;
      node_id = next_id;
    }
    return (prefix ? true : nodes[node_id].accept.size() > 0);
  }
  bool start_with(const string& word) {
    return search(word, true);
  }

  int count() const {
    return (nodes[0].common);
  }
  int size () const {
    return ((int)nodes.size());
  }
};
#define mint modint<1000000007>
template <std::uint_fast64_t Modulus> class modint {
  using u64 = std::uint_fast64_t;

public:
  u64 a;

  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
  friend ostream& operator<<(ostream& os, const modint& m) {
    return os << m.value();
  }
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  rep(i, n) s[i] = (s[i]=='H' ? 'A' : 'B');
  Trie<2, 'A'> trie;
  string tmp;
  vector<int> to(n, 0);
  rep(i, n) {
    string ng = string(1, (s[i]=='A' ? 'B' : 'A')) + tmp;
    int sz = ng.size();
    rep(j, sz) {
      if(trie.search(ng)) {
        to[i] = ng.size();
        break;
      }
      ng.pop_back();
    }
    tmp = string(1, s[i]) + tmp;
    trie.insert(tmp);
  }
  vector<mint> coef(n+1);
  rrep(i, n) {
    rep(j, n+1) coef[j] /= 2;
    coef[n] += 1;
    coef[to[i]] += (mint)1/2;
    if(coef[i].value()) {
      mint val = (mint)1-coef[i];
      rep(j, n+1) coef[j] /= val;
      coef[i] = 0;
    }
  }
  cout << coef[n] << endk;
  return 0;
}
