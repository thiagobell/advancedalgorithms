import sys
from random import randint
##reads net file
if(len(sys.argv)!=2):
    print "must provide path to network as unique parameter"
    exit()

net_file = open(sys.argv[1])
found_size = false
while (not found_size):
    line = net_file.readline()
    if(line[0]=="p"):
        tokens = line.split(" ")
        graph_size = (int) tokens[2]

print "#graph size is: %d" % graph_size
for i in range(30):
    print "./build/dijkstra %d %d < %s" % (randint(1,graph_size),randint(1,graph_size), sys.argv[1])


 
