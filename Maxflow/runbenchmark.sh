#!/bin/bash

for file in testnets/*.gr
do
#  echo $(basename $file)
  echo "/usr/bin/time -v ./build/maxflow < $file &> benchmarks/$(basename $file)"
  wait

done
