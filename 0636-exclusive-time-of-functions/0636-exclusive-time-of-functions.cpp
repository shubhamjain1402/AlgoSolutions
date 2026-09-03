class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector <int> ans(n,0);
        stack <int> st;

        int prevtime=0;
        for(string &log : logs){
            int firstcolon =  log.find(':');
            int secondcolon = log.find(':',firstcolon+1);

            int process=stoi(log.substr(0,firstcolon));
            string type =log.substr(firstcolon+1,secondcolon - firstcolon -1);
            int tim=stoi(log.substr(secondcolon+1));

            if(type == "start"){
                if(!st.empty()){
                    ans[st.top()]+=tim-prevtime;
                }
                st.push(process);
                prevtime=tim;
            }
            else{
                 if(!st.empty()){
                    ans[st.top()]+=tim-prevtime+1;
                 }
                 st.pop();
                 prevtime=tim+1;
            }
        }
        return ans;   
    }
};