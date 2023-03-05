#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class User
{
    private:
        int order;
        int age;
        string name;
    public:
        User(int order, int age, string name) : order(order), age(age), name(name) {};
        int getAge() const { return age; }
        string getName() const { return name; }
        friend bool compare(const User& left, const User& right);
};

bool compare(const User& left, const User& right)
{
    if (left.age == right.age)
    {
        return left.order < right.order;
    }
    return left.age < right.age;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    vector<User> Users;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int age;
        string name;

        cin >> age;
        cin >> name;

        Users.push_back(User(i, age, name));
    }

    sort(Users.begin(), Users.end(), compare);

    for (int i = 0; i < N; i++)
    {
        cout << Users[i].getAge() << " " << Users[i].getName() << '\n';
    }
    return 0;
}