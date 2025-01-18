/*
 * @param {number[]} nums
 * @return {number}
 */
function longestConsecutive(numbers_input) {
    if (numbers_input.length < 2) {
        return numbers_input.length
    }

    const numbers_map = {}

    for (const number of numbers_input) {
        numbers_map[number] = true
    }

    const visited = []
    let current_sequence = 0
    let longest_sequence = 1
    let in_sequence = false
    for (const number of Object.keys(numbers_map).map(Number)) {
        if (numbers_map[number - 1] === true) {
            continue
        }

        let sequence_value = number + 1
        do {
            ++current_sequence
            in_sequence = numbers_map[sequence_value++]
        } while (in_sequence === true)

        if (current_sequence > longest_sequence) {
            longest_sequence = current_sequence
        }

        current_sequence = 0
    }

    return longest_sequence
};