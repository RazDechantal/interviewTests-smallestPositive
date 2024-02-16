balancedString.cpp  working
test02.cpp
A string is called balanced when every letter occurring in the string, appears both in upper- and lowercase. For example, the string "CATattac" is balanced ('a', 'c' and 't' occur in both cases), but "Madam" is not ('d' and 'a' appear only in lowercase). Note that the number of occurrences does not matter.
Write a function int solution(string &s);
that, given a string S of length N, returns the length of the shortest balanced fragment of S. If S does not contain any balanced fragments, the function should return -1.
Examples:
1. Given S = "azABaabza", the function should return 5. The shortest balanced fragment of S is "ABaab".
2. Given S = "TacoCat", the function should return -1. There is no balanced fragment.
3. Given S = "AcZCbaBz", the function should return 8. The shortest balanced fragment is the whole string.
4. Given S = "abcdefghijklmnopqrstuvwxyz", the function should return -1.

Assume that:
N is an integer within the range [1,200]
string S consists only of letters ('a'−'z' and/or 'A'−'Z').
In your solution, focus on "correctness". The performance of your solution will not be the focus of the assessment.
___________________________________________________________________________
minDistIndices.cpp working
Integer V lies strictly  between integers U and W if U < V < W or if U > V > W.
A non-empty array A consisting of N integers is given. A pair of indices (P, Q), where 0 ≤ P < Q < N, is said to have adjacent values  if no value in the array lies strictly between values A[P] and A[Q], and in addition A[P] ≠ A[Q].

For example, in array A such that:
  A[0] = 0
  A[1] = 3
  A[2] = 3
  A[3] = 7
  A[4] = 5
  A[5] = 3
  A[6] = 11
  A[7] = 1
the following pairs of indices have adjacent values:
  (0, 7),   (1, 4),   (1, 7),
  (2, 4),   (2, 7),   (3, 4),
  (3, 6),   (4, 5),   (5, 7).
For example, indices 4 and 5 have adjacent values because the values A[4] = 5 and A[5] = 3 are different, and there is no value in array A that lies strictly between them. The only such value could be the number 4, which is not present in the array.

Given two indices P and Q, their distance  is defined as abs(P−Q), where abs(X) = X for X ≥ 0, and abs(X) = −X for X < 0. For example, the distance between indices 4 and 5 is 1 because abs(4 − 5) = (5 − 4) = 1.

Write a function:
int solution(vector<int> &A)
that, given a non-empty array A consisting of N integers, returns the minimum distance between indices of this array that have adjacent values. The function should return −1 if no adjacent indices exist.
For example, given array A such that:
  A[0] = 1
  A[1] = 4
  A[2] = 7
  A[3] = 3
  A[4] = 3
  A[5] = 5
the function should return 2 because:
- indices 1 and 3 are adjacent because A[1] ≠ A[3] and the array does not contain any value that lies strictly between A[1] = 4 and A[3] = 3;
-  the distance between these indices is abs(1 − 3) = 2;
- no other pair of adjacent indices that has a smaller distance exists.

Write an  algorithm for the following assumptions:
- N is an integer within the range [1, 40000]
- each element of array A is an integer within the range [−2,147,483,648, 2,147,483,647]
______________________________________________________________________________________
battleship.cpp
John plays a game of battleships with his friend Sonia. The game is played on a square map of N rows, numbered from 1 to N. Each row contains N cells, labeled with consecutive English upper-case letters ('A', 'B', 'C', etc.). Each cell is identified by a string composed of its row number followed by its column number: for example, "9C" denotes the third cell in the 9th row, and "15D" denotes the fourth cell in the 15th row.
John marks the positions of all his ships on the map (which is not shown to Sonia). Ships are defined by rectangles with a maximum area of 4 cells. Sonia picks map cells to hit some ships. A ship is considered to be hit if at least one of its constituent cells is hit. If all of a ship's cells are hit, the ship is sunk.
The goal is to count the number of sunk ships and the number of ships that have been hit but not sunk.

In this example, one ship has been sunk and the other has been hit but not sunk. 

We have the following coordinates where ships are situated.
Columns = [A,B,C,D]
Rows = [1,2,3,4]
The slots which are crossed makes the data set as such:
The coordinates of the ship in a 4*4 matrix or data set 
A = { (1,A),(1,B),(1,C),(1,D),
      (2,A),(2,B),(2,C),(2,D),
      (3,A),(3,B),(3,C),(3,D),
      (4,A),(4,B),(4,C),(4,D)
}

We have two ships
Ship1 is hit at (2,B) but not sunk
Ship 2 is hit at (2,D), (3D), (4,D) and sunk

The positions of ships are given as a string S, containing pairs of positions separated with spaces, describing respectively the top-left and bottom-right corner cells of each ship. Ships' descriptions are separated with commas. The positions of hits are given as a string T, containing positions describing the map cells that were hit, separated with spaces. For the map in the example shown above, S = "1B 2C,2D 4D" and T = "2B 2D 3D 4D 4A". Ships in S and hits in T may appear in any order.

write a function
string solution(int N, string &s, string &T)
that, given the size of the map N and two strings S, T that describe the positions of ships and hits respectively, returns a string with two numbers: the count of sunken ships and the count of ships that have been hit but not sunk, separated with a comma.
Examples:
1. Given N = 4, S = "1B 2C,2D 4D" and T = "2B 2D 3D 4D 4A", your function should return "1,1", as explained above
2. Given N = 3, S = "1A 1B,2C 2C" and T = "1B", your function should return "0,1". One ship was hit but not sunk. Note that the ship in cell 2C was not hit nor sunk, therefore it is not included in the result.

3. Given N = 12, S = "1A 2A,12A 12A" and T = "12A", your function should return "1,0". One ship was sunk.

Assume that:
- N is an integer within the range [1, 26]
- string S contains the descriptions of rectangular ships of area not greater than 4 cells;
- there can be at most one ship located on any map cell (ships do not overlap);
- each map cell can appear in string T at most once;
- string S and string T contains only valid positions given in specified format.

In your solution, focus on correctness . The performance of your solution will not be the focus of the assessment.
_______________________________________________________________________________________

add5Atbeginning.cpp working
Write a function called solution that, given an integer N, returns the maximum possible value obtained by inserting one '5' digit inside the decimal representation of integer N.
Examples:
1. Given N = 268, the function should return 5268
2. Given N = 670, the function should return 5670
3. Given N = 0, the function should return 50
4. Given N = −999, the function should return −5999
______________________________________________________________________________________
generateString.cpp working
Write a function   that, given strings and  and integer , returns a string composed of the first two letters from each of name and surname followed by age. 
. For example, given  name = "John" , surname = "Firelord" and age = 8, the function should return JoFi8
______________________________________________________________________________________
signOfProduct.cpp 
Write a function that, given an array A of N integers (between −100 and 100), returns the sign (−1, 0, 1) of the product of all the numbers in the array multiplied together. Assume that N is between 1 and 1000.  For example, given A = [1, −2, −3, 5], the function should return 1 (the multiplication equals 30). 
 Given A = [1, 2, 3, −5] your function should return −1 (the multiplication equals −30). 
 Given A = [1, 2, 0, −5] your function should return 0 (the multiplication equals 0).  
______________________________________________________________________________________
alternatingChar.cpp
Write a function solution that returns a string of length N consisting of alternating characters: "+" and "-", starting with a "+" character. You can assume N is between 1 and 100.
______________________________________________________________________________________
smallestPositiveInt
A function that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
______________________________________________________________________________________
fizzbuzz.cpp
Given a number n, for each integer i in the range from 1 to n inclusive, print one value per line as follows:
If i is a multiple of both 3 and 5, print FizzBuzz.
If i is a multiple of 3 (but not 5), print Fizz.
If i is a multiple of 5 (but not 3), print Buzz.
If i is not a multiple of 3 or 5, print the value of i.
Function Description
Complete the function fizzBuzz in the editor below.
fizzBuzz has the following parameter(s):
    int n:  upper limit of values to test (inclusive)
Returns:    NONE
Prints:

    The function must print the appropriate response for each value i in the set {1, 2, ... n} in ascending order, each on a separate line.

_________________________________________________________________________________________

disk.cpp working
Task description
There are three stacks of disks. Disks on each stack are sorted by size in increasing order from the bottom to the top.

Our goal is to move all disks from these stacks onto the fourth stack, which is initially empty. In one move the top element of one of the stacks can be moved to the fourth stack. After moving all disks onto the fourth stack, they should be sorted by size in decreasing order from bottom to the top.

You are given three arrays: stack1 of N1 integers, stack2 of N2 integers, and stack3 of N3 integers. Each array represents a stack in which the elements are listed from bottom to top (i.e. the last element of the array is the top element of the stack).

Find the sequence of moves after which all the disks will be on the fourth stack, sorted by size in descending order. You may assume that there are no two disks of the same size.

For example for stack1 = [2, 7], stack2 = [4, 5] and stack3 = [1], the sequence of moves is 1−2−2−1−3:

move disk of size 7 from stack 1
move disk of size 5 from stack 2
move disk of size 4 from stack 2
move disk of size 2 from stack 1
move disk of size 1 from stack 3
After these moves the elements of the fourth stack are sorted in descending order: [7, 5, 4, 2, 1] and all other stacks are empty.

Write a function:

string solution(vector<int> &stack1, vector<int> &stack2, vector<int> &stack3);

that, given three arrays, stack1, stack2 and stack3, returns a string representing the sequence of moves which should be performed. The J-th character of the string should be the stack number (1, 2 or 3) from whose top the element should be moved in the J-th move.

Examples:

1. Given stack1 = [2, 7], stack2 = [4, 5] and stack3 = [1], the function should return "12213", as explained above.

2. Given stack1 = [10, 20, 30], stack2 = [8] and stack3 = [1], the function should return "11123".

3. Given stack1 = [7], stack2 = [] and stack3 = [9], the function should return "31".

Assume that:

N1, N2 and N3 are integers within the range [0..100];
each element of arrays stack1, stack2 and stack3 is an integer within the range [1..1,000];
disk sizes are unique, i.e. there are no two disks of the same size;
on each stack disks are sorted by size in ascending order.
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
________________________________________________________________________________
maxSumOf2Int.cpp working
Task description
There is an array A consisting of N integers. What is the maximum sum of two integers from A that share their first and last digits? For example, 1007 and 167 share their first (1) and last (7) digits, whereas 2002 and 55 do not.

Write a function:

class Solution { public int solution(int[] A); }

that, given an array A consisting of N integers, returns the maximum sum of two integers that share their first and last digits. If there are no two integers that share their first and last digits, the function should return −1.

Examples:

1. Given A = [130, 191, 200, 10], the function should return 140. The only integers in A that share first and last digits are 130 and 10.

2. Given A = [405, 45, 300, 300], the function should return 600. There are two pairs of integers that share first and last digits: (405, 45) and (300, 300). The sum of the two 300s is bigger than the sum of 405 and 45.

3. Given A = [50, 222, 49, 52, 25], the function should return −1. There are no two integers that share their first and last digits.

4. Given A = [30, 909, 3190, 99, 3990, 9009], the function should return 9918.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [10..1,000,000,000].

__________________________________________________________________
tree3.cpp working
For the problem of tree, we need solution which fullfil the following description:
A binary tree is represented as a sequence of parent-child pairs, for example:
(A,B) (A,C) (B,G) (C,H) (E,F) (B,D) (C,E)
A tree with those edges may be illustrated in many ways. 
The following is a recursive definition for the S-expression of a tree:

S-exp(node) = ( node->val (S-exp(node->first_child))(S-exp(node->second_child))), if node != NULL = "", node == NULL
where, first_child->val < second_child->val (first_child->val is lexicographically smaller than second_child-> val)

This tree can be represented in an S-expression in multiple ways. The lexicographically smallest way of expressing it is as follows:

(A(B(D)(G))(C(E(F))(H)))
Translate the node-pair representation into its lexicographically smallest S-expression or report any errors that do not conform to the definition of a binary tree.
The list of errors with their codes is as follows:
Error Code      Type of error

E1                 More than 2 children

E2                 Duplicate Edges

E3                 Cycle present (node is direct descendant of more than one node)

E4                 Multiple roots

E5                 Any other error   

Function Description 

Complete the function sExpression in the editor below. The function must return either the lexicographically lowest S-expression or the lexicographically lowest error code as a string.
sExpression has the following parameter(s):

    nodes:  a string of space-separated parenthetical elements, each of which contains the names of two connected nodes separated by a comma

Constraints:

All node names are single characters in the range ascii[A-Z]
The maximum node count is 26.
There is no specific order to the input (parent, child) pairs.
If you have not worked with trees when programming before then the following may be helpful. A tree can be stored in memory as a map from parents to each of their children. For example, if { K: V } indicates an item in a dictionary or hashmap with key K and value V, and [X, Y] indicates a list or array with elements X and Y, then the example tree could be stored as:

{

    A: [B, C]

    B: [D, G]

    C: [E, H]

    D: []

    E: [F]

    F: []

    G: []

    H: []

}



This is not the only way to store a tree, nor is it necessarily the best way in all cases, however it will be sufficient to solve the problem given to you.

Sample case:
Sample Input 0
(B,D) (D,E) (A,B) (C,F) (E,G) (A,C)
 

Sample Output 0
(A(B(D(E(G))))(C(F)))


Sample Input 1
(A,B) (A,C) (B,D) (D,C)
 
Sample Output 1
E3

The program has already the main() function as following:
nt main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nodes;
    getline(cin, nodes);

    string result = sExpression(nodes);

    fout << result << "\n";

    fout.close();

    return 0;

}

________________________________________________________________________________________
path.cpp working
For the Problem "Paths in a warehouse" we need a solution for the following problem:
A forklift worker moves products from one place to the other in an automotive parts warehouse. There a map in the dashboard that shows, in real time, the open and blocked sections inside the warehouse. The map is displayed as an n x m matrix of 1's and 0's which represent open and blocked sections respectively. A forklift driver always starts at the upper left corner of the map at warehouse[0][0] and tries to reach the bottom right section of the map or warehouse[n-1][m-1].  Each movement must be in increasing value along a row or column but not both.  Given the warehouse map, determine the number of distinct paths to get from warehouse[0][0] to warehouse[n-1][m-1].  The number may be large, so return the value modulo (109+7).
Example
warehouse = [1, 1, 0, 1], [1, 1, 1, 1]
The matrix below is drawn from the warehouse array showing open and blocked sections of the warehouse. 1 indicates an open section and 0 indicates a blocked section. It is only possible to travel through open sections, so no path can go through the section at (0, 2).

There are 2 possible paths from warehouse[0][0] to warehouse[1][3] and 2 modulo (109+7) = 2.
Function Description
Complete the function numPaths in the editor below.
numPaths has the following parameter(s):
    warehouse[n][m]:  a two dimensional array of integers of n rows and m columns

Returns:
    int: the number of paths through the matrix, modulo (109 + 7).
Constraints

1 ≤ n, m ≤ 1000
Each cell in matrix a contains either a 0 or a 1.
Input Format for Custom Testing
Input from stdin will be processed as follows and passed to the function.
The first line contains an integer n, the number of rows in the matrix warehouse.

The next line contains an integer m, the number of columns in the matrix warehouse.

The next n lines each contain a string warehouse[i] where 0 ≤ i < n and |warehouse[i]| = m.

Sample Case 0
Sample Input 0

STDIN       Function
-----       --------
3       →   warehouse[][] size n=3 m=4 
4 
1 1 1 1 →   warehouse = [[1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 1]]
1 1 1 1  
1 1 1 1 
Sample Output 0

10
Explanation 0

There are 10 possible paths from warehouse[0][0] to warehouse[2][3] and 10 modulo (109 +7) = 10.

Sample Case 1
Sample Input 1

STDIN      Function
-----      --------
2      →   warehouse[][] size n=2 m=2
2
1 1    →   warehouse = [[1, 1], [0, 1]]
0 1      
Sample Output 1

1
Explanation 1

There is 1 possible path from warehouse[0][0] to warehouse[1][1] and 1 modulo (109 + 7) = 1.

________________________________________________________________________________

groupDivision.cpp working
1. Group Division (Collab UK Version)
A university has admitted a group of n students with varying skill levels. To better accommodate the students, the university has decided to create classes tailored to the skill levels. A placement examination will return a skill level that will be used to group the students, where levels[i] represents the skill level of student i. All students within a group must have a skill level within maxSpread, a specified range of one another. Determine the minimum number of classes that must be formed.
Example
n = 5
levels = [1, 4, 7, 3, 4]
maxSpread = 2 
The students in any group must be within maxSpread = 2 levels of each other. In this case, one optimal grouping is (1, 3), (4, 4), and (7). Another possible grouping is (1), (3, 4, 4), (7).  There is no way to form fewer than 3 groups.
Function Description
Complete the function groupDivision in the editor below.
groupDivision has the following parameter(s):

    int levels[n]:  the skill level for each student
    int maxSpread:  the maximum allowed skill level difference between any two members of a group

Returns
    int: the minimum number of groups that can be formed
Constraints

1 ≤ n ≤ 105
1 ≤ levels[i] ≤ 109 for every i (where 0 ≤ i ≤ n-1)
0 ≤ maxSpread ≤ 109
___________________________________________________________________________________
foundB.cpp working
Task description
Write a function solution that, given a string S consisting of N letters 'a' and/or 'b' returns true when all occurrences of letter 'a' are before all occurrences of letter 'b' and returns false otherwise.

Examples:

1. Given S = "aabbb", the function should return true.

2. Given S = "ba", the function should return false.

3. Given S = "aaa", the function should return true. Note that 'b' does not need to occur in S.

4. Given S = "b", the function should return true. Note that 'a' does not need to occur in S.

5. Given S = "abba", the function should return false.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..300,000];
string S is made only of the characters 'a' and/or 'b'.

_____________________________________________________________________________________
Standard bitwise operation: largestSubsetAnd.cpp working, understood

Task description
AND is a standard bitwise operation. For example, given K = 12 (binary representation 01100) and L = 21 (binary representation 10101) we obtain:

01100 AND
10101 =
_______

00100

The AND operation can be extended to N integers, for example:
01100 AND
10101 AND
00100 =
_______

00100

Because AND of 01100 (first argument) and 10101 (second argument) is 00100, and AND of this number with 00100 (third argument) is also 00100.
Write a function:
int solution(vector<int> &A);

that, given an array A consisting of N integers, returns the size of the largest possible subset of A such that AND of all its elements is greater than 0.

Examples:

1. Given A = [13, 7, 2, 8, 3] your function should return 3.

We can pick subset 13, 7 and 3. AND of these elements is positive and it is the largest possible subset of numbers that fulfills the criteria.

1101 (13) AND
0111 (7) AND
0011 (3) =
_______

0001 (1)

2. Given A = [1, 2, 4, 8] your function should return 1. The AND of each pair from the array is equal to 0.

3. Given A = [16, 16] your function should return 2. The AND of both numbers is 16.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [1..1,000,000,000].
Remember, all submissions are being checked for plagiarism. Your recruiter will be informed in case suspicious activity is detected.
___________________________________________________________________________________
periodNewest.cpp working
Task description
Consider a non-empty string S = S[0]S[1]...S[Q-1] consisting of Q characters. The period of this string is the smallest positive integer P such that:

P ≤ Q / 2 and
S[K] = S[K+P] for every K, where 0 ≤ K < Q − P.
For example, 8 is the period of "codilitycodilityco" and 7 is the period of "abracadabracadabra".

A positive integer M is the binary period of a positive integer N if M is the period of the binary representation of N.

For example, 4 is the binary period of 955, because the binary representation of 955 is "1110111011" and its period is 4.

You are given an implementation of a function:

int solution(int N);

This function, when given a positive integer N, returns the binary period of N. The function returns −1 if N does not have a binary period.

For example, given N = 955 the function returns 4, as explained in the example above.

The attached code is still incorrect for some inputs. Despite the error(s), the code may produce a correct answer for the example test cases. The goal of the exercise is to find and fix the bug(s) in the implementation. You can modify at most two lines.

Assume that:

N is an integer within the range [1..1,000,000,000].
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.

____________________________________________________________________________________________
coins.cpp working

Write a solution in C++ for the following task:

Task description
There are N coins, each showing either heads or tails. We would like all the coins to show the same face. What is the minimum number of coins that must be reversed?

Write a function:

int solution(vector<int> &A);

that, given an array A consisting of N integers representing the coins, returns the minimum number of coins that must be reversed. Consecutive elements of array A represent consecutive coins and contain only a 0 (heads) or a 1 (tails).

For example, given array A = [1, 0, 0, 1, 0, 0], there are four coins showing heads and two coins showing tails. The function should return 2, as after reversing two coins (in positions 0 and 3), all the coins will be showing the same face (heads).

Assume that:

N is an integer within the range [1..100];
each element of array A is an integer that can have one of the following values: 0, 1.
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.

Copyright 2009–2023 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

____________________________________________________________________________________________________
game of Rock-Paper-Scissors
rockPaperScisor.cpp working

Please write a solution in c++ for the following task. The solution must be accompanied by a main() function in which the examples in the task could be tested.

Task description
Franco is going to play a game of Rock-Paper-Scissors with his friend Giovanni. In each turn, both players make their chosen gesture (rock, paper or scissors) simultaneously. After every turn, players gain points as follows: 2 for a win (rock beats scissors, scissors beat paper and paper beats rock), 1 for a tie (when both players show the same gesture) and 0 for a loss.

Franco wants to surprise Giovanni by using a very simple strategy: he will make the same gesture in every turn throughout the game. What is the maximum number of points he can score using this strategy?

Write a function:

int solution(string &G);

that, given a string G representing the sequence of Giovanni's turns ('R' represents a rock, 'P' represents paper and 'S' represents scissors), returns the maximum number of points Franco can score using his strategy.

For example:

Given "RSPRS", the function should return 6 (with the chosen gesture being rock). Franco will gain 6 points (he will win in the second and fifth turns and tie in the first and fourth turn).
Given "SRR" the function should return 4 (chosen gesture: rock; he will win in the first turn and tie in the second and third turns).
Given "PRPRRPP" the function should return 10 (chosen gesture: paper).
Given "PPPPRRSSSSS" the function should return 13 (chosen gesture: scissors).
Assume that:

the length of string G is within the range [1..100];
string G consists only of letters 'R', 'P', and 'S'.
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.

_____________________________________________________________________________________________________
Convert seconds to hours, Minutes, seconds
timeinSecGame.cpp working

Please write a solution in c++ for the following task. The solution must be accompanied by a main() function in which the examples in the task could be tested.

Task description
Myung has a fancy application on her mobile, which shows her the time not in hours, minutes and seconds but only in seconds. She is in a bit of a hurry and she needs your help to convert the output of this application into a readable format.

Write a function:

string solution(int T);

that, given a time T in seconds, converts it into a string in the format "<<hours>>h<<minutes>>m<<seconds>>s".

For example, given T=7500 the function should return 2h5m0s.

Given T=83643 the function should return 23h14m3s.

Assume that:

T is an integer within the range [0..86,399].
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.

___________________________________________________________________________________
maxEvenSumPairs ´partially working. It works not for:
A1 = [4, 2, 5, 8, 7, 3, 7]
sol = Solution()
print(sol.solution(A1))  # Expected output: 2 

Task description
You are given N numbers on a circle, described by an array A. Find the maximum number of neighbouring pairs whose sums are even. One element can belong to only one pair.

Write a function:

class Solution { public int solution(int[] A); }

that, given an array A consisting of N integers, returns the maximum number of neighbouring pairs whose sums are even.

Examples:

1. Given A = [4, 2, 5, 8, 7, 3, 7], the function should return 2. We can create two pairs with even sums: (A[0], A[1]) and (A[4], A[5]). Another way to choose two pairs is: (A[0], A[1]) and (A[5], A[6]).

2. Given A = [14, 21, 16, 35, 22], the function should return 1. There is only one qualifying pair: (A[0], A[4]).

3. Given A = [5, 5, 5, 5, 5, 5], the function should return 3. We can create three pairs: (A[0], A[5]), (A[1], A[2]) and (A[3], A[4]).

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [0..1,000,000,000].

________________________________________________________________________

encodeBinary.cpp partially working. Does not work for  std::string S4(400000, '1');
The Python version (encodeBinary.py) works.

Task description
You are given a string S of length N which encodes a non-negative number V in a binary form. Two types of operations may be performed on it to modify its value:

if V is odd, subtract 1 from it;
if V is even, divide it by 2.
These operations are performed until the value of V becomes 0.

For example, if string S = "011100", its value V initially is 28. The value of V would change as follows:

V = 28, which is even: divide by 2 to obtain 14;
V = 14, which is even: divide by 2 to obtain 7;
V = 7, which is odd: subtract 1 to obtain 6;
V = 6, which is even: divide by 2 to obtain 3;
V = 3, which is odd: subtract 1 to obtain 2;
V = 2, which is even: divide by 2 to obtain 1;
V = 1, which is odd: subtract 1 to obtain 0.
Seven operations were required to reduce the value of V to 0.

Write a function:

int solution(string &S);

that, given a string S consisting of N characters containing a binary representation of the initial value V, returns the number of operations after which its value will become 0.

Examples:

1. Given S = "011100", the function should return 7. String S represents the number 28, which becomes 0 after seven operations, as explained above.

2. Given S = "111", the function should return 5. String S encodes the number V = 7. Its value will change over the following five operations:

V = 7, which is odd: subtract 1 to obtain 6;
V = 6, which is even: divide by 2 to obtain 3;
V = 3, which is odd: subtract 1 to obtain 2;
V = 2, which is even: divide by 2 to obtain 1;
V = 1, which is odd: subtract 1 to obtain 0.
3. Given S = "1111010101111", the function should return 22.

4. Given string S consisting of "1" repeated 400,000 times, the function should return 799,999.

Write an efficient algorithm for the following assumptions:

string S is made only of the characters '0' and/or '1';
N, which is the length of string S, is an integer within the range [1..1,000,000];
the binary representation is big-endian, i.e. the first character of string S corresponds to the most significant bit;
the binary representation may contain leading zeros.

______________________________________________________________________________



