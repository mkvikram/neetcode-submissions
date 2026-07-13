class Twitter {
    int time;
    // user -> time,post
    unordered_map<int,vector<pair<int,int>>>user;
    unordered_map<int,unordered_set<int>>user_friend;
public:
    
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        user[userId].push_back({time++,tweetId}); // time ,post
    }
    
    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int,int>>pq; // time stamp base pe max phle
        // pair ke fist element ke basis pe ye select krega max bale upr
        // usi basis pe hm second ko fetch krke return kr denge

        for(auto time_post:user[userId])
        {
            pq.push(time_post);
        }
        // pushing all those follower post also
        for(auto x_userId : user_friend[userId]){
            for(auto follower_post : user[x_userId] )
            {
                pq.push(follower_post);
            }
        }

        // pq automatically arjest post with latest timestamp
        // so will fetch 10 out of pq.size() or till pq.size)
        vector<int>top_posts;
        int count=0;
        while(pq.size() && count<10)
        {
            
            top_posts.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return top_posts;
    }
    
    void follow(int followerId, int followeeId) {

        if(followerId!=followeeId){// khud ko folllow nhi kr rha h
          user_friend[followerId].insert(followeeId);         
        }
    }
    
    void unfollow(int followerId, int followeeId) {
         user_friend[followerId].erase(followeeId);
    }
};
