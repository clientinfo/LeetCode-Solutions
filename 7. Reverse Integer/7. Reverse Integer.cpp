#include <climits> // Include the header file for integer limits.

class Solution {

public:

	// Define the reverse function which takes an integer x as input.
	int reverse(int x)
	{

		// Initialize a variable to store the reversed integer.
		int reversed_integer = 0;

		// Starts loop to reverse the digits of the given integer.
		while (x != 0)
		{
			// Extracts the last digit of the input integer.
			int last_digit = x % 10;

			// Remove the last digit from the input integer.
			x /= 10;

			// Check for overflow condition (greater than INT_MAX) if we append the current digit.
			if (reversed_integer > INT_MAX / 10 || (reversed_integer == INT_MAX / 10 && last_digit > 7))
			{

				return 0;
			}

			// Check for overflow condition (less than INT_MIN) if we append the current digit.
			if (reversed_integer < INT_MIN / 10 || (reversed_integer == INT_MIN / 10 && last_digit < -8))
			{

				return 0;
			}

			// Reverse the integer by appending the current digit.
			reversed_integer = reversed_integer * 10 + last_digit;
		}

		// Return the reversed integer.		
		return reversed_integer;
	}
};
