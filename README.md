balancedString.cpp
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
minDistIndices.cpp
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
A = {(1,A),(1,B),(1,C),(1,4),
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

add5Atbeginning.cpp
Write a function called solution that, given an integer N, returns the maximum possible value obtained by inserting one '5' digit inside the decimal representation of integer N.
Examples:
1. Given N = 268, the function should return 5268
2. Given N = 670, the function should return 5670
3. Given N = 0, the function should return 50
4. Given N = −999, the function should return −5999
______________________________________________________________________________________
generateString.cpp
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

