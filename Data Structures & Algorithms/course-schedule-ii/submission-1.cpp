class Course {
public:
    int prereqs;
    vector<int> prereq_for;

    Course(): prereqs(0) {}
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //process the list of prerequisites & build graph: O(E) time
        //1. in every course, track every other course that the course is a prereq for: O(E) space
        //2. store a counter to track how many electives have yet to be completed for a course
        vector<Course> courses(numCourses);
        for (const vector<int>& prereq : prerequisites) {
            int a = prereq.at(0);
            int b = prereq.at(1);
            courses[a].prereqs++;
            courses[b].prereq_for.push_back(a);
        }

        //iterate through every course, find courses that have no prereqs, add to queue: O(V)
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (courses[i].prereqs == 0) {
                q.push(i);
            }
        }

        //run multi-source bfs, every course processed can be taken without having taken any other untaken courses, add course to vector O(E)
        vector<int> res;
        vector<bool> added(numCourses);
        while (!q.empty()) {
            int n = q.front();
            q.pop();

            Course& c = courses[n];
            if (c.prereqs != 0 || added[n]) {
                continue;
            }

            res.push_back(n);
            added[n] = true;
            for (int i : c.prereq_for) {
                courses[i].prereqs--;
                q.push(i);
            }
        }

        for (int i : res) {
            cout << i << ' ';
        }

        //check if result contains numCourses elements, if it does return res, else return empty vector
        return res.size() == numCourses ? res : vector<int>{};
    }
};
