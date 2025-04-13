import subprocess

input_data = "9 3 5 1 4"
expected_output = "1 3 4 5 9"

with open("test_input.txt", "w") as f:
    f.write(input_data)

subprocess.run(["./radix_sort", "0", "test_input.txt"], check=True)

with open("out.txt") as f:
    output = f.read().strip()

if output == expected_output:
    print(" Test passed")
    exit(0)
else:
    print(f" Test failed: expected '{expected_output}', got '{output}'")
    exit(1)
