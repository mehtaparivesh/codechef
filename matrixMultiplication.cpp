class Solution
{
public:
    int convertTime(string cc, string correct)
    {
        int ans = 0;
        string c, hhgfghvjkvhjbkjn;
        c = cc.substr(0, 2);
        hhgfghvjkvhjbkjn = correct.substr(0, 2);
        int cu, fghjgfhjk;
        cu = stoi(c);
        fghjgfhjk = stoi(hhgfghvjkvhjbkjn);
        ans = fghjgfhjk - cu;

        c.erase();
        hhgfghvjkvhjbkjn.erase();

        c = cc.substr(3, 5);
        hhgfghvjkvhjbkjn = correct.substr(3, 5);

        cu = stoi(c);
        fghjgfhjk = stoi(hhgfghvjkvhjbkjn);
        int cfvghjkntryfuihxtfcgvhjbk = 0;
        if (fghjgfhjk >= cu)
        {
            cfvghjkntryfuihxtfcgvhjbk = fghjgfhjk - cu;
        }
        else
        {
            int diff = 60 - cu;
            cfvghjkntryfuihxtfcgvhjbk = diff + fghjgfhjk;
            ans--;
        }
        while (cfvghjkntryfuihxtfcgvhjbk)
        {
            if (cfvghjkntryfuihxtfcgvhjbk >= 15)
            {
                cfvghjkntryfuihxtfcgvhjbk -= 15;
                ans++;
            }
            else if (cfvghjkntryfuihxtfcgvhjbk >= 5)
            {
                cfvghjkntryfuihxtfcgvhjbk -= 5;
                ans++;
            }
            else
            {
                cfvghjkntryfuihxtfcgvhjbk -= 1;
                ans++;
            }
        }
        cout << ans << endl;

        return ans;
    }
};