#include<bits/stdc++.h>
using namespace std;
int n;
vector<string>color;
vector<int >pi,d,f;
int tt;
unordered_set<int>cycle;
void DFS(vector<vector<int>>&graph, int u){
    color[u]= "g";
    tt=tt+1;
    d[u]= tt;
    for(int v:graph[u]){

        if(color[v]=="w"){
            pi[v]=u;
            DFS(graph, v);
        }else if( color[v]== "g" ){
            int node= u;
            while(node !=v){
                cycle.insert(node);
                node=pi[node];
            }
        cycle.insert(v);
        }

    }

color[u]= "b";
tt++;
f[u]= tt;


}



int main(){
int edge,u,v;
cin>>n>>edge;
vector<vector<int>>graph(n+1);
for(int i=0; i<=n+1; i++){
        color.push_back("w");
        d.push_back(0);
        f.push_back(0);
        pi.push_back(-1);
}

for(int i=0;i <edge; i++){
    int x,y;
    cin>>x>>y;
    graph[x].push_back(y);
}

tt=0;

for(int i=0; i<n; i++){
    if(color[i]=="w")DFS(graph,i);
}

for(auto a:cycle){
    cout<<a<<"->";
}
cout<<endl;

return 0;
}
/*

8
9
0 1
1 2
2 3
3 0
2 4
4 5
5 6
6 4
6 7

*/

