#!/usr/bin/python3

import os
import sys
import csv

# process file1 and return it in structured form
def process_f1(path):
    f1_processed = {}
    with open(path, "r") as f1:
        for line in f1:
            line = line.replace(" ", "").replace("\t", "")
            line = line.strip().split(",")
            name = line[0]
            val1 = line[1]
            f1_processed[name] = [val1]
    return f1_processed

# process file2 and return it in structured form
def process_f2(path):
    f2_processed = {}
    with open(path, "r") as f2:
        for line in f2:
            line = line.replace(" ", "").replace("\t", "")
            line = line.strip().split(",")
            name = line[0]
            val2 = line[1]
            val3 = line[2]
            f2_processed[name] = [val2, val3]
    return f2_processed

#process file3
def process_f3(path, f1_p, f2_p):
    with open(path, "w") as f3:
        for key in f1_p:
            line = "{:<10}".format(key) + " " + "{:<10}".format(f1_p[key][0])
            if key in f2_p:
                val2 = f2_p[key][0]
                val3 = f2_p[key][1]
                line = line + " " + "{:<10}".format(val2) + " " + "{:<10}".format(val3)
            f3.write(line + "\n")

        for key in f2_p:
            line = "{:<10}".format(key) + " " + "{:<10}".format("")
            if key not in f1_p:
                val2 = f2_p[key][0]
                val3 = f2_p[key][1]
                line = line + " " + "{:<10}".format(val2) + " " + "{:<10}".format(val3)
                f3.write(line + "\n")

def main ():
    p_f1 = process_f1("file1.csv")
    p_f2 = process_f2("file2.csv")
    process_f3("file3.csv", p_f1, p_f2)

if __name__=="__main__":
    main()
