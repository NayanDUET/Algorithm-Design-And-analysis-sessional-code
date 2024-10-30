#include <bits/stdc++.h>
using namespace std;


struct Patient 
{
    string name;
    int age;

    bool operator<(const Patient& other) const 
    {
        return age < other.age;
    }
};

void prioritizePatients(vector<Patient>& patients)
 {
    
    priority_queue<Patient> maxHeap(patients.begin(), patients.end());

    while (!maxHeap.empty())
     {
        Patient oldest = maxHeap.top();
        maxHeap.pop();
        cout << "Name: " << oldest.name << ", Age: " << oldest.age << "\n";
    }
}

int main() {
   

     vector<Patient> patients = 
     {
        {"Abul", 65},
        {"Kabul", 40},
        {"Dabul", 27},
        {"Habul", 57},
        {"Mobul", 90},
        {"Karim", 23},
        {"Rahim", 50}
    };

    prioritizePatients(patients);

    return 0;
}
