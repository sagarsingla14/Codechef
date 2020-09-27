#include <bits/stdc++.h>
using namespace std;

class Stack {
    private:
        int arr[100];
        int topPosition;

    public:
        Stack() {
            topPosition = -1;
        }

        void push(int val);
        int top();
        void pop() {
            topPosition --;
        }
        int size() {
            return topPosition + 1;
        }
        bool isEmpty() {
            if(topPosition >= 0) {
                return false;
            }
            else{
                return true;
            }
        }
};

void Stack :: push(int val) {
    topPosition ++;
    arr[topPosition] = val;
}

int Stack :: top() {
    return arr[topPosition];
}


int main() {
    Stack s;

    s.push(1);
    s.push(2);
    s.push(4);
    s.push(3);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}
