class Solution
{
public:
#define SS string
#define vs vector<SS>
#define vvi vector<vi>
#define vi vector<int>
    int differenceArrayoftheanswer(SS s, SS t)
    {

        int AnswerOfTHeProblem = 0;
        for (int i = 0; i < s.size(); i++)
        {

            AnswerOfTHeProblem += s[i] != t[i];
        }

        return AnswerOfTHeProblem;
    }
   vs twoEditWords(vs &a, vs &b)
    {

        vs AnswerOfTHeProblem;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < b.size(); j++)
            {

                if (differenceArrayoftheanswer(a[i], b[j]) <= 2)
                {
                    AnswerOfTHeProblem.push_back(a[i]);
                    break;
                }
            }
        }

        return AnswerOfTHeProblem;
    }
};