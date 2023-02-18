import sys

seats = int(input())
configuration = input()
seatsArray = []
removed = 0

for i in configuration:
  seatsArray.append(i)

for i in range(len(seatsArray)):
  if i == len(seatsArray) - 1:
    break
  if seatsArray[i] == "." and seatsArray[i+1] == ".":
    print(0)
    sys.exit()

def dotCounter(lst,item):
  valuesArray = []
  counter = 1
  for i in range(len(lst) - 1):
    if lst[i] == item:
      if lst[i]  == lst[i+1]:
        counter += 1
        continue
      else:
        valuesArray.append(counter)
        counter = 1
  return min(valuesArray)

while removed != 1:
    if seatsArray[0] == '#':
      seatsArray.remove('#')
    elif seatsArray[0] == '.':
      removed = 1

print(dotCounter(seatsArray,"#"))