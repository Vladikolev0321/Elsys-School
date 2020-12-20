def solve(input):
    myDict = {}
    for i in input:
        if(i in myDict):
        #if(myDict.__contains__(i)):    
            myDict[i] += 1
        else:
            myDict[i] = 1
    print(myDict)

solve(["cat","cat","dog"])
