mat= [
    [1, 2, 3, 4],
    [2, 4, 6, 5], 
    [3, 10, 9, 7],
    [15, 14, 8, 6]
]

print("Matrix: ")
for row in mat:
    print(row)

r= int(input("Enter starting row : "))
c= int(input("Enter starting column: "))

r= r-1
c= c-1

curr_val= mat[r][c]
print("Starting value: ", curr_val)

moving= True

while moving: 
    moving= False

    up_r= r-1
    up_c= c

    right_r= r
    right_c= c +1

    left_r= r
    left_c= c-1

    down_r= r+1
    down_c= c

    up_lr= r-1
    up_lc= c-1

    up_rr= r-1
    up_rc= c+1

    down_lr= r+1
    down_lc= c-1

    down_rr= r+1
    down_rc= c+1

    if up_lr>=0 and up_lc>=0:
        if mat[up_lr][up_lc]>curr_val:
            r=up_lr
            c=up_lc
            curr_val=mat[r][c]
            moving=True
            continue

    if up_r>=0:
        if mat[up_r][up_c] > curr_val:
            r= up_r
            c= up_c
            curr_val= mat[r][c]
            moving= True
            continue

    if up_rr>=0 and up_rc<=3:
        if mat[up_rr][up_rc]> curr_val:
            r=up_rr
            c=up_rc
            curr_val=mat[r][c]
            moving=True
            continue

    if right_c<=3:
        if mat[right_r][right_c]>curr_val:
            r= right_r
            c= right_c
            curr_val=mat[r][c]
            moving=True
            continue

    if down_rr<=3 and down_rc<=3:
        if mat[down_rr][down_rc]> curr_val:
            r=down_rr
            c=down_rc
            curr_val=mat[r][c]
            moving=True
            continue

     
    if down_r<=3:
        if mat[down_r][down_c]>curr_val:
            r= down_r
            c= down_c
            curr_val= mat[r][c]
            moving= True
            continue

    if down_lr<=3 and down_lc>=0:
        if mat[down_lr][down_lc]> curr_val:
            r=down_lr
            c=down_lc
            curr_val=mat[r][c]
            moving=True
            continue

    if left_c>=0: 
        if mat[left_r][left_c]> curr_val:
            r= left_r
            c= left_c
            curr_val=mat[r][c]
            moving=True
            continue


print(f"Stopped at row: {r+1} and column: {c+1} with value: {curr_val}")

print(f"The global max is {max(max(row) for row in mat)}")