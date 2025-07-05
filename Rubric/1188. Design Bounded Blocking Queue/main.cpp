#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <condition_variable>

using namespace std;
using namespace std;
class BoundedBlockingQueue
{
private:
    mutex m;
    int capacity;
    queue<int> dynamicDataStore;
    condition_variable cv;
    // wait: blocks the current thread until the condition variable is awakened
    // notify_one: notifies one waiting thread
public:
    BoundedBlockingQueue(int capacity)
    {
        this->capacity = capacity;
    }

    int dequeue()
    {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [&]()
                { return !dynamicDataStore.empty(); });
        int res = dynamicDataStore.front();
        dynamicDataStore.pop();
        cv.notify_all();
        return res;
    }

    void enqueue(int element)
    {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [&]()
                { return capacity > dynamicDataStore.size(); });
        dynamicDataStore.push(element);
        cout << element << endl;
        cv.notify_all();
    }

    int size()
    {
        return dynamicDataStore.size();
    }
};

int main() {
    srand(time(nullptr));
    // test cases 1
    // capacity 2
    BoundedBlockingQueue bbq(2);

    auto producer = [&]()
    {
        for (int i = 0; i < 5; ++i)
        {
            int newData = rand();
            cout << "Generating: " << newData << endl;
            bbq.enqueue(newData);
            this_thread::sleep_for(chrono::milliseconds(200));
        }
    };

    auto consumer = [&]() {
        for (int i = 0; i < 5; i++) {
            int consumedData = bbq.dequeue();
            cout << "consuming old data " << consumedData << endl;
            this_thread::sleep_for(chrono::milliseconds(200));
        }
    };

    // bunch of threads doing these enqueue and deque, maybe two each
    vector<thread> producer_threads;
    vector<thread> consumer_threads;
    for (int i = 0; i < 2; i++) {
        producer_threads.push_back(thread(producer));
        consumer_threads.push_back(thread(consumer));
    }

    for (int i = 0; i < 2; i++)
    {
        producer_threads[i].join();
        consumer_threads[i].join();
    }

    return 0;
}
