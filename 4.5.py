def josephus(n, k):
    if n == 1:
        return 1
    else:
        return (josephus(n - 1, k) + k - 1) % n + 1
n = int(input("Enter number of people (n): "))
k = int(input("Enter step count (k): "))

result = josephus(n, k)
print(f"The safe position is: {result}")
