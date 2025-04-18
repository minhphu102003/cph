vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    sort(potions.begin(), potions.end());
    vector<int> result;
    int len = spells.size();
    int right = potions.size();
    for (int  i = 0; i < len; i++)
    {
        int l = 0, r = right;
        while (l < r)
        {
            int mid = (l + r)/2;
            if ((ll)spells[i] * potions[mid] >= success) {
                right = mid;
            } else {
                l = mid + 1;
            }
        }
        result.push_back(right - l);
    }

    return result;
}