#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long int mn=INT_MIN,mid,ans, mx = 0,sum;
        int cnt=0;
        for(auto i: nums){
            mx += i;
            mn = max(mn,i*1LL);
        }
        while(mn<=mx) {
            mid = (mx+mn)/2;
            cnt=1,sum=0;
            for(auto &i: nums) {
                sum+=i;
                if(sum>mid) {
                    sum=i;
                    cnt++;
                }
            }
            if(cnt==k) {
                ans=mid;
                mx=mid-1;
            } else if (cnt>k) {
                mn=mid+1;
            } else {
                ans=mid;
                mx=mid-1;
            }
        }
        return ans;
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
    cout << s.splitArray(arr, k) << endl;
    
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