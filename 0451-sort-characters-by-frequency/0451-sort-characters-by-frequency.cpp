class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(128, 0);
        for (char ch : s) freq[ch]++;
        vector<pair<int, char>> v;
        for (int i = 0; i < 128; i++) {
            if (freq[i] > 0) v.push_back({freq[i], char(i)});
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        string ans;
        for (auto &[count, ch] : v)
            ans.append(count, ch);

        return ans;
    }
};
