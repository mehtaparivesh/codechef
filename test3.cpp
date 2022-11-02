class Solution
{
public:
#define vs vector<string>
#define vvi vector<vi>
#define vi vector<int>
    int destroyTargets(vi &numbers, int temporary)
    {

        unordered_map<int, vi> mymap;
        sort(numbers.begin(), numbers.end());
        for (int i = 0; i < numbers.size(); i++)
        {
            mymap[numbers[i] % temporary].push_back(i);
        }

        int CURR = 0;
        int response = 0;
        for (int i = 0; i < numbers.size(); i++)
        {

            int mod = numbers[i] % temporary;
            auto &arr = mymap[mod];

            auto it = lower_bound(arr.begin(), arr.end(), i);

            int count = arr.end() - it;

            if (count > CURR)
            {
                CURR = count;
                response = numbers[i];
            }
        }

        return response;
    }
};