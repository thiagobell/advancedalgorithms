#!/bin/bash

for f in testcase/*gr
do
  ./build/matching -v < $f;
done;
