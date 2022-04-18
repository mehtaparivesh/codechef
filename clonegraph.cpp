int compareVersion(string version1, string version2)
{
    int i = 0;
    int j = 0;
    int n1 = version1.size();
    int n2 = version2.size();

    int one = 0;
    int two = 0;
    while (i < n1 || j < n2)
    {
        while (i < n1 && version1[i] != '.')
        {
            one = one * 10 + (version1[i] - '0');
            i++;
        }

        while (j < n2 && version2[j] != '.')
        {
            two = two * 10 + (version2[j] - '0');
            ;
            j++;
        }

        if (one > two)
            return 1;
        else if (one < two)
            return -1;

        one = 0;
        two = 0;
        i++;
        j++;
    }

    return 0;
}