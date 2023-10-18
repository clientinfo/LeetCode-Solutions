#include <vector>
#include <algorithm>

class Solution
{

public:

    int maximumGap(std::vector<int>& numbers)
    {
        // Get the size of the input array.
        int numbers_size = numbers.size();

        // If there are fewer than 2 elements in the array, the maximum gap is 0.
        if (numbers_size < 2)
        {
            return 0;
        }

        // Find the maximum and minimum elements in the array.
        int max_number = *std::max_element(numbers.begin(), numbers.end());
        int min_number = *std::min_element(numbers.begin(), numbers.end());

        // Calculate the bucket size and the number of buckets.
        int bucket_size = std::max(1, (max_number - min_number) / (numbers_size - 1));
        int bucket_count = (max_number - min_number) / bucket_size + 1;

        // Create arrays to store both max and min values in each bucket.
        int* max_bucket = new int[bucket_count];
        int* min_bucket = new int[bucket_count];

        // Initialize the arrays with extreme values.
        for (int index = 0; index < bucket_count; ++index)
        {
            max_bucket[index] = INT_MIN;
            min_bucket[index] = INT_MAX;
        }

        // Distribute the numbers into the buckets.
        for (int num : numbers)
        {
            int bucketIndex = (num - min_number) / bucket_size;
            max_bucket[bucketIndex] = std::max(max_bucket[bucketIndex], num);
            min_bucket[bucketIndex] = std::min(min_bucket[bucketIndex], num);
        }

        // Calculate the maximum gap by iterating through the buckets.
        int max_gap = 0;
        int previous_max = min_number;

        for (int i = 0; i < bucket_count; ++i)
        {
            // Skip empty buckets.
            if (max_bucket[i] == INT_MIN && min_bucket[i] == INT_MAX)
            {
                continue;
            }

            // Update the maximum gap by comparing with the previous maximum.
            max_gap = std::max(max_gap, min_bucket[i] - previous_max);
            previous_max = max_bucket[i];
        }

        // Deallocate memory to prevent memory leaks.
        delete[] max_bucket;
        delete[] min_bucket;

        // Return the calculated maximum gap.
        return max_gap;
    }
};