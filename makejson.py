
file = open("cc+snippets.cpp", "r")
writefile = open('final.cpp', "w")
s = file.read().splitlines()
for lines in s:
    writefile.write('"'+lines+'",\n')
