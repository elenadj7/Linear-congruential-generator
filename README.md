# Linear congruential generator

This algorithm is based on the application of the following recurrence equation:
Xj+1 = (a*Xj+b) mod m
where:
Xj - pseudorandom numbers (X0, a seed value whose value is given) for which 0 ≤ X0 < m.
a, b, m - positive integer constants for which 0 < a < m, 0 ≤ b < m, and m > 0.
mod - the operator that denotes the remainder when dividing two numbers (the % operator in most programming languages).

The generator provides the functionality to read initial values from a configuration file. Additionally, when launching the generator, it is necessary to specify the length of the sequence of random numbers that needs to be generated. The program functions by generating a binary search tree from a specified array and presenting it on the output in a hierarchical format. Subsequently, the program prints the inorder traversal of the constructed tree. Afterwards, a heap data structure is instantiated, followed by a demonstration of the heapsort algorithm used to sort the provided array in ascending order. Throughout each iteration of the algorithm, the console displays the current appearance of the entire array, along with the corresponding binary tree structure.
