#include<bits/stdc++.h>
using namespace std;

int activities(vector<int> S, vector<int> F) {

    int len = S.size();

    if(len==0)
        return 0;
    
    set<pair<int,int> > activities;
    map<pair<int,int>, int > activity_ind;

    for(int i=0;i<len;i++) {

    	pair<int, int> curr_activity = make_pair(S[i],F[i]);
        activities.insert(curr_activity);
        activity_ind[curr_activity] = i+1;
    }

    int prevEnd = INT_MIN, prevStart = INT_MIN;
    int count = 0;
    stack<int> sol;

    for(set<pair<int,int> >:: iterator it=activities.begin(); it!=activities.end(); it++) {

        int currStart = it->first, currEnd = it->second;
    	pair<int, int> curr_activity = make_pair(currStart, currEnd);
        
        if(currStart > prevEnd) {
            sol.push(activity_ind[curr_activity]);
            prevStart = currStart;
            prevEnd = currEnd;
            count++;
        }
        
        else if(currStart <= prevEnd) {
        	
            if(currEnd <= prevEnd ) {

			    sol.pop();
                sol.push(activity_ind[curr_activity]);
                prevStart = currStart;
            	prevEnd = currEnd;
            }
        }
    }
    
    stack<int> solution;
    while(!sol.empty()) {
        solution.push(sol.top());
        sol.pop();
    }
    
    while(!solution.empty()) {

    	int curr = solution.top();
        solution.pop();
        printf("%d ", curr);
	}
    cout<<endl;
    return count;
}

int main()
 {
	int T;
	scanf("%d",&T);
	while(T--) {
	    int n;
	    scanf("%d",&n);
	    vector<int> S,F;
	    int curr;
	    for(int i=0;i<n;i++) {
	        cin>>curr;
	        S.push_back(curr);
	    }
	    for(int i=0;i<n;i++) {
	        cin>>curr;
	        F.push_back(curr);
	    }
	    int count = activities(S,F);
	}
	return 0;
}
