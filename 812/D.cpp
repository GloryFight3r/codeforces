/*
 * がんばって
*/

#include <bits/stdc++.h>

using namespace std;

//basic types
using ll = long long;
using ld = long double;
using db = double;
using str = string;

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

#define tcT template<class T
#define tcTU tcT, class U

tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;

// pairs
#define mp make_pair
#define f first
#define s second

// for vectors
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i++)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const int mxN = 2e5+5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int tSZ = (1 << 21);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for grid problems
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

// useful functions
constexpr int pcnt(int x) { return __builtin_popcount(x); } // number of bits
constexpr int bits(int x) { return 31-__builtin_clz(x); } // log2(x) rounded down
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

// functions for working with MOD
ll add(ll f, ll s){ f += s; if(f >= MOD) f %= MOD; if(f < 0) f += MOD;	return f; } // add f to s and make sure it's in range
ll mul(ll f, ll s){ f *= s; if(f >= MOD) f %= MOD; return f;} // multiply f and s and make sure it's in range
ll pw(ll x, ll y) { ll ans = 1, ml = x; while(y) { if(y & 1) ans = mul(ans, ml); ml = mul(ml, ml);	y >>= 1; } return ans; } // number x to a power y
ll inv(ll x) { return pw(x, MOD - 2); } //inversion of a number

tcT> void remDup(vector<T>& x) { // sort and remove duplicates
	sort(all(x)); x.erase(unique(all(x)),end(x)); }
tcTU> void erase(T& x, const U& v) {
	auto it = x.find(v); assert(it != end(x));
	x.erase(v); }

// Input
#define tcTUU tcT, class ...U
tcT> void re(complex<T>& c);
tcTU> void re(pair<T,U>& p);
tcT> void re(vector<T>& v);
tcT, size_t SZ> void re(array<T,SZ>& a);

tcT> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }
 
tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
tcT> void re(vector<T>& x) { trav(a,x) re(a); }
tcT, size_t SZ> void re(array<T,SZ>& x) { trav(a,x) re(a); }
tcT> void rv(int& n, vector<T>& x) { re(n); x.rsz(n); trav(a,x) re(a); }

// To_String
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	#ifdef LOCAL
		return b ? "true" : "false"; 
	#else 
		return ts((int)b);
	#endif
}
tcT> str ts(complex<T> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) {
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
tcTU> str ts(pair<T,U> p);
tcT> str ts(T v) { // containers with begin(), end()
	#ifdef LOCAL
		bool fst = 1; str res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	#else
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;
 
	#endif
}
tcTU> str ts(pair<T,U> p) {
	#ifdef LOCAL
		return"("+ts(p.f)+", "+ts(p.s)+")"; 
	#else
		return ts(p.f)+" "+ts(p.s);
	#endif
}
 
// Output
tcT> void pr(T v) { cout << ts(v); }
tcTUU> void pr(const T& t, const U&... u) { 
	pr(t); pr(u...); }
void ps() { pr("\n"); } // no spaces
tcTUU> void ps(const T& t, const U&... u) { 
	pr(t); if (sizeof...(u)) pr(" "); ps(u...); }
 
// File In/Out
void setIn(str s) { freopen(s.c_str(),"r", stdin); }
void setOut(str s) { freopen(s.c_str(),"w", stdout); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIO(str st = "") {
	unsyncIO();
	if (sz(st)) { setIn(st+".in"), setOut(st+".out"); } // If problem requires file reading
}

// DEBUG
void DBG() { cerr << "]" << endl; }
tcTUU> void DBG(const T& t, const U&... u) {
	cerr << ts(t); if (sizeof...(u)) cerr << ", ";
	DBG(u...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
	#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
	#define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
		 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
	#define dbg(...) 0
	#define chk(...) 0
#endif

int n;
int to_ask = 0;

int ask(int a, int b) {
	to_ask--;
	assert(to_ask >= 0);

	ps("?", a, b);
	cout.flush();
	int x;
	re(x);

	assert(x != -1);

	return x;
}

int v[2][mxN];

// 0 raven, 1 - a poveche ot b, 2 - b poveche ot a
void solve() {
	to_ask = cdiv(1 << (n + 1), 3);
	//DBG(to_ask);
	
	int k[2] = {0, 0};
	for(int i = 0; i < (1 << n); i++) {
		v[0][k[0]++] = (i + 1);
	}
	
	int t = 0;
	while(true) {
		if(k[t] == 1) {
			ps("!", v[t][0]);
			cout.flush();
			return;
		}
		else if(k[t] == 2) {
			int x = ask(v[t][0], v[t][1]);
			if(x == 1) {
				ps("!", v[t][0]);
			}
			else {
				ps("!", v[t][1]);
			}
			cout.flush();
			return;
		}
		else {
			k[t ^ 1] = 0;
			for(int i = 0; i < k[t]; i += 4) {
				int x = ask(v[t][i], v[t][i + 2]);
				if(x == 0) {
					x = ask(v[t][i + 1], v[t][i + 3]);
					if(x == 1) {
						v[t ^ 1][k[t ^ 1]++] = v[t][i + 1];
					}
					else {
						v[t ^ 1][k[t ^ 1]++] = v[t][i + 3];
					}
				}
				else if(x == 1) {
					int x2 = ask(v[t][i], v[t][i + 3]);
					if(x2 == 1) {
						v[t ^ 1][k[t ^ 1]++] = v[t][i];
					}
					else {
						v[t ^ 1][k[t ^ 1]++] = v[t][i + 3];
					}
				}
				else {
					int x2 = ask(v[t][i + 2], v[t][i + 1]);

					if(x2 == 1) {
						v[t ^ 1][k[t ^ 1]++] = v[t][i + 2];
					}
					else {
						v[t ^ 1][k[t ^ 1]++] = v[t][i + 1];
					}
				}
			}
			t ^= 1;
		}
	}
}

int main() {
	setIO();

	int t; re(t);

	while(t--) {
		re(n);
		solve();
	}

	return 0;
}
