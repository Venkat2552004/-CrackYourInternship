/*
 * @lc app=leetcode id=381 lang=cpp
 *
 * [381] Insert Delete GetRandom O(1) - Duplicates allowed
 */

// @lc code=start
class RandomizedCollection
{
public:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> m;

    RandomizedCollection()
    {

    }

    bool insert(int val)
    {
        bool res = (m.find(val) == m.end());
        m[val].push_back(nums.size());
        nums.push_back({val, m[val].size() - 1});
        return res;
    }

    bool remove(int val)
    {
        bool res = (m.find(val) != m.end());
        if (res)
        {
            auto last = nums.back();
            m[last.first][last.second] = m[val].back();
            nums[m[val].back()] = last;
            m[val].pop_back();
            if (m[val].empty())
                m.erase(val);
            nums.pop_back();
        }
        return res;
    }

    int getRandom()
    {
        return nums[rand() % nums.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

