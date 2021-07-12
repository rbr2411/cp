#include <iostream>
#include <vector>
#include<queue>
using namespace std;
int main()
{
    // Max Heap
    priority_queue<int, vector<int>> pq;
    pq.push(2);
    pq.push(3);
    pq.push(22);
    pq.push(9);
    pq.push(1);
    pq.push(55);
    cout << pq.top() << endl;
    cout << "size: " << pq.size() << endl;
    pq.pop();
    cout << pq.top() << endl;
    cout << "size: " << pq.size() << endl;

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> min_pq;
    min_pq.push(22);
    min_pq.push(12);
    min_pq.push(48);
    min_pq.push(87);
    cout << min_pq.top() << endl;
    min_pq.pop();
    cout << min_pq.top() << endl;
    return 0;
}