#include <iostream>
#include <vector>
#include <set>

using namespace std;

void combineMeasurements (vector<int> &res, vector<int> &vec, vector<int> &vec2, set<int> &values);

int main() {
    vector<int> res, a, b;
    set<int> s;

    a.clear();
    b.clear();
    s.clear();

    a.push_back(1);
    a.push_back(2);

    s.insert(3);
    s.insert(4);

    b.push_back(5);

    res.clear();
    combineMeasurements(res,a,b,s);
    for (std::vector<int>::const_iterator elem = res.begin(); elem != res.end(); ++elem){
        std::cout << *elem << ' ';

    }
    return 0;
}
void addSetToVector (vector<int> &res, set<int> &values){
    copy(values.begin(), values.end(), std::back_inserter(res));
}

void addVectorToVector (vector<int> &res, vector<int> &values){
    copy(values.begin(), values.end(), std::back_inserter(res));
}
void combineMeasurements (vector<int> &res, vector<int> &vec, vector<int> &vec2, set<int> &values){
    addVectorToVector (res,vec);
    addSetToVector(res,values);
    addVectorToVector (res,vec2);
}
