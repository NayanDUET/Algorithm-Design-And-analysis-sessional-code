#include <bits/stdc++.h>

using namespace std;


int Prims(int v,vector<vector<pair<int,int>>>&adj,vector<pair<int,int>> &mstNode)
{

       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

       vector<int> vis(v,0);

       pq.push({0,0});

       vector<int> parent(v,-1);

       int sum = 0;

       while(!pq.empty())
       {
            auto it = pq.top();
            int nod = it.second;
            int wt = it.first;
            pq.pop();

            if(vis[nod]) continue;

            vis[nod] = 1;
            sum += wt;

            if(parent[nod] != -1)
            {
                mstNode.push_back({parent[nod],nod});
            }

            for(auto tt:adj[nod])
            {
                int adjNode = tt.first;
                int adjW = tt.second;

                if(!vis[adjNode])
                {
                    pq.push({adjW,adjNode});
                     parent[adjNode] = nod;
                }
            }
       }

       return sum;
}







int main()
{


     int n=6;


    vector<vector<pair<int,int>>>adj={

             {{1,4},{2,4}},
             {{2,2},{0,4}},
             {{0,4},{1,2},{3,3},{4,1},{5,6}},
             {{2,3},{5,2}},
             {{2,1},{5,3}},
             {{3,2},{2,6},{4,3}}

    };

    vector<pair<int,int>> mstNode;

    int ans = Prims(n,adj,mstNode);

    cout<<ans<<endl;

   cout << "Edges in MST:" << endl;
    for (auto edge : mstNode) {
        cout<<edge.first<<"-"<<edge.second<<endl;
    }




    return 0;
}
