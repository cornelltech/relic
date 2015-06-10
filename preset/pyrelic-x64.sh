#!/bin/bash 
# These settings were selected to get very good performance on a 
# 64-bit Intel architecture using the BN pairing-based curves for the 
# Pythia protocol.

cmake -DALLOC=AUTO -DARITH=gmp \
    -DFP_QNRES=on -DFP_PRIME=254 -DCHECK=off \
    -DCOMP="-O3 -funroll-loops -fomit-frame-pointer -march=native -mtune=native" \
    -DFP_METHD="BASIC;COMBA;COMBA;MONTY;LOWER;SLIDE" \
    -DFPX_METHD="INTEG;INTEG;LAZYR" \
    -DPP_METHD="LAZYR;OATEP" $1
