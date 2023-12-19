'''
There are 2 text segments separated by a blank line. Top portion is a byte map of 256 values. Bottom is the obfuscated payload.

Place square brackets around the 2 text segments
keylist = ["protobasidiomycetous", "frigatoon", ...]
payload = ["superdelicately", "overdescribing", ...]

Rename challenge.txt to dailyctf_segway.py

=========
Output should be an executable ELF, which can be confirmed in the file header (first 4 bytes of file).
Running will produce a segfault.
Using a debugger will lead logic to the faulty function.
Modify the first couple nops AFTER the final (push rax) into jmp rdi
Function should now jump to final stage.
Set breakpoint on the rot47 loop and step through to reveal flag
'''
from dailyctf_segway import *

result = []

# Each word in the payload is matched against the key. 
# The key index represents the byte value (0 - 255)
for word in payload:
    result.append(keylist.index(word))

# Convert from list of ints to bytes
result = bytes(result)

# Save as raw bytes
f = open("segway.bin", "wb")
f.write(temp)
f.close()
