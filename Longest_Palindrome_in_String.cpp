class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int n=s.length();
        int dp[n][n];
        int i;
        int j;
        int ans_start=0,ans_len=1;
        for(i=0;i<n-1;i++)
        {
            j=i+1;
            dp[i][i]=1;
            if(s[i]==s[j]) 
            {
                dp[i][j]=1;
                if(ans_len<2){
                ans_start=i;
                ans_len=2;}
            }
            else
            dp[i][j]=0;
        }
        dp[i][i]=1;
        int len=3;
        
        while(len <= n)
        {
            i=0;
            j=len+i-1;
            while(j<n)
            {
                if(s[i]==s[j] && dp[i+1][j-1]==1){
                    dp[i][j]=1;
                    if(ans_len<len)
                    {
                        ans_len=len;
                        ans_start=i;
                    }
                }
                else
                dp[i][j]=0;
                i++;
                j++;
            }
            len++;
        }
        return s.substr(ans_start,ans_len);
    }
};
