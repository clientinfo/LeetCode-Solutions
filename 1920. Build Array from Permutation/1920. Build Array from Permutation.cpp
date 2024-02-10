class Solution {
public:
	/**
	 * @brief Builds an array based on the given array according to specified rules.
	 *
	 * This function constructs a new array where each element at index i is the value at index nums[i] in the given array.
	 *
	 * @param nums The input array.
	 * @return The array constructed according to the specified rules.
	 */
	std::vector<int> buildArray(std::vector<int>& nums)
	{
		// Initialize the resulting array
		std::vector<int> ans;

		// Reserve memory for the resulting array to avoid reallocations
		ans.reserve(nums.size());

		// Iterate through each element in the input array
		for (int index = 0; index < nums.size(); ++index)
		{
			// Add the value at index nums[index] to the resulting array
			ans.push_back(nums[nums[index]]);
		}

		// Return the resulting array
		return ans;
	}
};