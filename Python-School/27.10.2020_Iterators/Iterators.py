class Iterator:   
    def __init__(self,count):
        self.counter = count
        self.curr = 0
        self.next = 1
    def __iter__(self):
        return self

    def __next__(self):
        if (self.counter == 0):
            raise StopIteration

        self.counter -= 1
        res = self.curr + self.next
        self.curr = self.next
        self.next = res
        return self.curr

fib = Iterator(20)
for i in fib:
    print(i)

