  class Segment_Tree {
      vector<int> seg;
public:
      //Constructor
      Segment_Tree(int n) {
            seg.resize(4 * n + 1);                                    //Mimimum element in range
      }

      //build
      // TIME COMPLEXITY O(N)
      void build(int ind, int low, int high, vector<ll> arr) {
            if (low == high) {
                  seg[ind] = arr[low];
                  return;
            }

            int mid = (low + high) / 2;
            build(2 * ind + 1, low, mid, arr);
            build(2 * ind + 2, mid + 1, high, arr);
            seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);        //change
      }


      // TIME COMPLEXITY O(LOGN)
      int query(int ind, int low, int high, int l, int r) {
            // no overlap
            // l r low high or low high l r
            if (r < low || high < l) return INT_MAX;                  //change

            // complete overlap
            // [l low high r]
            if (low >= l && high <= r) return seg[ind];

            int mid = (low + high) >> 1;
            int left = query(2 * ind + 1, low, mid, l, r);
            int right = query(2 * ind + 2, mid + 1, high, l, r);
            return min(left, right);                                 //change
      }

      //Update
      // TIME COMPLEXITY O(LOGN)
      void update(int index, int low, int high, int pos, int val, vector<ll> arr) {
            if (low == high) {
                  arr[pos]=val;
                  seg[index] = val;
                  return;
            }

            int mid = (low + high) >> 1;
            if (pos <= mid) update(2 * index + 1, low, mid, pos, val,arr);
            else update(2 * index + 2, mid + 1, high, pos, val, arr);
            seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);                    //change
      }
};

