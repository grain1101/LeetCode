#include "leetcode.h"

// 355. Design Twitter
struct tweet{
        int tweetId;
        int userId;
        int time;
};
bool cmp(const tweet& a, const tweet& b){
    return a.time < b.time;
}

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        cout << "user " << userId <<"  postTweet " << tweetId << endl;
        follow(userId, userId);
        const unordered_set<int>& follower = followers[userId];
        for(auto f : follower){
            tweet feed;
            feed.userId = userId;
            feed.tweetId = tweetId;
            feed.time = time++;
            newsFeed[f].push_back(feed);
        }
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        cout << "user" << userId <<"'s news feed is: ";
        vector<int> ret;
        set<int> noDuplicate;
        vector<tweet>& news = newsFeed[userId];
        sort(news.begin(), news.end(), cmp);
        for(int i = news.size() - 1; i >= 0 && ret.size()< recentFeed;i--){
            if (noDuplicate.find(news[i].tweetId) != noDuplicate.end()) continue;
            ret.push_back(news[i].tweetId);
            noDuplicate.insert(news[i].tweetId);
        }
        return ret;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followers.find(followeeId) != followers.end() &&
            followers[followeeId].find(followerId) != followers[followeeId].end()) return;
        followers[followeeId].insert(followerId);
        const vector<tweet>& tmp = newsFeed[followeeId];
        for(auto t : tmp){
            if (t.userId == followeeId)
                newsFeed[followerId].push_back(t);
        }

        cout << "user " << followerId << " 's follower " ;
        for(auto f : followers[followerId]){
            cout << f << " ";
        }
        cout << endl;
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        //cout << "user" << followerId <<"  unfollow " << followeeId << endl;
        if (followerId == followeeId) return;
        unordered_set<int>& tmp = followers[followeeId];
        if (tmp.find(followerId) == tmp.end()) return ;
        deleteNewsFeed(followerId, followeeId);
        tmp.erase(followerId);
    }
private:
    static int time;
    const int recentFeed = 10;

    unordered_map<int, vector<tweet>> newsFeed; // int's newFeed. which include int self posts and int followed posts, sorted by time;
    unordered_map<int, unordered_set<int>> followers; // <a, b> a's followers



    void deleteNewsFeed(int followerId, int followeeId){
        vector<tweet>& news = newsFeed[followerId];
        vector<tweet> ret;
        for(auto t : news){
            if (t.userId != followeeId) ret.push_back(t);
        }
        news.swap(ret);
//        for(auto n : news){
//            cout << n.tweetId << endl;
//        }
    }
};

int Twitter::time = 0;

int main() {
    Twitter twitter;
    twitter.postTweet(1,5);
    auto user1 = twitter.getNewsFeed(1);
    showV(user1);

    twitter.follow(1,2);
    twitter.postTweet(2,6);
    user1 = twitter.getNewsFeed(1);
    showV(user1);

    twitter.unfollow(1,2);
    showV(twitter.getNewsFeed(1));


    //cout << ans << endl;
}
