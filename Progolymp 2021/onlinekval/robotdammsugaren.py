mapDescriptions = input().split()
instructions = (" ".join(input())).split()
squareGrid = []
yAxis = int(mapDescriptions[0])

currentSqr = []
coveredSqr = []
for i in range(yAxis):
    squareGrid.append([char for char in input()])

for x in range(len(squareGrid)):
    for y in range(len(squareGrid[x])):
        if squareGrid[x][y] == "O":
            currentSqr = [x, y]
            squareGrid[x][y] = ""
            coveredSqr.append(currentSqr)
            break

for i in instructions:
    locSqr = currentSqr
    if i == ">":
      while squareGrid[locSqr[0]][locSqr[1]] != "#":
          if squareGrid[locSqr[0]][locSqr[1]] == "" or squareGrid[locSqr[0]][locSqr[1]] == ".":
              locSqr = [locSqr[0], locSqr[1] + 1]  # movement
              if squareGrid[locSqr[0]][locSqr[1]] == ".":
                  coveredSqr.append(locSqr)
                  squareGrid[locSqr[0]][locSqr[1]] = ""
              elif squareGrid[locSqr[0]][locSqr[1]] == "#":
                  continue
              currentSqr = locSqr
          continue
      locSqr = [locSqr[0], locSqr[1] - 1]
    if i == "<":
      while squareGrid[locSqr[0]][locSqr[1]] != "#":
          if squareGrid[locSqr[0]][locSqr[1]] == "" or squareGrid[locSqr[0]][locSqr[1]] == ".":
              locSqr = [locSqr[0], locSqr[1] - 1]  # movement
              if squareGrid[locSqr[0]][locSqr[1]] == ".":
                  coveredSqr.append(locSqr)
                  squareGrid[locSqr[0]][locSqr[1]] = ""
              elif squareGrid[locSqr[0]][locSqr[1]] == "#":
                  continue
              currentSqr = locSqr
          continue
      locSqr = [locSqr[0], locSqr[1] + 1]
    if i == "^":
      while squareGrid[locSqr[0]][locSqr[1]] != "#":
          if squareGrid[locSqr[0]][locSqr[1]] == "" or squareGrid[locSqr[0]][locSqr[1]] == ".":
              locSqr = [locSqr[0] - 1, locSqr[1]]  # movement
              if squareGrid[locSqr[0]][locSqr[1]] == ".":
                  coveredSqr.append(locSqr)
                  squareGrid[locSqr[0]][locSqr[1]] = ""
              elif squareGrid[locSqr[0]][locSqr[1]] == "#":
                  continue
              currentSqr = locSqr
          continue
      locSqr = [locSqr[0] + 1, locSqr[1]]
    if i == "v":
      while squareGrid[locSqr[0]][locSqr[1]] != "#":
          if squareGrid[locSqr[0]][locSqr[1]] == "" or squareGrid[locSqr[0]][locSqr[1]] == ".":
              locSqr = [locSqr[0] + 1, locSqr[1]]
              if squareGrid[locSqr[0]][locSqr[1]] == ".":
                  coveredSqr.append(locSqr)
                  squareGrid[locSqr[0]][locSqr[1]] = ""
              elif squareGrid[locSqr[0]][locSqr[1]] == "#":
                  continue
              currentSqr = locSqr
          continue
      locSqr = [locSqr[0] - 1, locSqr[1]]

print(len(coveredSqr))