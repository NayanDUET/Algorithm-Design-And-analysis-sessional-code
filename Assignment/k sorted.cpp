#include <bits/stdc++.h>
using namespace std;

struct Element
 {
    int value;   
    int arrayIdx; 
    int elemIdx;

   
    bool operator>(const Element& other) const 
    {
        return value > other.value;
    }
};

vector<int> Msorted(const vector<vector<int>>& vec) 
{

    vector<int> res;
    priority_queue<Element, vector<Element>, greater<Element>> mh;

   
    for (int i = 0; i < vec.size(); ++i) 
    {
        if (!vec[i].empty()) {
            mh.push({vec[i][0], i, 0});
        }
    }

    
    while (!mh.empty())
     {
        Element sml = mh.top();
        mh.pop();
        res.push_back(sml.value);

        if (sml.elemIdx + 1 < vec[sml.arrayIdx].size())
         {
            mh.push({vec[sml.arrayIdx][sml.elemIdx + 1], 
               sml.arrayIdx, sml.elemIdx + 1});
        }
    }

    return res;
}

int main() 
{
    vector<vector<int>> vec = 
    {
        {1, 5, 9},
        {2, 6, 8},
        {3, 7, 10},
        {4, 11, 15},
        {16, 20, 30},
    };

    vector<int> marray = Msorted(vec);

    cout << "Merged array:\n";
    for (int num : marray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
