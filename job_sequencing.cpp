#include<bits/stdc++.h>
using namespace std;

struct job {
    int d;
    int p;
};

bool compare(job a, job b) {
    return a.p > b.p;
}

int empty_location(vector<int>& arr, int n) {
    while (n >= 1) {
        if (arr[n] == 0) {
            return n;
        }
        n--;
    }
    return -1;
}

int main() {
    int n; // no of jobs
    cin >> n;
    vector<job> jobs(n);
    for(int i = 0; i < n; i++) {
        cin >> jobs[i].p >> jobs[i].d;
    }
    sort(jobs.begin(), jobs.end(), compare);
    int max_deadline = 0;
    for(int i = 0; i < n; i++) {
        if(jobs[i].d > max_deadline)
            max_deadline = jobs[i].d;
    }
    vector<int> duration(max_deadline + 1, 0);
    int profit = 0;
    for(int i = 0; i < n; i++) {
        int x = empty_location(duration, jobs[i].d);
        if (x != -1) {
            duration[x] = 1;
            profit += jobs[i].p;
        }
    }
    cout << profit << endl;
    return 0;
}
