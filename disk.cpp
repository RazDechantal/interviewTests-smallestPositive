#include <iostream>
#include <vector>

std::string solution(std::vector<int> &stack1, std::vector<int> &stack2, std::vector<int> &stack3)
{
    int n1 = stack1.size();
    int n2 = stack2.size();
    int n3 = stack3.size();

    // Base case: If all stacks are empty, return an empty string
    if (n1 == 0 && n2 == 0 && n3 == 0)
    {
        return "";
    }

    std::string moves;

    // Find the largest disk among the top elements of the stacks
    int top1 = (n1 > 0) ? stack1.back() : 0;
    int top2 = (n2 > 0) ? stack2.back() : 0;
    int top3 = (n3 > 0) ? stack3.back() : 0;

    // Determine which stack has the largest disk
    int maxTop = std::max(std::max(top1, top2), top3);

    // Move the largest disk to the fourth stack
    if (maxTop == top1)
    {
        moves += "1";
        stack1.pop_back();
    }
    else if (maxTop == top2)
    {
        moves += "2";
        stack2.pop_back();
    }
    else
    {
        moves += "3";
        stack3.pop_back();
    }

    // Recursively find the sequence of moves for the remaining disks
    std::string remainingMoves = solution(stack1, stack2, stack3);

    // Append the moves for the remaining disks to the current moves
    moves += remainingMoves;

    return moves;
}

int main()
{
    std::vector<int> stack1 = {2, 7};
    std::vector<int> stack2 = {4, 5};
    std::vector<int> stack3 = {1};
    std::string moves = solution(stack1, stack2, stack3);
    std::cout << moves << std::endl; // Output: "12213"

    stack1 = {10, 20, 30};
    stack2 = {8};
    stack3 = {1};
    moves = solution(stack1, stack2, stack3);
    std::cout << moves << std::endl; // Output: "11123"

    stack1 = {7};
    stack2 = {};
    stack3 = {9};
    moves = solution(stack1, stack2, stack3);
    std::cout << moves << std::endl; // Output: "31"

    return 0;
}
