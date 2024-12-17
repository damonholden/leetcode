int32_t longestConsecutive(int32_t* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int32_t sorted_nums[numsSize];
    sorted_nums[0] = nums[0];
    int32_t sorted_nums_size = 1;
    bool found;
    int32_t temp_store;
    int32_t temp_store_two;
    int32_t highest_seen = sorted_nums[0];

    for (int32_t index_x = 1; index_x < numsSize; index_x++) {
        found = false;
        for (int32_t index_y = 0; index_y <= index_x ; index_y++) {
            if (nums[index_x] > highest_seen) {
                sorted_nums[index_x] = nums[index_x];
                highest_seen = sorted_nums[index_x];
                break;
            }

            if (index_y == index_x) {
                if (found == true) {
                    sorted_nums[index_y] = temp_store;
                    continue;
                }

                sorted_nums[index_y] = nums[index_x];
                continue;
            }

            if (found == true) {
                temp_store_two = sorted_nums[index_y];
                sorted_nums[index_y] = temp_store;
                temp_store = temp_store_two;
                continue;
            }

            if (nums[index_x] < sorted_nums[index_y]) {
                temp_store = sorted_nums[index_y];
                sorted_nums[index_y] = nums[index_x];
                found = true;
                continue;
            }
        }

        // printf("instance arr \n");
        // for (int32_t index_z = 0; index_z < index_x; index_z++) {
        //     printf("%d ",sorted_nums[index_z]);
        // }
        // printf("\n");

    }

    // printf("final arr \n");
    // for(int32_t final_index = 0; final_index < numsSize; final_index++) {
    //     printf("%d ", sorted_nums[final_index]);
    // }

    int32_t highest_sequence = 1;
    int32_t current_sequence = 1;
    
    for (int32_t count_index = 0; count_index < numsSize - 1; ++count_index) {
        if (sorted_nums[count_index] == sorted_nums[count_index + 1]) {
            if (current_sequence > highest_sequence) {
                highest_sequence = current_sequence;
            }
            continue;
        }

        if (sorted_nums[count_index] + 1 == sorted_nums[count_index + 1]) {
            current_sequence++;
            if (current_sequence > highest_sequence) {
                highest_sequence = current_sequence;
            }
            continue;
        }

        if (current_sequence > highest_sequence) {
            highest_sequence = current_sequence;
        }

        current_sequence = 1;
    }

    return highest_sequence;
}