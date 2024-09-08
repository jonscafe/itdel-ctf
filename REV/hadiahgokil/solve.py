def reverse_operations(a, b, c, d):
    result = []

    # Undo the sum: reverse b - d
    result.append(b - d)

    # Append d as is (no changes)
    result.append(d)

    # Reverse the next class residue by applying the modular inverse of the prime
    large_prime = 104729  # The large prime used in forward operation
    mod_inverse = find_mod_inverse(large_prime, 225925880321)  # Modular inverse of the prime
    reversed_residue = (c * mod_inverse) % 225925880321
    result.append(reversed_residue)

    # Undo XOR operation
    result.append((b - d) ^ a)

    return result


def find_mod_inverse(num, modulo):
    # Modular inverse using Python's pow function
    return pow(num, -1, modulo)


def process(inp):
    hex_string = inp
    for i in range(7):
        print("--------------------------------------------")
        print(i + 1)

        hex_list = hex_string.split("-")
        decimal_list = []

        for hex_value in hex_list:
            decimal_value = int(hex_value, 16)
            decimal_list.append(decimal_value)

        result = reverse_operations(decimal_list[0], decimal_list[1], decimal_list[2], decimal_list[3])

        hex_output = "-".join([hex(value)[2:].upper() for value in result])
        number_output = result

        print("Hex Input:", hex_string)
        print("Number Input:", decimal_list)
        print("Hex Output:", hex_output)
        print("Number Output:", number_output)

        hex_string = hex_output

    return hex_string


# Example test case
print(process("1CDF-79AC-2E68397387-525A"))
