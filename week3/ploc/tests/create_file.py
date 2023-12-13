"""Program to create random files and dump text into it"""
import sys


def main():
    filename = sys.argv[1:]

    for files in filename:
        with open(files, "w") as f:
            for i in range(1,100):
                f.write("""
def main():
    print("Hello world")
    
if __name__ == "__main__":
    main()
""" * i)
        

if __name__ == "__main__":
    main()
