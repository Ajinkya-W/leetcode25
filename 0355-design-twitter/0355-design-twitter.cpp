class Twitter {
private:
    unordered_map<int, unordered_set<int>> userFollowing; // Stores followers
    unordered_map<int, vector<pair<int, int>>> userTweets; // Stores tweets {time, tweetId}
    const int LIM = 10;
    int counter;
public:
    Twitter() : counter(0) {}

    // O(1)
    void postTweet(int userId, int tweetId) {
        userTweets[userId].emplace_back(counter++, tweetId);
    }

    // O(1)
    void follow(int followerId, int followeeId) {   
        userFollowing[followerId].insert(followeeId);
    }
    
    // O(1)
    void unfollow(int followerId, int followeeId) {
        userFollowing[followerId].erase(followeeId);
    }

    vector<int> getNewsFeed(int userId) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> tweets;
    userFollowing[userId].insert(userId);
    for (auto &followerId : userFollowing[userId]) {
        int bound = max(0, (int)userTweets[followerId].size() - LIM);
        for (int i = userTweets[followerId].size() - 1; i >= bound; i--) {
            auto& tweet = userTweets[followerId][i];
            if (tweets.size() < LIM) {
                tweets.emplace(tweet);
            } else if (tweet.first > tweets.top().first) {
                tweets.pop();
                tweets.emplace(tweet);
            } else continue;
        }
    }
    vector<int> feed(tweets.size());
    for (int i = feed.size() - 1; i >= 0; i--) {
        feed[i] = tweets.top().second;
        tweets.pop();
    }
    return feed;
}
};