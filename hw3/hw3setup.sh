#!/usr/pkg/bin/bash
START=$(date +%s)
./hw3io &
./hw3cpu &
./hw3mix .5 .5 &
wait
END=$(date +%s)
DIFF=$(($END-$START))
echo "Total execution time: $DIFF seconds."