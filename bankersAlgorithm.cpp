// Banker's Algorithm
#include <iostream>

int main()
{
    // P0, P1, P2, P3, P4 are the Process names here

    int n = 5; // Number of processes
    int m = 3; // Number of resources
    int alloc[5][3] = { { 0, 1, 0 }, // P0 // Allocation Matrix
                       { 2, 0, 0 }, // P1
                       { 3, 0, 2 }, // P2
                       { 2, 1, 1 }, // P3
                       { 0, 0, 2 } }; // P4

    int max[5][3] = { { 7, 5, 3 }, // P0 // MAX Matrix
                     { 3, 2, 2 }, // P1
                     { 9, 0, 2 }, // P2
                     { 2, 2, 2 }, // P3
                     { 4, 3, 3 } }; // P4

    int avail[3] = { 3, 3, 2 }; // Available Resources

    int f[n];
    int ans[n];
    int ind = 0;
    for (int i = 0; i < n; i++)
        f[i] = 0;
    int need[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                        }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (int y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

        int check = 1;
        // To check if sequence is safe or not
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) {
                check = 0;
                std::cout << "The given sequence is not safe";
                break;
            }
        }

        if (check == 1) {
            std::cout << "Following is the SAFE Sequence" << std::endl;
            for (int i = 0; i < n - 1; i++)
                std::cout << " P" << ans[i] << " ->";
            std::cout << " P" << ans[n - 1] << std::endl;
        }

        return (0);
}