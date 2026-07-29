#include<bits/stdc++.h>
using namespace std;

class Teacher{
    private:
        double salary;

    public:
        string name;
        string dept;
        string subject;

        Teacher(string name, string dept, string subject, double salary)
        {
            this->name = name;
            this->dept = dept;
            this->subject = subject;
            this->salary = salary;
        }
        
        
};

int main()
{
    vector<int> arr = {3, 4, 5, 1, 2};

    Teacher t1("Shradha", "Computer Science", "C++", 25000);


    return 0;
}