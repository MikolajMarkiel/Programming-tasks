# Instruction 
Create a function that takes a string and returns the first character that repeats. If there is no repeat of a character, return `"0"`.

### Examples

```
firstRepeat("legolas") ➞ "l"

firstRepeat("Gandalf") ➞ "a"

firstRepeat("Balrog") ➞ "0"

firstRepeat("Isildur") ➞ "0"
// Case sensitive "I" not equal to "i"
```

### Notes

Tests are case sensitive.

# My solution

```cpp
char firstRepeat(std::string chars) {
	for (int i = 0; i < chars.size(); i++)
	{
		if (chars.rfind(chars.at(i)) == i)
		{
			continue;
		}
		else
		{
			return chars.at(i);
		}
	}
	return '0';
}
```