#!/usr/bin/python3
import os
import sys

# retuns array of numbers
def read_nums (path):
    nums = []
    with open (path) as fnum:
        for line in fnum:
            line = line.strip()
            line = line.replace(" ", "").replace("\t", "")
            line = line.split(",")
            try:
                line = [ int(i) for i in line]
            except ValueError as ve:
                print(f'You entered {line}, which has elements which are not number.')
                exit(1)
            nums.extend(line)
    return nums

def main():
    nums = read_nums("fnum.csv")
    print (sum(nums))
if __name__=="__main__":
    main()
