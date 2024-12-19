#include<bits/stdc++.h>
using namespace std;

int knapsack(int capacity,vector<int> &weight,vector<int> &profit,int n)
{

      vector<vector<int>> dp(n+1,vector<int>(capacity+1,0));

      for(int i=1;i<=n;i++)
      {
          for(int w=0;w<=capacity;w++)
          {
              if(weight[i-1] <= w)
              {
                  dp[i][w] = max(dp[i-1][w],profit[i-1]+dp[i-1][w-weight[i-1]]);
              }
              else dp[i][w] = dp[i-1][w];
          }
      }

      return dp[n][capacity];
}




int main()
{

      cout<<"Enter number of items:";
      int n;
      cin>>n;

      cout<<"Enter the number of capacity ";
      int capacity;
      cin>>capacity;

      cout<<"Enter weight:";

      vector<int> weight(n);
      vector<int> profits(n);

      for(int i=0;i<n;i++)
      {

          cin>>weight[i];
      }

      cout<<"Enter values:";

      for(int i=0;i<n;i++)
      {

          cin>>profits[i];
      }

      int mxProfit = knapsack(capacity,weight,profits,n);

      cout<<"Max profit is:"<<mxProfit<<endl;



    return 0;
}
