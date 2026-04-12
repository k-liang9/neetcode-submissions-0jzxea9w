class Course {
public:
    vector<int> adjacencies;
    int prereqs;

    Course() : prereqs(0) {}
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<Course> courses(numCourses);

        for (const vector<int>& prereq : prerequisites) {
            courses[prereq.at(1)].adjacencies.push_back(prereq.at(0));
            courses[prereq.at(0)].prereqs++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (courses[i].prereqs == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int course_num = q.front();
            q.pop();

            if (courses[course_num].prereqs > 0) {
                continue;
            }

            for (int adj : courses[course_num].adjacencies) {
                q.push(adj);
                courses[adj].prereqs--;
            }
        }

        for (Course& course : courses) {
            cout << course.prereqs << '\n';
            if (course.prereqs != 0) {
                return false;
            }
        }
        
        return true;
    }
};
