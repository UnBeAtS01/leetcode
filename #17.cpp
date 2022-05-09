vector<string> ans;
void solve(int idx, string &d, string v, map<int, string> &mp)
{
    if (idx >= d.size())
    {
        ans.push_back(v);
        return;
    }
    for (auto i : mp[int(d[idx] - '0')])
    {
        string temp = v;
        temp += i;
        solve(idx + 1, d, temp, mp);
    }
    return;
}
vector<string> letterCombinations(string d)
{
    map<int, string> mp;
    ans.clear();
    mp[2] = "abc";
    mp[3] = "def";
    mp[4] = "ghi";
    mp[5] = "jkl";
    mp[6] = "mno";
    mp[7] = "pqrs";
    mp[8] = "tuv";
    mp[9] = "wxyz";
    if (d.size() == 0)
        return ans;
    string s;
    solve(0, d, s, mp);
    return ans;
}