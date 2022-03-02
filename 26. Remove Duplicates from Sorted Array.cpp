class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    std::map<int, int> numMap;
    for (auto i = 0; i < nums.size(); i++)
    {
      if (numMap.find(nums[i]) != numMap.end())
      {
        nums.erase(nums.begin() + i);
        i--;
      }
      else
      {
        numMap.insert(pair<int, int>(nums[i], 0));
      }
    }
    return nums.size();
  }
}

class Solution2
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    if (nums.size() == 0)
      return 0;
    int i = 0;
    int j = 1;
    int curr = nums[i];
    while (j < nums.size())
    {
      while (j < nums.size() && curr == nums[j])
      {
        j++;
      }
      if (j == nums.size())
      {
        nums[i] = curr;
        return i + 1;
      }
      else
      {
        nums[i] = curr;
        curr=nums[j];
        i++;
      }
    }
    nums[i] = curr;
    return i + 1;
  }
}