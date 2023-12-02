import sys


def main():
    """Main function"""

    word = sys.argv[1]
    file = sys.argv[2]

    try:
        # Open file in read mode
        with open(file, "r") as filename:
            contents = filename.read()
            if word in contents:
                print(f"Yes, {word} is in {file}")
            else:
                print(f"No, cannot find {word} in {file}")
    except Exception as e:
        print(f"Error, {e}")


if __name__ == "__main__":
    main()
