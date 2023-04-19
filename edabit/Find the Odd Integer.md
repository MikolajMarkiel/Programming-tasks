# Instruction
Create a function that takes an array and finds the integer which appears an odd number of times.

### Examples

```
findOdd([1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5]) ➞ -1

findOdd([20, 1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5]) ➞ 5

findOdd([10]) ➞ 10
```

### Notes

There will always only be one integer that appears an odd number of times

# My solution
```cpp
using namespace std;

int findOdd(vector<int> arr) {
	for (int item : arr)
	{
		int tmp = count(arr.begin(), arr.end(), item);
		if (tmp % 2 == 1)
		{
			return item;
		}
	}
}
```
