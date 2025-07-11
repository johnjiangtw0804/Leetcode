#include <functional>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;
using ll = long long;
using PLL = pair<ll, ll>;

class Solution
{
public:
    int mostBooked(ll rooms, vector<vector<int>> &meetings)
    {
        // returns the rooms that has the most meetings
        sort(meetings.begin(), meetings.end());
        auto comp = [](const PLL &a, const PLL &b)
        {
            if (a.first == b.first)
            {
                return a.second > b.second;
            }
            return a.first > b.first;
        };
        priority_queue<PLL, vector<PLL>, decltype(comp)> pq;
        unordered_map<ll, ll> roomNum2Count;
        set<ll> availableRooms;

        // use next room start time as our current time
        // release all the possible rooms
        function<void(ll)> releaseRooms = [&](ll current)
        {
            while (pq.size() > 0 && pq.top().first <= current)
            {
                availableRooms.insert(pq.top().second);
                pq.pop();
            }
        };

        function<void(ll, ll)> bookTheRoom = [&](ll room, ll endTime)
        {
            // use
            roomNum2Count[room]++;
            // mark used
            availableRooms.erase(room);
            // track progress
            pq.push(PLL(endTime, room));
        };
        for (int i = 0; i < rooms; i++)
        {
            availableRooms.insert(i);
        }

        // int delayed = 0; we should not delay all the meetings!
        // because what if later meeting actually starts at the right time
        for (int i = 0; i < (int)meetings.size(); i++)
        {
            vector<int> &meeting = meetings[i];
            releaseRooms(meeting[0]);

            if (availableRooms.size() > 0)
            {
                auto it = availableRooms.begin();
                ll nextRoom = *it;
                bookTheRoom(nextRoom, meeting[1]);
            }
            else
            {
                // must delay
                // book the next availablRoom
                ll duration = meeting[1] - meeting[0];
                ll newEnd = pq.top().first * 1ll + duration;
                availableRooms.insert(pq.top().second);
                pq.pop();
                auto it = availableRooms.begin();
                ll nextRoom = *it;
                bookTheRoom(nextRoom, newEnd);
            }
        }

        ll resRoom = INT_MAX / 2;
        ll resCount = 0;
        for (auto &[room, count] : roomNum2Count)
        {
            if (resCount < count || (resCount == count && resRoom > room))
            {
                resRoom = room;
                resCount = count;
            }
        }
        return (int)resRoom;
    }
};
// Hint 1:
// Use long long for time values in C++ to handle large timestamps.

// Hint 2:
// When you have a meeting but all rooms are booked, you need to assign the meeting to the next available room (the earliest room to become free, with the smallest room number). Only that meeting should be delayed — its duration stays the same, and the other meetings should not be shifted or delayed in any way. This adjustment happens only for that specific meeting.

// Otherwise, if rooms are available, just assign the room normally.

// Hint 3:
// Sometimes, rooms naturally become available. When you have a meeting with a start time greater than or equal to the earliest ending room in the priority queue, it means the room can be released for use. Pop all meetings that have already ended so you can assign those rooms.
