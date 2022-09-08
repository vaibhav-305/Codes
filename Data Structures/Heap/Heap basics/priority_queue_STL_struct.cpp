#include <iostream>
#include <queue>
using namespace std;
struct Person{
    int age;
    float height;

    Person(int x, float h){
        age=x,height=h;
    }
};

struct CompareHeight {
    bool operator()(Person const& p1, Person const& p2)
    {
        // return "true" if "p1" is ordered before "p2", for example:
        return p1.height < p2.height;
    }
};
void showQ(auto Q)
{
    while(!Q.empty())
    {
        cout<<Q.top().age<<" "<<Q.top().height<<"\n";
        Q.pop();
    }
    cout<<"\n";
}
int main()
{
    priority_queue<Person,vector<Person>,CompareHeight> pQ;   //comparator for heights
    pQ.push(Person(30,5.5));
    pQ.push(Person(25,5));
    pQ.push(Person(20,6));
    pQ.push(Person(33,6.1));
    pQ.push(Person(23,5.6));
    showQ(pQ);
  return 0;
}
