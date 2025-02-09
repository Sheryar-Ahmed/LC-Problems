class Twitter {
private:
    unordered_map<int, unordered_set<int>> fo; // Follow relationships
    unordered_map<int, deque<pair<int, int>>> t; // Last 10 tweets per user
    long long time;

public:
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (t[userId].size() == 10) t[userId].pop_front(); // Keep only last 10 tweets
        t[userId].push_back({time++, tweetId});
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; 
        
        // Function to push tweets into the heap while maintaining a max size of 10
        auto pushTweets = [&](int uid) {
            for (auto& tweet : t[uid]) {
                minHeap.push(tweet);
                if (minHeap.size() > 10) minHeap.pop(); // Keep only top 10 latest tweets
            }
        };

        // Push user's tweets
        pushTweets(userId);
        
        // Push followees' tweets
        for (int followee : fo[userId]) {
            pushTweets(followee);
        }

        // Extract tweets from the heap in reverse order (latest first)
        vector<int> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(res.begin(), res.end()); // Convert minHeap order to latest-first
        return res;
    }

    /** Follower follows a followee. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            fo[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. */
    void unfollow(int followerId, int followeeId) {
        fo[followerId].erase(followeeId);
    }
};
