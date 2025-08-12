class Twitter {
public:
    struct Tweet{
        int tweetId;
        int createdAt;
        Tweet(int id,int timestamp){
            tweetId=id;
            createdAt=timestamp;
        }
    }; 

    struct comp{
        bool operator()(const Tweet &a, const Tweet &b){
            return a.createdAt > b.createdAt; // minheap - smalle integer have more prioity
        }
    };

    int timeStamp;
    unordered_map<int,unordered_set<int>>followMp;
    unordered_map<int,vector<Tweet>>tweetsList;

    Twitter() {
       timeStamp = 1;
    }
    
    void postTweet(int userId, int tweetId) {// o(1)
        follow(userId,userId); 
        Tweet twt(tweetId,timeStamp);
        timeStamp++;
        tweetsList[userId].push_back(twt);
    }
    
    vector<int> getNewsFeed(int userId) { // get 10 recent posts only o(N)
        vector<int> result;
        priority_queue<Tweet, vector<Tweet>,comp>pq;
        auto followingList = followMp[userId];
        if(followingList.empty()) return result;
        for(int followee: followingList){ // go to all followee tweets
            if(!followee) continue;
            for(Tweet t: tweetsList[followee]){
                pq.push(t);
                if(pq.size()>10) pq.pop();
            }
        }
        while(!pq.empty()){
            result.push_back(pq.top().tweetId);
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    void follow(int followerId, int followeeId) { // o(1)
        followMp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) { // o(1)
        // i dont want to unfollow myself because i want to get my tweets in my feed
        if(followerId==followeeId) return ; 
        // check if the followerId exists
        if(followMp.count(followerId)>0){
            auto followingList = followMp[followerId];
            // check if the followee is present to unfollow
            auto itr = find(followingList.begin(),followingList.end(),followeeId);
            if(itr!=followingList.end()){ //present
               followMp[followerId].erase(followeeId);
            }
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */