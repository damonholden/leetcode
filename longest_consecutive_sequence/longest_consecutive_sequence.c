int32_t longestConsecutive(int32_t *nums, int numsSize)
{
	if (numsSize == 0)
	{
		return 0;
	}

	int32_t highest_number = nums[0];
	int32_t lowest_number = nums[0];
	for (int32_t index = 1; index < numsSize; index++)
	{
		if (nums[index] > highest_number)
		{
			highest_number = nums[index];
		}

		else if (nums[index] < lowest_number)
		{
			lowest_number = nums[index];
		}
	}

	int32_t size_of_map = highest_number + abs(lowest_number);

	// printf("%d\n", lowest_number);
	// printf("%d\n", abs(lowest_number));
	// printf("%d\n", highest_number);
	// printf("%d\n", size_of_map);

	bool *sorted_nums = calloc(size_of_map + 1, sizeof(bool));

	for (int32_t index = 0; index < numsSize; index++)
	{
		sorted_nums[nums[index] + abs(lowest_number)] = true;
	}

	int32_t highest_sequence = 1;
	int32_t current_sequence = 1;
	int32_t next_num = 0;
	int32_t current_visited_size = 0;
	int32_t vistited[numsSize];
	for (int32_t index = 0; index < numsSize; index++)
	{
		// printf("index %d\n", sorted_nums[index]);
		// printf("high %d\n", highest_sequence);
		// printf("low %d\n", current_sequence);
		if (nums[index] + abs(lowest_number) == 0) {
			while (nums[index] + abs(lowest_number) + 1 != size_of_map) {
				if (sorted_nums[nums[index] + abs(lowest_number) + 1] == true) {
					current_sequence++
				}
			}

		}

		if (sorted_nums[index] == true)
		{
			current_sequence++;

			if (current_sequence > highest_sequence)
			{
				highest_sequence = current_sequence;
			}
			continue;
		}

		if (current_sequence > highest_sequence)
		{
			highest_sequence = current_sequence;
		}

		current_sequence = 0;
	}

	return highest_sequence;
}