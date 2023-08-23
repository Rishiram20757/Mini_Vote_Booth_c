#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 10

struct Candidate {
    char name[50];
    int votes;
};

void displayCandidates(struct Candidate candidates[], int numCandidates) {
    printf("Candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("- %s\n", candidates[i].name);
    }
}

void displayVoteCounts(struct Candidate candidates[], int numCandidates) {
    printf("Vote Counts:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("- %s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    struct Candidate candidates[MAX_CANDIDATES];
    int numCandidates = 0;
    int choice;

    printf("Voting Management System\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Vote for your favorite Candidate\n");
        printf("2. Check the number of votes of each Candidate\n");
        printf("3. Check the candidate who is leading and then Exit\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the program.\n");
            break;
        } else if (choice == 1) {
            if (numCandidates == 0) {
                printf("No candidates available. Please add candidates first.\n");
                continue;
            }

            printf("Choose a candidate by entering the corresponding number:\n");
            displayCandidates(candidates, numCandidates);

            int candidateIndex;
            scanf("%d", &candidateIndex);

            if (candidateIndex >= 1 && candidateIndex <= numCandidates) {
                candidates[candidateIndex - 1].votes++;
                printf("Vote for %s recorded.\n", candidates[candidateIndex - 1].name);
            } else {
                printf("Invalid candidate choice.\n");
            }
        } else if (choice == 2) {
            displayVoteCounts(candidates, numCandidates);
        } else if (choice == 3) {
            if (numCandidates == 0) {
                printf("No candidates available. Please add candidates first.\n");
                continue;
            }

            int maxVotes = -1;
            int maxVotesCandidateIndices[MAX_CANDIDATES];
            int numMaxVotesCandidates = 0;

            for (int i = 0; i < numCandidates; i++) {
                if (candidates[i].votes > maxVotes) {
                    maxVotes = candidates[i].votes;
                    numMaxVotesCandidates = 1;
                    maxVotesCandidateIndices[0] = i;
                } else if (candidates[i].votes == maxVotes) {
                    maxVotesCandidateIndices[numMaxVotesCandidates] = i;
                    numMaxVotesCandidates++;
                }
            }

            if (numMaxVotesCandidates == 0) {
                printf("No winner. There are no candidates.\n");
            } else if (numMaxVotesCandidates == 1) {
                printf("Leading candidate: %s\n", candidates[maxVotesCandidateIndices[0]].name);
            } else {
                printf("No winner. There is a tie.\n");
            }
        } else {
            printf("Invalid choice. Please choose a valid option.\n");
        }
    }

    return 0;
}
