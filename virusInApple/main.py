from copy import copy, deepcopy

def infect_apple(apple, n):
    if n == 0:
        return apple
    
    current = deepcopy(apple)
    for c in range(n):
        for i in range(len(apple)):
            for j in range(len(apple[i])):
                if apple[i][j] == "V":
                    #Calc indices 
                    up = (0 if i == 0 else i-1, j)        
                    down = (i if i == len(apple)-1 else i+1, j)        
                    left = (i, j if j == 0 else j-1)
                    right = (i, j if j == len(apple[i])-1 else j+1)
                    #Set current 
                    current[up[0]][up[1]] = "V"
                    current[down[0]][down[1]] = "V"
                    current[left[0]][left[1]] = "V"
                    current[right[0]][right[1]] = "V"
        #Update apple 
        apple = deepcopy(current)
    
    return current
