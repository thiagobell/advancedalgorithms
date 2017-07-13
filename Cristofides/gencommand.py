files = ["berlin52.tsp","brd14051.tsp","fnl4461.tsp","pcb3038.tsp","pr2392.tsp","rl5915.tsp","rl5934.tsp","usa13509.tsp","vm1748.tsp"]
for f in files:
    print "echo '" + f  + "'"
    print "./build/cristofides -t < " + "testinputs/"+f + " > " + f +".ng \nwait"
    print "./build/cristofides -g -t < " + "testinputs/"+f + " > " + f +".g \nwait"
print "echo 'end'"
