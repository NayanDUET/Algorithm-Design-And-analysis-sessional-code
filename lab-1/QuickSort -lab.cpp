#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr,int m, int p)
 {
        int v=arr[m];
        int i=m;
        int j=p;
        while(i<j){
            while(arr[i]<=v)
                i++;
            while(arr[j]>v)
                j--;
            if(i < j){

                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }}

        arr[m]=arr[j];
        arr[j]=v;
        return j;
    }
    void quickSort(vector<int> &arr,int p,int q)
   {
       if (p<q)
      {
        int j = partition(arr,p,q);
        quickSort(arr,p,j-1);
        quickSort(arr,j+1,q);
      }
      return;
   }


int main()
{
    string filename="Quicksort.txt";
    random_device rd;
    mt19937 gen(rd());
    int lower_bound = 1;
    int upper_bound = 5000000;
    uniform_int_distribution<> distr(lower_bound,upper_bound);
    ofstream outfile(filename);
    if (!outfile)
    {return 0;}
    cout<<"saving random numbers to "<<filename<<endl;
    for(int i=0;i<upper_bound;i++)
    {
        int random_number=distr(gen);
        outfile<<random_number<<endl;
    }
    outfile.close();
    ifstream infile(filename);
    if(!infile)
    {
        return 0;
    }
       vector<int>arr;
       int number;
       while(infile>>number)
           arr.push_back(number);

       infile.close();
       int n=arr.size();
       quickSort(arr,0,n-1);
   }
