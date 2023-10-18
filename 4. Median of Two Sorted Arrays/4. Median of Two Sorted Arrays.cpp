#include <vector>

class Solution
{

public:

	// Define the findMedianSortedArrays function which takes two sorted arrays as parameters.
	double findMedianSortedArrays(std::vector<int>& array_number_one, std::vector<int>& array_number_two)
	{
		
		// Get the sizes of the input arrays.
		int m = array_number_one.size();
		int n = array_number_two.size();
		
		// Variables to maintain the binary search range and calculate the median.
		int imin = 0, imax = m;
		int halfLen = (m + n + 1) / 2;
		double median = 0.0;

		// Ensure array_number_one is the smaller array to simplify the following logic.
		if (m > n)
		{
			std::swap(array_number_one, array_number_two);
			std::swap(m, n);
		}

		// Perform binary search to find the median.
		while (imin <= imax) 
		{
			// Current index in array_number_one.
			int i = (imin + imax) / 2;

			// Corresponding index in array_number_two.
			int j = halfLen - i; 

			// Binary search to find a partition that satisfies the median condition.
			if (i < m && array_number_two[j - 1] > array_number_one[i]) 
			{
				imin = i + 1;
			}

			else if (i > 0 && array_number_one[i - 1] > array_number_two[j]) 
			{
				imax = i - 1;
			}

			else 
			{
				// Found a valid partition, calculate the median accordingly.
				// Calculate the maximum of the left side of the partition.

				int max_of_left = 0;
				if (i == 0) 
				{
					max_of_left = array_number_two[j - 1];
				}

				else if (j == 0)
				{
					max_of_left = array_number_one[i - 1];
				}

				else 
				{
					max_of_left = std::max(array_number_one[i - 1], array_number_two[j - 1]);
				}

				// If the total length of the merged array is odd, return the maximum of the left side.
				if ((m + n) % 2 == 1) 
				{
					return max_of_left;
				}

				// Calculate the minimum of the right side of the partition.
				int min_of_right = 0;

				if (i == m) 
				{
					min_of_right = array_number_two[j];
				}

				else if (j == n)
				{
					min_of_right = array_number_one[i];
				}

				else
				{
					min_of_right = std::min(array_number_one[i], array_number_two[j]);
				}

				// If the total length of the merged array is even, return the average of the left and right minima.
				return (max_of_left + min_of_right) / 2.0;
			}
		}

		return median;
	}
};