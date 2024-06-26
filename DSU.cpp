//O(4*ALPHA, 1)
class DisjointSetUnion
{
      vector<int> rank, parent, size;
public:
      DisjointSetUnion(int n)
      {
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1, 1);
            for(int i=0;i<n+1;i++) parent[i]=i;
      }
            
      int ul_parent(int node)
      {
            if(node==parent[node])
                  return node;
           return parent[node]=ul_parent(parent[node]);                //path compression
      }

      void union_by_rank(int u, int v)
      {
            int ulp_u = ul_parent(u);
            int ulp_v = ul_parent(v);

            if(ulp_u == ulp_v) return ;
            else if(rank[ulp_u] < rank[ulp_v])
            {
                  parent[ulp_u]=ulp_v;
            }
            else if(rank[ulp_u] > rank[ulp_v])
            {
                  parent[ulp_v]=ulp_u;
            }
            else
            {
                  parent[ulp_u] = ulp_v;
                  rank[ulp_v]++;
            }
      }
       void union_by_size(int u, int v)
      {
            int ulp_u = ul_parent(u);
            int ulp_v = ul_parent(v);

            if(ulp_u == ulp_v) return ;
            if(size[ulp_u] < size[ulp_v])
            {
                  parent[ulp_u]=ulp_v;
                  size[ulp_v]+=size[ulp_u];
            }
            else
            {
                  parent[ulp_v]=ulp_u;
                  size[ulp_u]+=ulp_v;           
            }

      }

};
