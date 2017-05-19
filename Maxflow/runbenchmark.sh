#!/bin/bash

for file in nets/*.gr
do
  echo $(basename $file)
  /usr/bin/time -v ./build/maxflow < $file &> benchmarks/$(basename $file)
  wait

done
