class Solution {
public:
    void print(unordered_map<int, int> delay) {
        cout<<"map "<<endl;
        for (auto pr : delay) {
            cout<<pr.first<<" "<<pr.second<<endl;
        }
        cout<<endl;
    }
    
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long time = 1;
        int i = 0;
        unordered_map<long long, long long> delay;
        while (i < tasks.size()) {
            if (delay.find(tasks[i]) == delay.end()) {
                delay[tasks[i]] = time + space + 1; 
                i++;
            } else if (delay.find(tasks[i]) != delay.end()) {
                if (time >= delay[tasks[i]]) {
                    delay[tasks[i]] = time + space + 1; 
                    i++;
                } else {
                    time = delay[tasks[i]];
                    delay[tasks[i]] = time + space + 1; 
                    i++;
                }
            }
            time++;
        }
        return (time - 1);
    }
};