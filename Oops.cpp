#include <iostream>
#include <string>
using namespace std;

class Human
{
    public:
    string name;
    int age;
    char gender;

    void output()
    {
        cout << name << age << gender;
    }
};

int main()
{
    Human *sanchal = new Human();
    sanchal->name = "Sanchal";
    sanchal->age = 12;
    sanchal->gender = 'M';

    sanchal->output();

    return 0;

}