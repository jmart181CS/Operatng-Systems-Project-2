// Johnny Martino
// Banker's Algorithm
#include <iostream>

int main() {
    int n = 5; // Number of processes (rows)
    int m = 3; // Number of resources (columns)

    // Allocation Matrix
    int alloc[5][3] = { { 0, 1, 0 },   // P0 
                        { 2, 0, 0 },   // P1
                        { 3, 0, 2 },   // P2
                        { 2, 1, 1 },   // P3
                        { 0, 0, 2 } }; // P4

    // Max Matrix
    int max[5][3] =   { { 7, 5, 3 },   // P0 
                        { 3, 2, 2 },   // P1
                        { 9, 0, 2 },   // P2
                        { 2, 2, 2 },   // P3
                        { 4, 3, 3 } }; // P4

    // Available Resources
    int avail[3] =      { 3, 3, 2 }; 

    int tracker[n];
    int answer[n];
    int seq = 0;
    //initializing tracker
    for (int i = 0; i < n; i++)
        tracker[i] = 0;
    //populating need matrices by taking the allocation matrix - the max matrix
    int need[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    //scans through the numbers of the need matrix and compares them to the available resources. If all of the need variables are less than the available variables, then the corresponding process is next in the sequence and is placed in answer in place seq.
    //After the next corresponding process has been found, the allocation matrix to that process is added to the available matrix before continuing with the next iteration. This process continues until a sequence is found.
    //The tracker array is also set to 1 every time the next part of the sequence is found to ensure no extra work is being conducted on subsequent loops.
    for (int loop = 0; loop < n; loop++) {
        for (int i = 0; i < n; i++) {
            if (tracker[i] == 0) {
                bool check = false;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        check = true;
                        break;
                    }
                }
                if (!check) {
                    answer[seq++] = i;
                    for (int j = 0; j < m; j++)
                        avail[j] += alloc[i][j];
                    tracker[i] = 1;
                }
            }
        }
    }

        bool check = true;
        // Checks if found sequence is safe (complete) using tracker, and prints if so. For this specific case, the correct sequence will be P1, P3, P4, P0, P2
        for (int i = 0; i < n; i++) {
            if (tracker[i] == 0) {
                check = false;
                std::cout << "The sequence is not safe." << std::endl;
                break;
            }
        }

        if (check) {
            std::cout << "The sequence is safe! Printing found sequence..." << std::endl;
            for (int i = 0; i < n - 1; i++)
                std::cout << "P" << answer[i] << ", ";
            std::cout << "P" << answer[n - 1] << std::endl;
        }
}