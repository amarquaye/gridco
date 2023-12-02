import sys


def main():
    """Main function"""

    word = sys.argv[1]
    file = sys.argv[2]

    # Open file in read mode
    with open(file, "r") as filename:
        contents = filename.read()
        if word in contents:
            print("Yes")
        else:
            print("No")


if __name__ == "__main__":
    main()
