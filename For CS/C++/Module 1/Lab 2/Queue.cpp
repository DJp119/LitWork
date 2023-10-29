#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

class CustomQueue {
private:
    stack<int> s1; 
    stack<int> s2; 

public:
    void enqueue(int x) {
        s1.push(x);
    }

    void dequeue() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (!s2.empty()) {
            s2.pop();
        }
    }

    int front() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (!s2.empty()) {
            return s2.top();
        }
        return -1; // Return -1 if the queue is empty
    }
};

int main() {
    CustomQueue queue;
    string input;
    getline(cin, input);
    stringstream ss(input);
    string query;

    while (ss >> query) {
        if (query == "1") {
            int x;
            ss >> x;
            queue.enqueue(x);
        } else if (query == "2") {
            queue.dequeue();
        } else if (query == "3") {
            int front = queue.front();
            if (front != -1) {
                cout << front << endl;
            }
        }
    }

    return 0;
}
