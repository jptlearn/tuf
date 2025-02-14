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
  int maxLimit = INT_MIN;
  for (const Job& job : jobs)
  {
    int temp = job.deadline;
    if (job.deadline > maxLimit)
    {
      maxLimit = temp;
    }
  }
  return maxLimit;
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

int jogSequence(vector<Job> jobs) {
  // Sort the jobs in descending order of profit
  sort(jobs.begin(), jobs.end(), compare);

  int maxDeadline = 0;
  for (const Job& job: jobs) {
    if(job.deadline > maxDeadline) {
      maxDeadline = job.deadline; // Find the maximum deadline
    }
  }

  vector<int> jobSlot(maxDeadline, -1); // Initializing the job slots
  int totalProfit = 0;

  // Iterate through each job
  for (const Job& job: jobs){
    // Find a free slot for this job
    for (int j = min(maxDeadline, job.deadline) - 1; j >= 0; j--) {
      if (jobSlot[j] == -1) {
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