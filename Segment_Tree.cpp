class SGTree {
      vector<ll> seg;
public:
      SGTree(ll n) {
            seg.resize(4 * n + 1);
      }
 
      //O(N)
      void build(ll ind, ll low, ll high, ll arr[]) {
            if (low == high) {
                  seg[ind] = arr[low];
                  return;
            }
            ll mid = (low + high) / 2;
            build(2 * ind + 1, low, mid, arr);
            build(2 * ind + 2, mid + 1, high, arr);
            seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);        //change
      }
 
      //O(LOGN)
      ll query(ll ind, ll low, ll high, ll l, ll r) {
            // no overlap
            // l r low high or low high l r
            if (r < low || high < l) return 0;          //change
 
            // complete overlap
            // [l low high r]
            if (low >= l && high <= r) return seg[ind];
 
            ll mid = (low + high) >> 1;
            ll left = query(2 * ind + 1, low, mid, l, r);
            ll right = query(2 * ind + 2, mid + 1, high, l, r);
            return (left + right);                                    //change
      }
 
      //O(LOGN)
      void update(ll ind, ll low, ll high, ll i, ll val) {
            if (low == high) {
                  seg[ind] = val;
                  return;
            }
 
            ll mid = (low + high) >> 1;
            if (i <= mid) update(2 * ind + 1, low, mid, i, val);
            else update(2 * ind + 2, mid + 1, high, i, val);
            seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);                   //change
      }  
};
   
