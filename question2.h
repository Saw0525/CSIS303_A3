
#include <vector>
using namespace std;

// Recursive function to find the last occurrence of the target
int linear_search(const vector<int> &items, int target, size_t pos_first, int pos_last) {
    if (pos_first == items.size())
        return pos_last; // Base case: Return the most recent match, or -1 if none

    if (items[pos_first] == target) 
        pos_last = pos_first; // Update the last found index

    return linear_search(items, target, pos_first + 1, pos_last);//recursive call
}

// Wrapper function
int find_last_occurrence(const vector<int> &items, int target) {
    return linear_search(items, target, 0, -1); // Start from index 0
}