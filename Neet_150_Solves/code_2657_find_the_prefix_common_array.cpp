class Solution {
public:
    int n;
    set<int>a;
    set<int>b;
    set<int>common;

    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B)
    {
        n=A.size();
        int cnt=0;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            a.insert(A[i]);
            b.insert(B[i]);
            if(a.count(A[i])!=0 && b.count(A[i])!=0)
            {
                common.insert(A[i]);
            }
            if(a.count(B[i])!=0 && b.count(B[i])!=0)
            {
                common.insert(B[i]);
            }
            ans.push_back(common.size());
        }
        return ans;
    }
};