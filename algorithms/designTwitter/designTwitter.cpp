/**
 *
 * Sean
 * 2017-01-05
 *
 * https://leetcode.com/problems/design-twitter/
 *
 * Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:
 * 
 * postTweet(userId, tweetId): Compose a new tweet.
 * getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
 * follow(followerId, followeeId): Follower follows a followee.
 * unfollow(followerId, followeeId): Follower unfollows a followee.
 * Example:
 * 
 * Twitter twitter = new Twitter();
 * 
 * // User 1 posts a new tweet (id = 5).
 * twitter.postTweet(1, 5);
 * 
 * // User 1's news feed should return a list with 1 tweet id -> [5].
 * twitter.getNewsFeed(1);
 * 
 * // User 1 follows user 2.
 * twitter.follow(1, 2);
 * 
 * // User 2 posts a new tweet (id = 6).
 * twitter.postTweet(2, 6);
 * 
 * // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
 * // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
 * twitter.getNewsFeed(1);
 * 
 * // User 1 unfollows user 2.
 * twitter.unfollow(1, 2);
 * 
 * // User 1's news feed should return a list with 1 tweet id -> [5],
 * // since user 1 is no longer following user 2.
 * twitter.getNewsFeed(1);
 *
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

// heap
class Twitter {
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> followees;
    int timestamp;
public:
    /** Initialize your data structure here. */
    Twitter() {
        timestamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, ++timestamp});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> feeds;
        unordered_map<int, int> indexes;
        
        // pair { userId, next new tweet timestamp }
        auto cmp = [](const pair<int, int> &p1, const pair<int, int> &p2) {
            return p1.second < p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> aQueue(cmp);
        
        int size = tweets[userId].size();
        int cnt = size;
        indexes[userId] = size-1;
        if (size>0) aQueue.push({userId, tweets[userId][size-1].second});

        for(auto &follower : followees[userId]) {
            size = tweets[follower].size();
            indexes[follower] = size -1;
            cnt += size;
            if (size>0) aQueue.push({follower,  tweets[follower][size-1].second});
        }

        for (int i=0; i<min(10, cnt); ++i) {
            auto aPair = aQueue.top();
            aQueue.pop();
            int curId = aPair.first;
            feeds.push_back(tweets[curId][indexes[curId]].first);
            if (--indexes[curId] >= 0) {
                aPair.second = tweets[curId][indexes[curId]].second;
                aQueue.push(aPair);
            }
        }
        return feeds;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followees[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followees[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

void printVec(const vector<int> &iVec) {
    for (auto &i : iVec) cout << i << " ";
    cout << endl;
}

int main() {
    Twitter twitter;
    twitter.postTweet(1,5);
    printVec(twitter.getNewsFeed(1));
    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    printVec(twitter.getNewsFeed(1));
    twitter.unfollow(1, 2);
    printVec(twitter.getNewsFeed(1));
    return 0;
}
