#include <bits/stdc++.h>
#define ll long long int
using namespace std;

priority_queue<vector<int> > pq;

void Print_Maximum_Vector(vector<int> Vec)
{
    for (int i = 0; i < Vec.size(); i++) {
        cout << Vec[i] << " ";
    }
    cout << endl;
    return;
}

struct comp {
    bool operator()(const pair<char,int> &a,
        const pair<char,int> &b) {
            return (a.second < b.second);
        }
};

int main() {

    // map<char , int , greater <int> > mymap; 


    priority_queue<pair<char, int> , vector <pair <char , int>> , comp > pqueue;

    // using emplace() to insert pair in-place
    pqueue.emplace('a', 24);

    // using push() to insert pair
    pqueue.push(make_pair('b', 20));

    // printing the priority_queue
    while (!pqueue.empty()) {
        pair<char, int> p =  pqueue.top();
        cout << p.first << " "
             << p.second << endl;
        pqueue.pop();

    }





    // Type - 2;
    priority_queue<char , vector<char> , greater<char> > mypqueue2;
    mypqueue2.emplace('A');
    mypqueue2.emplace('B');
    mypqueue2.emplace('a');
    mypqueue2.emplace('x');
    mypqueue2.emplace('Y');
    mypqueue2.emplace('r');

    // printing the priority queue
    cout << "mypqueue2 = ";
    while (!mypqueue2.empty()) {
        cout << mypqueue2.top() << " ";
        mypqueue2.pop();
    }
    cout << endl;





    vector<int> data_1{ 10, 20, 30, 40 };
    vector<int> data_2{ 10, 20, 35, 40 };
    vector<int> data_3{ 30, 25, 10, 50 };
    vector<int> data_4{ 20, 10, 30, 40 };
    vector<int> data_5{ 5, 10, 30, 40 };

    // Inserting vectors into priority queue
    pq.push(data_1);
    pq.push(data_2);

    // printing the maximum vector till now
    Print_Maximum_Vector(pq.top());

    // Inserting vectors into priority queue
    pq.push(data_3);

    // printing the maximum vector till now
    Print_Maximum_Vector(pq.top());

    // Inserting vectors into priority queue
    pq.push(data_4);
    pq.push(data_5);

    // printing the maximum vector till now
    Print_Maximum_Vector(pq.top());

}
