def fibonacci(index):
    curr = 0
    next = 1
    count = 0
    res = 0
    while(count < index - 1):
        res = curr + next
        curr = next
        next = res
        count += 1
    print(res)

fibonacci(12)
for i in range(10):
    fibonacci(i)







