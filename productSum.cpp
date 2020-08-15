#include <any>
#include <vector>

using namespace std;

// Tip: You can use el.type() == typeid(vector<any>) to check whether an item is
// a list or an integer.
int productSum(vector<any> array, int level=1) {
    int sum = 0;
    for (auto ch:array) {
        if (ch.type()==typeid(vector<any>)) {
            sum+= productSum(any_cast<vector<any>>(ch), level+1);
        }
        else {
            sum+=any_cast<int>(ch);
        }
    }
    return sum*level;
}