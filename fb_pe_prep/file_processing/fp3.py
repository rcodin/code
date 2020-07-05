import sys
import os
import time

def process_file (filename):
    with open(filename) as f:
        f_arr = f.read()
    f_arr = f_arr.strip().replace(" ", "").replace("\t", "")
    f_arr = f_arr.split(",")
    f_arr = [int (e) for e in f_arr]
    return f_arr

def print_file (filename, arr):
    with open(filename, 'w') as f:
        for e in arr[:-1]:
            f.write(str(e))
            f.write(",")
        f.write(str(arr[-1:][0]))

def main ():
    if len(sys.argv) != 4:
        print ("Error: wrong input format")
        exit (1)
    file1_name = sys.argv[1]
    file2_name = sys.argv[2]
    file3_name = sys.argv[3]
    arr1 = process_file (file1_name)
    arr2 = process_file (file2_name)
    arro = []
    for e1, e2 in zip (arr1, arr2):
        arro.append(e1 + e2)
    r_arr1 = arr1[min(len(arr1), len(arr2)): len (arr1)] 
    r_arr2 = arr1[min(len(arr1), len(arr2)): len (arr2)] 
    for e in r_arr1:
        arro.append(e)

    for e in r_arr2:
        arro.append(e)

    print_file (file3_name, arro)
    
if __name__=="__main__":
    main()
