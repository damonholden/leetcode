/** 
 * @param {number[]} numbers_imput
 * @return {number}
 */
function longestConsecutive(numbers_input) {
    if (numbers_input.length < 2) {
        return numbers_input.length
    }

    const numbers_map = new Map()

    for (const number of numbers_input) {
        numbers_map.set(number, true)
    }

    let current_sequence = 0
    let longest_sequence = 1
    let in_sequence = false
    for (const number of numbers_map.keys()) {
        if (numbers_map.get(number - 1) === true) {
            continue
        }

        let sequence_value = number + 1
        do {
            ++current_sequence
            in_sequence = numbers_map.get(sequence_value++)
        } while (in_sequence === true)

        if (current_sequence > longest_sequence) {
            longest_sequence = current_sequence
        }

        current_sequence = 0
    }

    return longest_sequence
};