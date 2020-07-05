import csv

data = []
with open('sum.csv', newline='') as cfile:
    creader = csv.reader(cfile, delimiter=",")
    for r in creader:
        w_line = r
        r = [int(re) for re in r]
        w_line.append(sum(r))
        data.append(w_line)

with open('sum.csv', 'w', newline='') as cfile:
    cwriter = csv.writer(cfile, delimiter = ',')
    for r in data:
        cwriter.writerow(r)
