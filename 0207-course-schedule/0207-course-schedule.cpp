class Solution {
private:
    void buildGraph(vector<vector<int>>& prerequisites, const int numCourses, vector<int> &inDegree, vector<vector<int>>& adjGraph){
        for(const auto& relation: prerequisites){
            adjGraph[relation[1]].push_back(relation[0]);
            inDegree[relation[0]]++;
        }
        return;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adjGraph(numCourses);

        buildGraph(prerequisites, numCourses, inDegree, adjGraph);
        
        queue<int> coursesQ;
        int seenCourses = 0;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                coursesQ.push(i);
                seenCourses++;
            }
        }

        while(!coursesQ.empty()){
            int currCourse = coursesQ.front();
            coursesQ.pop();
            for(auto neighbour: adjGraph[currCourse]){
                inDegree[neighbour]--;
                if(inDegree[neighbour] == 0){
                    coursesQ.push(neighbour);
                    seenCourses++;
                }
            }
        }
        if(seenCourses != numCourses){
            return false;
        }
        return true;
    }
};