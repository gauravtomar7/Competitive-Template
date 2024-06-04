      #include <bits/stdc++.h>
      #include <ext/pb_ds/assoc_container.hpp>
      #include <ext/pb_ds/tree_policy.hpp>

      using namespace std;
      using namespace __gnu_pbds;

      typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ord_set; // *st.find_by_order(number at ith ), st.order_of_key(less than number)

      #define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
      #define ll long long
      #define endl "\n"
      #define pb push_back
      #define vll vector<ll> 
      #define maxpq priority_queue<ll> 
      #define minpq priority_queue<ll ,vector<ll>,greater<ll>> 
      #define all(x) (x).begin(), (x).end()     
      const int mod = 1e9+7;

      #ifndef ONLINE_JUDGE
      #define dbug(x) cerr << #x <<" "; _print(x); cerr << endl;
      #else
      #define dbug(x)
      #endif


      void _print(ll t) {cerr << t;}
      void _print(int t) {cerr << t;}
      void _print(string t) {cerr << t;}
      void _print(char t) {cerr << t;}
      void _print(double t) {cerr << t;}

      template <class T, class V> void _print(pair <T, V> p);
      template <class T> void _print(vector <T> v);
      template <class T> void _print(set <T> v);
      template <class T, class V> void _print(map <T, V> v);
      template <class T> void _print(multiset <T> v);
      template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
      template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
      template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
      template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
      template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


      //---------------------------------------------------------------
      ll ceel (ll n, ll m) {return ceil(1.*n/m);}

      ll power(ll a, ll b) // pow(a,b) (binary exponentation)
      {
          ll r=1;
          while(b)
          {
            if(b%2)
                  r=(r*a);
            a=(a*a);
            b/=2;
          }
          return r;
      }
      ll stn(string z) // string to number
      {
            ll i = 0;
            for (char c : z)
            {
                  if (c >= '0' && c <= '9')
                  {
                        i = i * 10 + (c - '0');
                  }
            }
            return i;
      }
      string binary(int y) // binary form
      {
            string ans = "";
            while (y > 0)
            {
                  ans = (char)('0' + y % 2) + ans;
                  y = y / 2;
            }
            return ans;
      }
      bool palindrome(const string &s)   // palindrome or not
      { 
            int n = s.length();
            for (int i = 0; i < n; i++)
            {
                  if (s[i] != s[n - i - 1])
                        return false;
            }
            return true;
      }

      bool primecheck(long long int z) // prime or not
      {
            for (long long int i = 2; i * i <= z; i++)
            {
                  if (z % i == 0)
                        return false;
            }
            return true;
      }
      vector<ll> SieveOfEratosthenes(ll n) // prime no. lesser than n
      {
            vector<bool> prime(n + 1, true);
                     prime[1] = false;
            for (ll p = 2; p * p <= n; p++)
            {
                  if (prime[p] == true)
                  {
                        for (ll i = p * p; i <= n; i += p)
                              prime[i] = false;
                  }
            }
           // return prime;
            vector<ll> k;
            for (ll p = 2; p <= n; p++)
            {
                  if (prime[p])
                        k.pb(p);
                       
            }
            return k;
      }
