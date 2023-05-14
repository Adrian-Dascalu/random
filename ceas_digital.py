a = g = d = [" ", "_"]
b = c = e = f = [" ", "|"]
p = [" ", "."]

zero = (a[0], a[1], a[0], f[1], g[0], b[1], e[1], d[1], c[1])
unu = (a[0], a[0], a[0], f[0], g[0], b[1], e[0], d[0], c[1])
doi = (a[0], a[1], a[0], f[0], g[1], b[1], e[1], d[1], c[0])
trei = (a[0], a[1], a[0], f[0], g[1], b[1], e[0], d[1], c[1])
patru = (a[0], a[0], a[0], f[1], g[1], b[1], e[0], d[0], c[1])
cinci = (a[0], a[1], a[0], f[1], g[1], b[0], e[0], d[1], c[1])
sase = (a[0], a[1], a[0], f[1], g[1], b[0], e[1], d[1], c[1])
sapte = (a[0], a[1], a[0], f[0], g[0], b[1], e[0], d[0], c[1])
opt = (a[0], a[1], a[0], f[1], g[1], b[1], e[1], d[1], c[1])
noua = (a[0], a[1], a[0], f[1], g[1], b[1], e[0], d[1], c[1])

digits = [zero, unu, doi, trei, patru, cinci, sase, sapte, opt, noua]

from datetime import datetime
import time
import sys, os

while(1):
    ora = datetime.now().strftime('%H')
    minut = datetime.now().strftime('%M')
    secunda = datetime.now().strftime('%S')
    ms = datetime.now()
    ms = int(ms.microsecond / 10000)
    
    if(ms < 10):
        ms = str(ms)
        ms = '0' + ms

    ms = str(ms)

    ceas = [digits[int(ora[0])], digits[int(ora[1])], digits[int(minut[0])], digits[int(minut[1])], digits[int(secunda[0])], digits[int(secunda[1])], digits[int(ms[0])], digits[int(ms[1])]]

    c = 0

    os.system('cls')

    for i in range(3):
        for j in ceas:
            for char in j[i * 3 : i * 3 + 3]:
                print(char, end = "")

            if((i == 2 or i == 1) & (c % 2 == 1) & (c > 8) & (c < 22) & (c != 15)):
                print(p[1], end = "")
            elif(c % 2 == 0):
                pass
            else:
                print(p[0], end = "")

            c += 1
        print()
    
    time.sleep(0.05)

"""for row in range(3):
    for digit in digits:
        for char in digit[row*3:row*3+3]:
            print(char, end="")
        print(p[0], end="")
    print()

for i in range(3):
    for j in digits:
        for char in j[i*3:i*3+3]:
            print(char, end = "")
        if(i == 2):
            print(p[1], end = "")
        else:
            print(p[0], end = "")
    print()"""