#!/usr/bin/env python3
import sys
import argparse

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--N",type=int,help="matrix size",default=8*1024)
    parser.add_argument("--filename",type=str,help="output filename",
        default="matrix.txt")
    args = parser.parse_args()

    filename, N = args.filename, args.N

    with open(filename,'w') as f:
        print(N,file=f)
        for i in range(N):
            for j in range(N):
                print(j,file=f,end=' ')
            print(file=f)