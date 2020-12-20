class Turtle:
    def __init__(self, rows, cols):
        self.rows = rows
        self.cols = cols
        self.canvas = []
        self.curr_row = 0
        self.curr_col = 0
        self.curr_direction = 0

        for x in range(rows):
            row = []
            for y in range(cols):
                row.append(0)
            self.canvas.append(row)

    def spawn_at(self, row, col):
        if(row < self.rows and col < self.cols and row >= -self.rows and col >= -self.cols):
            self.canvas[row][col] += 1
            self.curr_row = row
            self.curr_col = col
        else:
            raise Exception("Invalid indexes")

    def move(self):  #directions r-0 d-1 l-2 u-3
        is_spawned = False

        for row in range(len(self.canvas)):
            for col in range(len(self.canvas[row])):
                if(self.canvas[row][col] != 0):
                    is_spawned = True
                    break

        if(is_spawned == True):
            if(self.curr_direction == 0):
                self.move_right()
            elif(self.curr_direction == 1):
                self.move_down()
            elif(self.curr_direction == 2):
                self.move_left()
            else:
                self.move_up()
        else:
            raise RuntimeError("Can't use move, there is no turtle spawned!")

    def move_right(self):
        if(self.curr_col + 1 == self.cols):
            self.curr_col = 0
        else:
            self.curr_col += 1

        self.canvas[self.curr_row][self.curr_col] += 1

    def move_down(self):
        if(self.curr_row + 1 == self.rows):
            self.curr_row = 0
        else:
            self.curr_row += 1

        self.canvas[self.curr_row][self.curr_col] += 1

    def move_left(self):
        if(self.curr_col - 1 < 0):
            self.curr_col = self.cols - 1
        else:
            self.curr_col -= 1

        self.canvas[self.curr_row][self.curr_col] += 1

    def move_up(self):
        if(self.curr_row - 1 < 0):
            self.curr_row = self.rows - 1
        else:
            self.curr_row -= 1

        self.canvas[self.curr_row][self.curr_col] += 1

    def turn_right(self):
        if(self.curr_direction == 3):
            self.curr_direction = 0
        else:
            self.curr_direction += 1

    def turn_left(self):
        if(self.curr_direction == 0):
            self.curr_direction = 3
        else:
            self.curr_direction -= 1
#to check if spawn_at is called at least one time


class SimpleCanvas:
    def __init__(self, canvas, symbolArr):
        self.canvas = canvas
        self.symbolArr = symbolArr
        self.max_count = 0

    def draw(self):
        for row in range(len(self.canvas)):
            for col in range(len(self.canvas[row])):
                if(self.canvas[row][col] > self.max_count):
                    self.max_count = self.canvas[row][col]

        resCanvas = []

        for x in range(len(self.canvas)):
            row = []
            for y in range(len(self.canvas[x])):
                row.append(0)
            resCanvas.append(row)

        intensity_intervals = []

        intensity_intervals.append(0)
        for x in range(1, len(self.symbolArr) - 1):
            intensity_intervals.append(x / (len(self.symbolArr) - 1))
        intensity_intervals.append(1)
        #print(intensity_intervals)

        for index_of_interval in range(1, len(self.symbolArr)):
            for row in range(len(self.canvas)):
                for col in range(len(self.canvas[row])):
                    curr_intensity = self.canvas[row][col] / self.max_count
                    if(curr_intensity == 0):
                        resCanvas[row][col] = self.symbolArr[0]
                    elif(intensity_intervals[index_of_interval - 1] < curr_intensity <= intensity_intervals[index_of_interval]):
                        resCanvas[row][col] = self.symbolArr[index_of_interval]
                    elif(curr_intensity == 1):
                        resCanvas[row][col] = self.symbolArr[len(self.symbolArr) - 1]

        res = []
        for i in range(len(resCanvas)):
            res.append("".join(resCanvas[i]))
        resString = "\n".join(res)
        return resString


"""
turtle = Turtle(3, 3)
turtle.spawn_at(0, 0)
turtle.move()
turtle.turn_right()
turtle.move()
turtle.move()
turtle.turn_left()
turtle.move()
print(turtle.canvas)

#
turtle = Turtle(3, 3)
turtle.spawn_at(0, 0)
for i in range(9):
    turtle.move()
print(turtle.canvas)
#for row in range(len(turtle.canvas)):
 #   for col in range(len(turtle.canvas[row])):
  #      print(row)

turtle = Turtle(3, 3)
turtle.spawn_at(0, 0)
for i in range(9):
    turtle.move()
turtle.turn_right()
for i in range(4):
    turtle.move()
turtle.turn_left()
turtle.move()
turtle.move()
turtle.turn_right()
turtle.move()

canvas = SimpleCanvas(turtle.canvas, [' ', '*', '@', '#'])
print(canvas.draw())
"""
"""
turtle = Turtle(3, 3)
turtle.spawn_at(0, 0)
for i in range(9):
    turtle.move()
turtle.turn_right()
for i in range(4):
    turtle.move()
turtle.turn_left()
turtle.move()
turtle.move()
turtle.turn_right()
turtle.move()
canvas = SimpleCanvas(turtle.canvas, [' ', '*', '@', '#'])
print(canvas.draw())
print(canvas.draw())

"""