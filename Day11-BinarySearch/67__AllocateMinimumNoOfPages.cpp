// Time Complexity - O(nlogn)
// Space Complexity - O(1)

bool isPossible(vector<int> &A, int mx, int students) {
    int n = 1, sum = 0;
    for(int pages : A) {
        if(pages > mx)
            return false;
        if(sum+pages > mx) {
            ++n;
            sum = pages;
            if(n > students)
                return false;
        }
        else
            sum += pages;
    }
    return true;
}
int Solution::books(vector<int> &A, int B) {
    int n = A.size();

    // If no. of books is less than no. of student
    // then it isn't possible to assign books to all students
    if(n < B)
        return -1;
    
    int low = 1, high = INT_MAX, ans = INT_MAX;

    while(low <= high) {
        int mid = (low+high)/2;

        if(isPossible(A, mid, B)) {
            ans = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return ans;
}