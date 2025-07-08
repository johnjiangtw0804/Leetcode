#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct memoBlock {
    int start;
    int end;
    int mid;
    // size = end - start + 1
};

class Allocator
{
private:
    int capacity;
    list<memoBlock> dataStore;
    unordered_map<int, vector<list<memoBlock>::iterator>> midToBlock;
public:
    Allocator(int n)
    {
        this->capacity = n;
    }

    int allocate(int size, int mID)
    {
        // find the next available block
        // steps:
        //      1 如果為 空
        //      2 最開頭
        //      3 gap 得部分
        //      3 如果是尾部

        if (dataStore.size() == 0) {
            if (size > capacity) {
                return -1;
            }
            dataStore.emplace_back(memoBlock{0, size-1, mID});
            midToBlock[mID].push_back(dataStore.begin());
            return 0;
        }
        if (dataStore.front().start >= size) {
            auto loc = dataStore.emplace(dataStore.begin(), memoBlock{0, size - 1, mID});
            midToBlock[mID].push_back(loc);
            return 0;
        }

        auto it = dataStore.begin();
        while (next(it) != dataStore.end())
        {
            int gapStart = it->end + 1;
            int gapEnd = next(it)->start - 1;
            // have enough spot
            if (gapEnd - gapStart + 1 >= size)
            {
                // insert to next location
                auto loc = dataStore.emplace(next(it), memoBlock{gapStart, gapStart + size - 1, mID});
                midToBlock[mID].push_back(loc);
                return gapStart;
            }
            it++;
        }

        // at the end
        int avail = it->end + 1;
        if (avail + size - 1 >= capacity)
            return -1;
        it = dataStore.emplace(dataStore.end(), memoBlock{avail, avail+size - 1, mID});
        midToBlock[mID].push_back(it);
        return avail;
    }
    int freeMemory(int mID)
    {
        if (midToBlock.find(mID) == midToBlock.end()) {
            return 0;
        }
        int count = 0;
        auto its = midToBlock[mID];
        for (auto it : its) {
            count += (it->end - it->start + 1);
            dataStore.erase(it);
        }

        midToBlock.erase(mID);
        return count;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
