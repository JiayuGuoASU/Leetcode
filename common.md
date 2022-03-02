```c++
//求和   
void print(vector<vector<int>> &ans){
        for (int i=0;i<ans.size();i++){
            for (int j=0;j<ans[0].size();j++){
                cout<<ans[i][j]<<' ';
            }
            cout<<endl;
        }
    }
```

map 中为value进行排序

```c++
class Solution {
public:
    typedef pair<char, int> PAIR;
    struct CmpByValue {  
      bool operator()(const PAIR& lhs, const PAIR& rhs) {  
        return lhs.second > rhs.second;  
      }  
    };
    string frequencySort(string s) {
        map<char, int> ans;
        for (int i=0;i<s.length();i++){
            if (ans.count(s[i])==0){
                ans.insert(PAIR(s[i],1));
            } else {
                ans[s[i]]++;
            }
        }
        vector<PAIR> ansv(ans.begin(), ans.end());  
        sort(ansv.begin(), ansv.end(), CmpByValue());  
        string anss="";
        for (int i=0;i<ansv.size();i++){
            string curr="";
            for (int j=0;j<ansv[i].second;j++){
                curr+=ansv[i].first;
            }
            anss=anss+curr;
        }
        return anss;
    }
};
```

string split 实现方法

```c++
void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));
 
    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}
```

sort 排序 改写

```
struct cmp
{
       bool operator() (const Student& s1, const Student& s2)
       {
              if(s1.age==s2.age)
                     return s1.name <s2.name;
              else  return s1.age < s2.age;
        }
};
sort(a,a+n,cmp());
```

