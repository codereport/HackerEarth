# code_report Solution
# https://youtu.be/LV6DTbLBL8M

x, y, s, t = (int (i) for i in input ().split ())

j, c = t, 0
for i in range (0, t):
    if (j >= y and j <= y + s):
        c += min (max (0, i - x + 1), s + 1)
    j -= 1

print (c)
