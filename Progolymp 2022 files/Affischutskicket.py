a = input().split()
kuvert = int(a[0])
affisch = int(a[1])
blad = int(a[2])

b = ((kuvert/1000000)*(229*324))*2
c = (affisch/1000000)*(297*420)*2
d = (blad/1000000)*(210*297)

print(b+c+d)