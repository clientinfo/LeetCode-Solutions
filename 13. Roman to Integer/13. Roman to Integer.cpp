class Solution
{
	
public:

    int romanToInt(string arg_string) {
        // Create a map to store the numeric values for each Roman numeral symbol
        std::unordered_map<char, int> roman_values = 
		{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;

        // Iterate through the Roman numeral string
        for (int index = 0; index < arg_string.length(); ++index) {
            // Check for the subtraction cases
            if (index < arg_string.length() - 1 && roman_values[arg_string[index]] < roman_values[arg_string[index + 1]]) {
                result += roman_values[arg_string[index + 1]] - roman_values[arg_string[index]];
                // Skip the next symbol since it's already considered in subtraction
                ++index;
            } else {
                result += roman_values[arg_string[index]];
            }
        }

        return result;
    }
};
