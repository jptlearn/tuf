#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Job {
  char id; // Job ID
  int deadline; // Deadline of job
  int profit; // Profit from the jog
};

bool compare(Job A, Job B){
  return A.profit > B.profit;
}

int maxDeadline(vector<Job> jobs) {
  int maxDeadline = 0;
  for (const Job& job: jobs) {
    maxDeadline = max(maxDeadline, job.deadline);
  }
  return maxDeadline;
}

int jobSequence(vector<Job> jobs) {
  sort(jobs.begin(), jobs.end(), compare);
  int maxDeadlineLimit = maxDeadline(jobs);
  int totalProfit = 0;
  vector<int> jobSlot(maxDeadlineLimit, -1);
  for (const Job &job : jobs) {
    for (int j = job.deadline - 1; j >= 0; j--) {
      if(jobSlot[j] == -1 ) {
        jobSlot[j] = job.id;
        totalProfit += job.profit;
        break;
      }
    }
  }
  return totalProfit;
}

int main() {
  vector<Job> jobs = {{'A', 3, 35}, {'B', 4, 30}, {'C', 4, 25}, {'D', 2, 20}, {'E', 3, 15}, {'F', 1, 12}, {'G', 2, 5}};

  cout << "Maximum profit in the job sequencing problem is: " << jobSequence(jobs) << endl;

  return 0;
}