# 6466Assignment2
Finding a parking spot during semester time is a big problem at UNA, and Mr ParkingPls is determined to address this problem. To this end, he observes that the difficulty in finding a parking spot is worst on a certain day of the week and a certain time on that day. He hypothesises that the main culprit of the worst parking problem is that there is an extremely large number of overlapping lecture sessions on that particular day and time. If this is true, he can recommend that UNA either redistribute the lecture slots more evenly during the week or rent a nearby land on the particular day and time each week to expand its parking capacity.
Of course first, Mr ParkingPls must test his hypothesis. To this end, he has obtained the schedule of all lectures at UNA. Since all classes at UNA either starts or ends at the beginning of an hour or half an hour, Mr ParkingPls simplifies the lecture sessions representation by creating a time index for every half-hour between 06:00 and 20:00 (inclusive) within a week —that is, time-1 refers to Monday 06:00, time-2 refers to Monday 06:30, · · ·, time-145 refers to Friday 20:00—. He then represents each lecture session as a half-open interval of time index, e.g., interval [3, 5) means the lecture starts on Monday 07:00 end ends (at a negligible amount) before Monday 08:00. The question is now to find the time index with the most number of overlapping lecture sessions. Now, since he has only limited knowledge about Algorithms, he asks your help.

Your tasks
1. [15 pts] Mr ParkingPls is convinced that to find the time index with the most overlapping lecture sessions, one only needs to find overlaps between time indices at the beginning or end of the intervals, rather the entire time index. The question is:
(a) [5 pts] Is Mr ParkingPls correct?
(b) [10 pts] If Mr ParkingPls is correct, please support your answer with a proof. Otherwise, please provide a counter-example.
2. [45 pts] Since Mr ParkingPls would like to use this work for other much larger projects where new sessions can be added quite often, Mr ParkingPls would like to use Red-Black Tree and asked your help. To help him, please:
(a) [10 pts] Design a suitable Red-Black Tree data structure for Mr ParkingPls’ problem. This means that given a Red-Black Tree implementation as defined in [CLRS] ch. 13, how you would use/augment/modify this underlying data structure for Mr ParkingPls problem. Hint: You might want to read [CLRS] sec. 14.3 first (provided as additional resources to this assignment).
(b) [5 pts] Please provide an algorithm with O(log n) complexity for inserting a node to the tree you have designed in 2a, along with the derivation of its complexity results. The notation n refers to the number of nodes that are already in the tree prior to insertion. For the algorithm, you can use the insertion procedure of Red-Black Tree in [CLRS] ch. 13 as a basis and stated only the modifications needed, if alterations are needed. If no alteration is needed, please explain why.
(c) [15 pts] Please provide an algorithm for finding the time index with the largest number of overlapping lecture sessions in the red-black tree you designed. Please also provide the correctness proof (using loop invariant) and the time complexity (with its derivation) of your algorithms. You will get full mark if the time complexity of your algorithm is O(1) and at most 9 points if the time complexity of your algorithm is O(log n), where n is the number of lecture sessions. Please note that in this question:
• You can only use red-black tree data structure
• You need to assume that the maximum time index is a variable (i.e., the complexity requirement should still hold if the maximum time index is a variable k, which is given as input, rather than 145) because, Mr ParkingPls would like to use the algorithm for other parking issues
(d) [15 pts] Please implement the above solution such that the user can find the time index by giving the command “A2[studentID] input file name” OR “java A2[studentID] input file name” from the command prompt. The input format is described in the next section. We provide you with a main.cpp and a scaf- folding for Red-Black Tree. If you use C/C++, you need to implement the node insertion function and the algorithm you provided in 2c on top of the provided main function and Red-Black Tree scaffolding.
If you use java, you need to make sure that your java program accepts the same input as the provided main.cpp . You also need to develop Red-Black Tree yourself. If you choose this path, you might want to first check which operations of Red-Black Tree you need for this assignment and implement only those operations. Note: You are not allowed to use TreeMap or other Java Red-Black Tree library.
Program Marking: If your program compiles and runs, you will get 3 points. We will then run your program on 6 test cases: 2 cases would have up to 5,000 sessions, 2 cases would have 5,001 – 500,000 sessions, and 2 cases would have 500,001 – 5,000,000 sessions. For each test case, your program will begiven a total of (log n + 0.01)sec CPU time to find a solution. This time limit includes the time for reading the file, inserting the data to the red-black tree, finding the solution, and printing the solution. The time limit will be rounded up to 2 decimal digit. You can assume your program will have access to at most 12GB RAM. It will be run as a single thread process on a computer with Intel i7 3.4GHz processor. For each test case that your program solves correctly within the given time and memory limit, you will get 2 points.
Examples of the test cases are available in https://cs.anu.edu.au/courses/comp3600/a2-testCases.zip.

Input to the Program
The program will accept a single argument, which is the name of the input file. The input file contains N + 1 lines, where N is the number of lecture session intervals.
The first line consists of a single number, which is N.
Each line in the next N lines consists of three numbers, separated by a white space. The first number is the session ID, the second number is starting time index, and the third number is the ending time index.
The session ID is sorted, in the sense that ID-i would be in line-(i + 1). Example:
5
1 96 101
2 46 49
3 76 77
4 8 10
5 4 10
Output of the Program
The program outputs two lines to the standard output stream (i.e., use cout if you use C++).
The first line contains two numbers, each separated by a white space. The first number is the time index with the most number of overlapping lecture sessions. Let’s denote this time index as t. The second number (denoted as K) is the number of lecture sessions that overlap with time index t.
The second line consists of K numbers sorted in ascending order, each separated by a white space. Each number in this line is the ID of the session that overlaps with time index t.
Example output for the above input: 82
45
