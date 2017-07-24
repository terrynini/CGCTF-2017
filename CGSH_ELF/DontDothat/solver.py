from pwn import *


#which program we want to open
target = process("./DontDothat")

#recieve message from program
target.recvuntil("\n")


payload = ""

MYSET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_"

for a in MYSET:
    for b in MYSET:
        for c in MYSET:
            payload = a + b + c
            #this send the message with \n
            target.sendline(payload)
            message = target.recvuntil("\n")
            if("flag" in message):
                print "flag is : " + payload
                break



