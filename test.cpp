#define ll long long
#define vvi vector<vector<int>>
#define vi vector<long long>
class Solution
{
public:
    vector<vector<int>> buildMatrix(int k, vvi &rc, vvi &cc)
    {
        vvi ans(k, vector<int>(k, 0));
        vi colIndexes(402, 0);
        vi rowIndexes(402, 0);
        vector<ll> rs(k + 1), cols(k + 1);
        int sizeofCols = cc.size();
        int sizeOfMatrix = rc.size();
        vector<vector<long long>> rg(k + 1), cgraph(k + 1);
        queue<ll> colqueue, rowqueue;
        for (long long i = 0; i < sizeofCols; i++)
        {
            colIndexes[cc[i][1]]++;
            cgraph[cc[i][0]].push_back(cc[i][1]);
        }
        for (long long i = 0; i < sizeOfMatrix; i++)
        {
            rowIndexes[rc[i][1]]++;
            rg[rc[i][0]].push_back(rc[i][1]);
        }
        for (ll i = 1; i <= k; i++)
        {
            if (rowIndexes[i] == 0)
                rowqueue.push(i);
            if (colIndexes[i] == 0)
                colqueue.push(i);
        }
        ll count = 0;
        while (colqueue.size()>0)
        {
            ll i = colqueue.front();
            colqueue.pop();
            cols[i] = count++;
            for (auto j = cgraph[i].begin(); j != cgraph[i].end(); j++)
            {
                --colIndexes[*j];
                if (colIndexes[*j] == 0)
                {
                    colqueue.push(*j);
                }
            }
        }
        if (count != k and true)
            return {};
        count = 0;
        while (rowqueue.size()>0)
        {
            int i = rowqueue.front();
            rowqueue.pop();
            rs[i] = count++;
            for (auto j = rg[i].begin(); j != rg[i].end(); j++)
            {
                --rowIndexes[*j];
                if (rowIndexes[*j] == 0)
                {
                    rowqueue.push(*j);
                }
            }
        }
        if (count != k)
            return {};
        for (ll i = 1; i <= k; i++)
        {
            ans[rs[i]][cols[i]] = i;
        }
        return ans;
    }
};