ABI Builder
============

RELIC makes extensive use of C macros for function-like definitions. This is quite fast, but makes it nearly impossible to interface with from Python. These scripts perform straightforward C code generation that creates proper C function entry points so that macro functions can be accessed from Python (or any other  language that seeks to access these functions) at runtime.

The ABI is generated from a JSON file that describes the function signatures.

Currently, only a subset of all RELIC macros are listed.
