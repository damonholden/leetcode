int32_t longestConsecutive(int32_t* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

	bool sorted_nums[3000000000];

    for (int32_t index = 0; index < numsSize; index++) {
		sorted_nums[nums[index] + 1000000000] = true;
	}

    int32_t highest_sequence = 0;
    int32_t current_sequence = 0;
    
    for (int32_t index = 0; index < numsSize; index++) {
		if (sorted_nums[index] == true) {
			current_sequence++;
			continue; 
		}

		if (current_sequence > highest_sequence) {
			highest_sequence = current_sequence;
		}

		current_sequence = 0;
    }

    return highest_sequence;
}