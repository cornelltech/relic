#!/usr/bin/env python
"""
Converts an ABI description into C code.
"""

import json, collections

# All trampoline functions are given the _abi suffix to ensure unique names
suffix = "_abi"

# Trampoline function template
template = "{returns} {function}{suffix}({ptypes}) {{ {returnStatement}{function}({plist}); }}"


def convertAbi(abiFilename):
    """
    Reads an ABI descruption from a JSON file (@abiFilename) and outputs a
    C program made of trampoline functions.
    """
    # Open, read, and parse the JSON description file.
    with open(abiFilename, 'r') as abiF:
        abi = json.load(abiF)

    # Print the preamble
    if "preamble" in abi:
        write("\n".join(abi["preamble"]))
        write("")

    # Process each bundle in the ABI description
    for bundle in abi["bundles"].iteritems():
        name, functions = bundle

        # Write the name of the bundle
        write("// " + name)

        # Process each function in this bundle
        for f in functions:
            write(processFunction(f))


def write(s):
    print s


def ptypeString(d):
    """
    Generates a parameter string for function prototype from a list of 
    parameter names and types @d.
    """
    if not d:
        return "void"
    else:
        # Combine names and types into a C function prototype string
        names = d[::2]
        types = d[1::2]
        return ", ".join( [ "{} {}".format(t,n) for n,t in zip(names, types) ] )


def plistString(d):
    """
    Generates a parameter call string from a list of parameter names and 
    types @d.
    """
    if not d:
        return ""
    else:
        # Combine names into a C function call string
        names = d[::2]
        return ", ".join(names)


def processFunction(func):
    """
    Generates a function using the template and the function's description @f.
    """
    func = collections.defaultdict(str, func)

    # If return type is ommitted, assume void.
    if not func["returns"]:
        func["returns"] = "void"
    
    # Set the return statement string
    if func["returns"] == "void":
        func["returnStatement"] = ""
    else:
        func["returnStatement"] = "return "

    func["suffix"] = suffix
    func["ptypes"] = ptypeString(func["parameters"])
    func["plist"] = plistString(func["parameters"])

    return template.format(**func)


# Run!
if __name__ == "__main__":
    import sys

    if len(sys.argv) != 2:
        print "usage: {} ABI-FILE".format(sys.argv[0])
    else:
        convertAbi(sys.argv[1])
