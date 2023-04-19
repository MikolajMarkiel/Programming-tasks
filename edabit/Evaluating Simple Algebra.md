# Instruction
Given a _string_ containing an _algebraic equation_, calculate and **return the value of x**. You'll only be given equations for simple **addition** and **subtraction**.

### Examples

```
evalAlgebra("2 + x = 19") ➞ 17

evalAlgebra("4 - x = 1") ➞ 3

evalAlgebra("23 + 1 = x") ➞ 24
```

### Notes

-   There are spaces between every number and symbol in the string.
-   x may be a negative number
# My solution

```cpp
int evalAlgebra(std::string eq) {

	enum class side {left, right};
	enum class sign {addition, subtraction};
	side side = side::left;
	sign curr_sign = sign::addition;
	bool inversion = 0;
	int x = 0;
	int tmp = 0;
	char c;

	for (int i = 0; i < eq.size(); i++) {
		c = eq.at(i);
		
		if (c >= '0' && c <= '9') {
			tmp = tmp * 10 + (c - '0');
			if (i < eq.size()-1) {
				continue;
			}
		}
		
		x = x + (((int)curr_sign ^ (int)side) ? tmp : -tmp); // (+ left) or (- right) -> substraction; (- left) or (+ right) -> addition
		tmp = 0;

		if (c == '=') {
			side = side::right;
			curr_sign = sign::addition;
		} 
		else if (c == '+') {
			curr_sign = sign::addition;
		}
		else if (c == '-') {
			curr_sign = sign::subtraction;
		}
		else if (c == 'x') {
			inversion = (int)curr_sign ^ (int)side;
		}
	}
	if (inversion) {
		x = -x;
	}
	return x;
}
```