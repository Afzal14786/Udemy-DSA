#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

const int NUM_SUBJECTS = 3; // Assuming 3 subjects in the exam

class Candidate {
public:
    int id;
    std::vector<int> marks;
    int totalMarks;
    int rank;

    Candidate(int _id, const std::vector<int>& _marks) 
        : id(_id), marks(_marks), totalMarks(0), rank(0) {
        for (int mark : marks) {
            totalMarks += mark;
        }
    }
};

bool compareCandidate(const Candidate& a, const Candidate& b) {
    if (a.totalMarks != b.totalMarks) {
        return a.totalMarks > b.totalMarks; // Higher total marks get better rank
    }
    // If total marks are equal, compare subject-wise
    for (int i = 0; i < NUM_SUBJECTS; ++i) {
        if (a.marks[i] != b.marks[i]) {
            return a.marks[i] > b.marks[i];
        }
    }
    return a.id < b.id; // If all else is equal, lower ID gets better rank
}

void assignRanks(std::vector<Candidate>& candidates) {
    std::sort(candidates.begin(), candidates.end(), compareCandidate);
    
    int currentRank = 1;
    for (int i = 0; i < candidates.size(); ++i) {
        if (i > 0 && compareCandidate(candidates[i-1], candidates[i])) {
            currentRank = i + 1;
        }
        candidates[i].rank = currentRank;
    }
}

void displayResults(const std::vector<Candidate>& candidates) {
    std::cout << std::left << std::setw(5) << "Rank" 
              << std::setw(10) << "ID" 
              << std::setw(15) << "Total Marks";
    for (int i = 1; i <= NUM_SUBJECTS; ++i) {
        std::cout << std::setw(10) << "Subject " + std::to_string(i);
    }
    std::cout << std::endl;
    std::cout << std::string(60 + NUM_SUBJECTS*10, '-') << std::endl;

    for (const auto& candidate : candidates) {
        std::cout << std::left << std::setw(5) << candidate.rank 
                  << std::setw(10) << candidate.id 
                  << std::setw(15) << candidate.totalMarks;
        for (int mark : candidate.marks) {
            std::cout << std::setw(10) << mark;
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<Candidate> candidates;
    int numCandidates;

    std::cout << "Enter the number of candidates: ";
    std::cin >> numCandidates;

    for (int i = 0; i < numCandidates; ++i) {
        int id;
        std::vector<int> marks(NUM_SUBJECTS);

        std::cout << "Enter details for candidate " << i+1 << ":\n";
        std::cout << "ID: ";
        std::cin >> id;

        for (int j = 0; j < NUM_SUBJECTS; ++j) {
            std::cout << "Marks for Subject " << j+1 << ": ";
            std::cin >> marks[j];
        }

        candidates.emplace_back(id, marks);
    }

    assignRanks(candidates);
    displayResults(candidates);

    return 0;
}