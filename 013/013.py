f = open("p013_input.txt", "r")
print "answer =" , str(sum(int(line) for line in f))[:10]
