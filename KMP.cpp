//RETURN ALL THE INDICES OF OCCURING STRING NEEDLE
vector<int> solve(string &s)
{
    int m=s.size();
    int i=1, len=0;
    vector<int> lpss(m,0);
    while(i<m)
    {
        if(s[i]==s[len])
        {
            len++;
            lpss[i]=len;
            i++;
        }
        else 
        {
            if(len!=0)
            len=lpss[len-1];
            else 
            {
                lpss[i]=0;
                i++;
            }
        }
    }
    return lpss;
}

    vector<int>  strStr(string haystack, string needle) {
     
       int n=haystack.size();
       int m=needle.size();
         vector<int> lps=solve(needle);

       int i=0, j=0;
       vector<int> ans;
       while(i<n)
       {
          if(haystack[i]==needle[j])
                {
                    i++;
                    j++;
                }
        if(j==m)
        {
            ans.push_back(i-j);
            j=lps[j-1];
        }
        else if(i<n && haystack[i]!=needle[j])
        {
            if(j!=0) j=lps[j-1];
            else i++;
        }
       }
       return ans; 
    }
