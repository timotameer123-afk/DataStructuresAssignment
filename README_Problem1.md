# Part A:
## What is the Complexity Analysis of the `hello_recursive` function? 🤔
* The **complexity** is O($2^n$)

## **Justification:**
* The function `hello_recursive` will make a recursive call for the `hello_recursive` function 2 times per call, making a Binary tree shape with a height $n$.
* This makes a number of $2^n$ calls, as at each level the number of nodes is **doubled**, so the **complexity** is O($2^n$).