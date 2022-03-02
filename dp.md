[Partition Array for Maximum Sum - LeetCode](https://leetcode.com/problems/partition-array-for-maximum-sum/)

我想错了！！！

```c++
class Solution {
public:
    void print(vector<int> &arr){
        for (int i=0;i<arr.size();i++){
            cout<<arr[i]<<',';
        }
        cout<<endl;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> ans(arr.size(),0);
        int maxx=-1;
        for (int i=0;i<arr.size();i++){
            if (maxx<arr[i]) maxx=arr[i];
            ans[i]=(i+1)*maxx;
        }
        print(ans);
        for (int p=2;p<=k;p++){
            for (int i=arr.size()-1;i>=p-1;i--){
                int max=arr[i];
                int sum=arr[i];
                for (int j=i-1;j>=p-2;j--){
                    if (arr[j+1]>max){
                        max=arr[j+1];
                    }
                    if (ans[j]+max*(i-j)>sum){
                        sum=ans[j]+max*(i-j);
                    }
                }
                ans[i]=sum;
            }
            print(ans);
        }
        return ans[ans.size()-1];
    }
};
```

