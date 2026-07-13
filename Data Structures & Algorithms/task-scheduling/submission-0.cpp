class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Count frequencies of each task
        vector<int> counts(26, 0);
        for (char ch : tasks) {
            counts[ch - 'A']++;
        }

        // Step 2: Push all existing frequencies into a max-heap
        priority_queue<int> maxHeap;
        for (int f : counts) {
            if (f > 0) maxHeap.push(f);
        }

        // Queue stores pairs of {remaining_frequency, time_when_available}
        queue<pair<int, int>> cooldownQueue;
        int time = 0;

        // Step 3: Process tasks until both heap and queue are empty
        while (!maxHeap.empty() || !cooldownQueue.empty()) {
            time++;

            if (!maxHeap.empty()) {
                int freq = maxHeap.top() - 1;
                maxHeap.pop();
                
                // If the task still has instances left, send it to cooldown
                if (freq > 0) {
                    cooldownQueue.push({freq, time + n});
                }
            }

            // Check if any task in the cooldown queue is ready to be re-added to the max-heap
            if (!cooldownQueue.empty() && cooldownQueue.front().second == time) {
                maxHeap.push(cooldownQueue.front().first);
                cooldownQueue.pop();
            }
        }

        return time;
    }
};