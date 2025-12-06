import itertools
import random
import sys
import os

def construct_white_block_sequence(combination, extra_white, num_blocks):
    white_blocks = []
    
    prev_index = -1
    for current_index in combination:
        count = current_index - prev_index - 1
        white_blocks.append(count)
        prev_index = current_index
        
    total_slots_range = extra_white + num_blocks
    white_blocks.append(total_slots_range - 1 - prev_index)

    return white_blocks


def construct_line_string(hint_set, extra_whites_counts):
    num_blocks = len(hint_set)
    line_str = ""
    for i in range(num_blocks):
        line_str += "." * extra_whites_counts[i]
        line_str += "#" * hint_set[i]
        if i < num_blocks - 1:
            line_str += "."
            
    line_str += "." * extra_whites_counts[-1]
    return line_str


def generate_combinations_data(line_length, hint_set, output_path):
    """
    Generates all valid line combinations and writes them to a file.
    """
    num_blocks = len(hint_set)
    total_black = sum(hint_set)
    needed_white = num_blocks - 1 if num_blocks > 0 else 0
    extra_white = line_length - total_black - needed_white
    
    if extra_white < 0:
        return []

    results = []
    for combo in itertools.combinations(range(extra_white + num_blocks), num_blocks):
        white_block_sequence = construct_white_block_sequence(combo, extra_white, num_blocks)
        line_str = construct_line_string(hint_set, white_block_sequence)

        results.append(line_str)

    with open(output_path, 'w') as f:
        for placement in results:
            f.write(placement + "\n") 
    
    print(f"Data successfully generated to: {output_path}")
    print(f"Line Length: {line_length}, Hints: {hint_set}") # Debug output


def main():
    if len(sys.argv) < 2:
        print("Usage: python generate_data.py <output_file_path>")
        sys.exit(1)

    output_file = sys.argv[1]
    
    os.makedirs(os.path.dirname(output_file), exist_ok=True)
    
    hintCount = random.randrange(2, 4)
    hintSet = [random.randrange(1, 5) for _ in range(hintCount)]
    
    min_length = sum(hintSet) + len(hintSet) - 1
    lineLength = min_length + random.randrange(0, 5)
    
    generate_combinations_data(lineLength, hintSet, output_file)

if __name__ == "__main__":
    main()