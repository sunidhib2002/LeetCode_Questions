class Solution {
public:
    void Generate(int num1, int num2, int k, vector<int> &fiboSeries) {
        if (num1 + num2 > k) {
            return;
        }
        fiboSeries.push_back(num1 + num2);
        // num2 = num1 + num2;
        // num1 = num2;
        Generate(num2, num2 + num1, k, fiboSeries);
    }
    
    int findMinFibonacciNumbers(int k) {
        vector<int> fiboSeries;
        fiboSeries.push_back(1);
        fiboSeries.push_back(1);
        Generate(1, 1, k, fiboSeries);
        // for (int i = 0; i < fiboSeries.size(); i++) {
        //     cout<<fiboSeries[i]<<" ";
        // }
        // cout<<endl;
        int n = fiboSeries.size() - 1;
        int cnt = 0;
        for (int i = n; i >= 0; i--) {
            if (fiboSeries[i] <= k) {
                k -= fiboSeries[i];
                cnt += 1;
            }
        }
        return cnt;
    }
};