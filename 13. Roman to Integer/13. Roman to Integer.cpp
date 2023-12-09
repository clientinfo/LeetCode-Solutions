class Solution
{
	
public:

    int romanToInt(string s) {
        // Create a map to store the numeric values for each Roman numeral symbol
        std::unordered_map<char, int> l_roman_values = 
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
        for (int index = 0; index < s.length(); ++index) {
            // Check for the subtraction cases
            if (index < s.length() - 1 && l_roman_values[s[index]] < l_roman_values[s[index + 1]]) {
                result += l_roman_values[s[index + 1]] - l_roman_values[s[index]];
                // Skip the next symbol since it's already considered in subtraction
                ++index;
            } else {
                result += l_roman_values[s[index]];
            }
        }

        return result;
    }
};