from time import sleep

def next_generation(grid):
    # Your implementation goes here
    # Please don't upload the whole content of the file,
    # but only this function (along with any additional
    # code that your implementation requires)
    def count_alive_neighbours_cells(row, col, grid):
        count_alive_cells = 0
        if(row-1 >= 0):
            if(grid[row-1][col] == 1):
                count_alive_cells += 1
            if(col-1 >= 0):
                if(grid[row-1][col-1] == 1):
                    count_alive_cells += 1
            if(col+1 < 15):
                if(grid[row-1][col+1] == 1):
                    count_alive_cells += 1
        if(row+1 < 15):
            if(grid[row+1][col] == 1):
                count_alive_cells += 1
            if(col-1 >= 0):
                if(grid[row+1][col-1] == 1):
                    count_alive_cells += 1
            if(col+1 < 15):
                if(grid[row+1][col+1] == 1):
                    count_alive_cells += 1
        if(col - 1 >= 0):
            if(grid[row][col-1] == 1):
                count_alive_cells += 1
        if(col + 1 < 15):
            if(grid[row][col+1] == 1):
                count_alive_cells += 1
        if(count_alive_cells < 2):
            grid[row][col] = 0
        if(count_alive_cells > 3):
            grid[row][col] = 1
        return count_alive_cells
    for row in range(15):
        for col in range(15):
            count_alive_cells = 0
            if(grid[row][col] == 1):
                if(row-1 >= 0):
                    if(grid[row-1][col] == 1):
                        count_alive_cells += 1
                    if(col-1 >= 0):
                        if(grid[row-1][col-1] == 1):
                            count_alive_cells += 1
                    if(col+1 < 15):
                        if(grid[row-1][col+1] == 1):
                            count_alive_cells += 1
                if(row+1 < 15):
                    if(grid[row+1][col] == 1):
                        count_alive_cells += 1
                    if(col-1 >= 0):
                        if(grid[row+1][col-1] == 1):
                            count_alive_cells += 1
                    if(col+1 < 15):
                        if(grid[row+1][col+1] == 1):
                            count_alive_cells += 1
                if(col - 1 >= 0):
                    if(grid[row][col-1] == 1):
                        count_alive_cells += 1
                if(col + 1 < 15):
                    if(grid[row][col+1] == 1):
                        count_alive_cells += 1
                if(count_alive_cells < 2):
                    grid[row][col] = 0
                if(count_alive_cells > 3):
                    grid[row][col] = 1
            if(grid[row][col] == 0):



    return grid


def print_grid(grid):
    for row in grid:
        for cell in row:
            print('■' if cell else '□', end=' ')
        print('')


def animate(grid):
    generation = grid
    while True:
        print('')
        print('')
        print_grid(generation)
        sleep(1)
        #generation = next_generation(generation)

g = [[0 for i in range(15)] for k in range(15)]
g[2][1] = 1
g[2][2] = 1
g[2][3] = 1
g[1][3] = 1
g[0][2] = 1

animate(g)