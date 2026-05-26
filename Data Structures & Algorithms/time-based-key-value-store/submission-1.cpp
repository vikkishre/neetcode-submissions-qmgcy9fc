class TimeMap {
    unordered_map<string,vector<pair<string,int>>> mp;
    string key;
    string val;
    int timestamp;
public:
    TimeMap() {
        this->key="";
        this->val="";
        this->timestamp=0;
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        string ans;
        vector<pair<string,int>> arr=mp[key];
        int l=0,h=arr.size()-1;
        if(mp.find(key)==mp.end())
            return "";
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(arr[mid].second<=timestamp)
            {
                ans=arr[mid].first;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};
