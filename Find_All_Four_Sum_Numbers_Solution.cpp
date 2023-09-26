**********************************************************************************  Question  ******************************************************************************************************************
Given an array A of integers and another number K. Find all the
unique quadruple from the given array that sums up to K.
Also note that all the quadruples which you return should be
internally sorted, ie for any quadruple [ql , q2, q3, q4] the following
should follow: ql <= q2 <= q3 <= q4.
Example 1:
Input:
Output: 00 1 2
Explanation: Sum of 0, 0, 1, 2 is equal
to K.
Example 2:
  Output: 2 3
Explanation:
sum of 2, 4,
Input:
N = 7, K = 23
24710
3578
810
Sum of 2, 3, 8, 10 = 23,
7 10 = 23 and sum of 3,
5, 7, 8 = 23.
Your Task:
You don't need to read input or print anything. Your task is to
complete the function fourSum() which takes the array arr[] and
the integer k as its input and returns an array containing all the
quadruples in a lexicographical manner. In the output each
quadruple is separate by $. The printing is done by the driver's
code.
Expected Time Complexity: O(N ).
Expected Auxiliary Space: O(N ).
Constraints:
1 N 100
-1000 1000
-100 100


************************************************************************************  Solution  ****************************************************************************************************************
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
     vector<vector<int> > fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    //calculating the quadruplets:
    for (int i = 0; i < n; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
     }

      return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends

