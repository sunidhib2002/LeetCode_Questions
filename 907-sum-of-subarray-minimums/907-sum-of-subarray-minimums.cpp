class Solution {
public:
    void print(vector<int> a) {
        for (int i = 0; i < a.size(); i++) {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    
    vector<int> GetRight(vector<int> arr) {
        vector<int> right;
        stack<pair<int, int>> s;
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (s.empty()) {
                right.push_back(-1);
            } 
            if (!s.empty() && s.top().first < arr[i]) {
                right.push_back(s.top().second);
            } else if (!s.empty() && s.top().first >= arr[i]) {
                while (!s.empty() && s.top().first > arr[i]) {
                    s.pop();
                }
                if (!s.empty()) {
                    right.push_back(s.top().second);
                } else {
                    right.push_back(-1);
                }
            } 
            s.push({arr[i], i});
        }
        reverse(right.begin(), right.end());
        vector<int> ans;
        int n = right.size();
        for (int i = 0; i < right.size(); i++) {
            if (right[i] == -1) {
                ans.push_back(n - 1 - i);
            } else {
                ans.push_back(right[i] - i - 1);
            }
        }
        return ans;
    }
    
    vector<int> GetLeft(vector<int> &arr) {
        stack<pair<int,int>> s;
        vector<int> left;
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            if (s.empty()) {
                left.push_back(-1);
            } else if (!s.empty() && s.top().first < arr[i]) {
                left.push_back(s.top().second);
            } else if (!s.empty() && s.top().first >= arr[i]) {
                while (!s.empty() && s.top().first >= arr[i]) {
                    s.pop();
                }
                if (s.empty()) {
                    left.push_back(-1);
                } else {
                    left.push_back(s.top().second);
                }
            }
            s.push({arr[i], i});
        }
        // print(left);
        for (int i = 0; i < left.size(); i++) {
            if (left[i] == -1) {
                ans.push_back(i); 
            } else {
                ans.push_back(i - 1 - left[i]);
            }
        }
        return ans;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> left = GetLeft(arr);
        vector<int> right = GetRight(arr);
        int m = 1000000007;
        // print(right);
        // print(left);
        long long ans = 0;
        for (int i = 0; i < left.size(); i++) {
            ans += ((left[i] + 1) * (right[i] + 1)  * 1LL * arr[i]);
        }
        return ans % m;
    }
};