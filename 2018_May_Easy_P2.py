# code_report Solution
# https://youtu.be/Be2rZ647SzM

n = int (input ())
v = list ()

for i in range (n):
   s = input ()
   a, b = (int (n) for n in s.split ())
   v.append ((a,   True))
   v.append ((b+1, False))

v.sort ()

x, y, sum = 0, 0, 0 # x = min_candies, y = max_students

for e in v:
   sum += 1 if e[1] else -1
   if (sum > y): 
       y = sum
       x = e[0]

print (x, " ", y, sep='')

