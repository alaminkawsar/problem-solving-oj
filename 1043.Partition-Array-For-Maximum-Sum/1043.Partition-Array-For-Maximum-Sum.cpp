#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        for(int i = n-1; i >= 0; i--){
            int mx = 0;
            int end = min(n, i+k);
            for(int j = i; j < end; j++) {
                mx = max(mx, arr[j]);
                dp[i] = max(dp[i], dp[j+1] + (j-i+1)*mx);
            }
        }
        return dp[0];
    }
};

void solve()
{
    int n;
    vector<int> arr;
    int k,val;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>val, arr.push_back(val);
    Solution s;
    cout << s.maxSumAfterPartitioning(arr, k) << endl;
    
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    freopen("input.txt","r",stdin);
    int t=1,ts=0; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
