# KitchenPlace
Short places in the Map relative to multiple start points (Kitchen Location closer to all Employees)

You need to find the best empty space to put a kitchen in.
a. The kitchen needs to be located in the empty space for which the sum of distances to all employees is minimal.
b. The distance from an empty space to an employee is the shortest path from the employee to the empty space.
c. Employees can only walk in north, south, east or west directions (no diagonals).
d. Employees cannot walk through walls (of course).
e. If the floor plan does not allow for a kitchen (for example if the floor plan does not allow some employees to reach some spaces) then state that it is so.
f. Map need to read from a file with the floor plan and outputs the best kitchen location. If the floor plan does not allow for a kitchen (for example if the floor plan does not allow some employees to reach some spaces) then state that it is so. 
