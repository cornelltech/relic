#!/bin/bash 
# Build RELIC with our ABI
set -e

RELIC_ROOT=../
SRC=$RELIC_ROOT/src
FULL_ABI=full-abi.json
ABI_JSON=abi-description.json

echo "Building relic_abi.c"

# Remove comments from full-abi because the Python JSON parser freaks out
grep -v "//" $FULL_ABI > $ABI_JSON

python abiBuilder.py $ABI_JSON | cat preamble.c - > relic_abi.c 
cp relic_abi.c $SRC

echo "Building RELIC"
# if make -C $RELIC_ROOT 1>/dev/null 2>&1; then
#     echo "OK"
# else
    # Run it again without supressing output so we can see the errors
    make -C $RELIC_ROOT
# fi