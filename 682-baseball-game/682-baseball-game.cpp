class Solution {
public:
    int calPoints(vector<string>& ops) 
    {
        list<int> l;
		for (string s : ops)
		{
			if (s.size() >= 2 or s >= "0" && s <= "9")
				l.push_back(stoi(s));
			else if (s == "D")
				l.push_back((2 * l.back()));
			else if (s == "C")
				l.pop_back();
			else if (s == "+")
			{
				auto it = l.end();
				it--;
				it--;
				l.push_back((l.back() + *(it)));
			}
		}
		return int(accumulate(l.begin(), l.end(), 0));
    }
};