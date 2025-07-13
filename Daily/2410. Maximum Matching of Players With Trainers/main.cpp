class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i2 = 0;
        int res = 0;
        for (int i = 0; i < players.size(); i++)
        {
            while (i2 < trainers.size() && trainers[i2] < players[i])
            {
                i2++;
            }
            if (i2 == trainers.size())
            {
                break;
            }
            i2++;
            res++;
        }
        return res;
    }
};
