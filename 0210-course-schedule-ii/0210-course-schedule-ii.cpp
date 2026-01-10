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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adjGraph(numCourses);

        buildGraph(prerequisites, numCourses, inDegree, adjGraph);

        queue<int> coursesQ;
        vector<int> courseOrder;

        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                coursesQ.push(i);
            }
        }

        while(!coursesQ.empty()){
            int currCourse = coursesQ.front();
            coursesQ.pop();
            courseOrder.push_back(currCourse);
            for(auto neighbour: adjGraph[currCourse]){
                inDegree[neighbour]--;
                if(inDegree[neighbour] == 0){
                    coursesQ.push(neighbour);
                }
            }
        }
        
        return courseOrder.size() != numCourses? vector<int>(): courseOrder;
    }
};