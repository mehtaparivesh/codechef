def min_window(s, t):
    from collections import Counter
    
    # Create a Counter for characters in target string
    target_counter = Counter(t)
    
    # Variable to store the result
    result = ""
    min_length = float('inf')
    
    # Two pointers for our sliding window
    left = right = 0
    # Variable to keep track of number of chars of t found in s
    num_chars_found = 0
    
    # Create a Counter for characters in our sliding window
    window_counter = Counter()
    
    # Expand the right side of our sliding window
    while right < len(s):
        if s[right] in target_counter and window_counter[s[right]] < target_counter[s[right]]:
            num_chars_found += 1
        window_counter[s[right]] += 1
        # If all chars are found, contract the left side of our window
        while num_chars_found == len(t):
            if right - left + 1 < min_length:
                min_length = right - left + 1
                result = s[left:right+1]
            window_counter[s[left]] -= 1
            if s[left] in target_counter and window_counter[s[left]] < target_counter[s[left]]:
                num_chars_found -= 1
            left += 1
        right += 1
    
    return result if result else "null"

s = input().strip()
t = input().strip()
print(min_window(s, t))
