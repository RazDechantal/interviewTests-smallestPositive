def smallest_missing_positive(A):
    # Create a set to store positive integers in A
    positive_set = set()
    
    # Iterate through the array A and add positive integers to the set
    for num in A:
        if num > 0:
            positive_set.add(num)
    
    # Start from 1 and find the smallest missing positive integer
    smallest = 1
    while smallest in positive_set:
        smallest += 1
    
    return smallest

def main():
    # Test cases
    A1 = [1, 3, 6, 4, 1, 2]
    A2 = [1, 2, 3]
    A3 = [-1, -3]

    result1 = smallest_missing_positive(A1)
    result2 = smallest_missing_positive(A2)
    result3 = smallest_missing_positive(A3)

    print(f"For A1: {A1}, the smallest missing positive integer is {result1}")
    print(f"For A2: {A2}, the smallest missing positive integer is {result2}")
    print(f"For A3: {A3}, the smallest missing positive integer is {result3}")

if __name__ == "__main":
    main()
