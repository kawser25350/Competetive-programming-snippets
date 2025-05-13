import sys

def solve():
    pass
    

def main():
    try:
        sys.stdin = open('input.txt', 'r')
        sys.stdout = open('output.txt', 'w')
    except:
        pass

    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
