class Twitter {
public:
    int ts;
    unordered_map<int, unordered_set<int>> followees;
    unordered_map<int, vector<vector<int>>> user_tweets;

    Twitter(): 
    ts(0)
    {}
    
    void postTweet(int userId, int tweetId) {
        followees[userId].insert(userId);
        user_tweets[userId].push_back({ts, tweetId});
        ts++;
    }
    
    vector<int> getNewsFeed(int userId) {
        auto comp = [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> feed(comp);
        for (int followeeId : followees[userId]) {
            if (user_tweets[followeeId].size() > 0) {
                const vector<vector<int>>& tweets = user_tweets[followeeId];
                int index = tweets.size() - 1;
                feed.push({tweets[index][0], tweets[index][1], followeeId, index});
            }
        }

        vector<int> res;
        while (!feed.empty() && res.size() < 10) {
            const vector<int>& tweet = feed.top();
            res.push_back(tweet[1]);
            int index = tweet[3]-1;
            int followeeId = tweet[2];
            if (index >= 0) {
                const vector<int>& next_tweet = user_tweets[followeeId][index];
                feed.push({next_tweet[0], next_tweet[1], followeeId, index});
            }
            feed.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        followees[followerId].erase(followeeId);
    }
};
