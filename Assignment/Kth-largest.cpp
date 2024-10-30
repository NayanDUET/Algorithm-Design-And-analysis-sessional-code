#include <bits/stdc++.h>
using namespace std;



priority_queue<int,vector<int>,greater<int>> mh;


void add(int num,int k) 
{
        
        if (mh.size() < k) 
        {
            mh.push(num);
        } 
        else if (num > mh.top())
         {
            mh.pop();
            mh.push(num);
        }
 }

int main() 
{

    int k = 3;

    vector<int> stream = {7,3,2,8,9,13,12};
    
    for(auto it: stream)
    {
        add(it,k);
    }

    cout<<"The " <<k <<" th Largest element is :"<<mh.top()<<endl;

    return 0;
}
