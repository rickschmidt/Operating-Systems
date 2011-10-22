#!/usr/pkg/bin/bash
START=$(date +%s)
./hw3io 2 &
./hw3cpu 2 &
./hw3mix 1 2 &
wait
END=$(date +%s)
DIFF=$(($END-$START))
echo "Total execution time: $DIFF seconds."