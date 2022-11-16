# Operatng-Systems-Project-2

This code utilizes the banker's algorithm to determine if the matrices in the project discription are in a safe state and what that state is. The code can be run with g++ -o BA bankersAlgorithm.cpp and subsequently ./BA

# Implementation

The implemenentation of this project was significantly easier than the first project. Not having to deal with shared memory and multiple processes really streamlined things. Also, the fact that the concept of the banker's algorithm being easier to understand (for me, at least) significantly helped. However, there still were a few issues.

The hardest part was finding a way to save the order of the processes in the sequence. The actual checking of each variable in the matrices was easy, as well as changing the available resources. To solve this issue of saving the order of the processes, I created an answer array that stored the positional data of the current row that was being worked in. the answer would only save if all of the need varaibles were less than the available variables. Additionally, I implemented a tracker array that would be set to 0 initially.
But it would be set to 1 every time the next part of the sequence was found, so it eliminated any extra overhead. This tracker variable also doubled as a way to ensure that the found sequence was safe, or complete. If the sequence was complete, the answer array would output the answer in the correct order.

Overall, this lab let me learn about the Banker's Algorithm in much more detail than I would have otherwise, and was a fun little challenge to implement.
