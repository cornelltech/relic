#!/usr/bin/env python
"""
Extracts an ABI description using very specific heuristics for certain RELIC 
modules. Presently: relic_pc and relic_ec moudules.
"""
import json, collections, re

# A table of known parameter names and their most likely data types.
# This currently only works for relic_pc.h
paramNameTable = \
{ 
    # Function prefix types (g1_t, g2_t, gt_t)
    "A" : "PREFIX",
    "P" : "PREFIX",
    "Q" : "PREFIX",
    "R" : "PREFIX",
    "G" : "PREFIX",

    # Table of type prefix*
    "T" : "PREFIX-PTR",

    # D = digit
    "D" : "dig_t",

    # B = buffer, M = message
    "B" : "byte*",
    "M" : "byte*",

    # L = length, C = compression flag
    "L" : "int",
    "C" : "int",

    # common params that are multiprecision int
    "K" : "bn_t",
    "N" : "bn_t",
    "X" : "bn_t",
    "Y" : "bn_t",    
    "H" : "bn_t",
}

# Known function name prefixes and the data types they operate on.
prefixTable = \
{
    "g1" : "g1_t",
    "g2" : "g2_t",
    "gt" : "gt_t",
    "ec" : "ec_t",
}

def processFile(filename):
    """
    Reads a C header file and infers function definitions from macros.
    """
    # Read the file
    with open(filename) as f:

        # Process each line
        for line in f:
            desc = processLine(line)

            # Print any function descriptions that we find
            if desc:
                print json.dumps(desc) + ","


def processLine(line, debug=False):
    """
    Process a single line from a C file and returns a dictionary description
    of the function suitable from an ABI JSON file.
    """
    # Grab the function name and parameter list
    match = re.search("^#define ([\w]+)\((.*?)\)", line)
    if not match:
        return None

    # Grab function name and prefix
    fname = match.group(1)
    prefix = fname.split("_")[0]

    # Split up the parameter names
    paramNames = []
    if match.group(2):
        paramNames = match.group(2).split(", ")

    # Generate a list of parameter names and types
    params = []
    for p in paramNames:
        params.extend([p, inferType(p, prefix)])

    if debug:
        print fname, params
    
    # TODO: infer return type. So far: _is_ and _cmp_ seem to be tight fit
    #       to discovering non-void return types and I think these are always
    #       int return types.
    return { "function":fname, "returns":"void", "parameters":params }


def inferType(pname, prefix, default="int"):
    """
    Infers the type of a parameter using the paramNameTable
    """
    if pname not in paramNameTable.keys():
        print "// WARNING: Unknown parameter type: {}".format(pname)
        return default

    # Lookup the type in the table
    t = paramNameTable[pname]

    # Some keywords require further processing
    if t == "PREFIX" and prefix in prefixTable.keys():
        return prefixTable[prefix]

    if t == "PREFIX-PTR" and prefix in prefixTable.keys():
        return prefixTable[prefix] + "*"

    return t

# Run!
if __name__ == "__main__":
    import sys

    if len(sys.argv) != 2:
        print "usage: {} relic_file.h".format(sys.argv[0])
    else:
        processFile(sys.argv[1])
