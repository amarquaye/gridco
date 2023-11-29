""" 
    Program to determine the sexuality of an individual.
    By Jesse Amarquaye.
    Engineering and Operations Branch, MIS.
    Assignment 1.
    
"""


print("Welcome To The Sexuality Assessment")

try:
    ask_gender = input("Enter your gender. Type 'M' for male and 'F' if you are a Female: " )

    print("Enter 'Y' for Yes or 'N' for No to the following questions to determine your sexuality")

    male_attraction = input("Are you attracted to males? ")
    female_attraction = input("Are you attracted to females? ")
    pan = input("Are you attracted to anything? ")


    # Male Questions
    if ask_gender.lower() == "m":
        gender = "male"

        if (male_attraction.lower() == "y") and (female_attraction.lower() == "y") and (pan.lower() == "y"):
            print("You are Pansexual")

        elif (male_attraction.lower() == "y") and (female_attraction.lower() == "y"):
            print("You are Bisexual")

        elif male_attraction.lower() == "y":
            print("You are Gay")

        elif male_attraction.lower() == "n":
            print("You are straight")

        # MISTAKE
        elif pan.lower() == "y":
            print("You are Pansexual")

        elif pan.lower() == "n":
            if male_attraction.lower() == "y":
                print("Youa are Gay")

            elif female_attraction.lower() == "y":
                print("You are Lesbian")

            elif male_attraction.lower() == "y" and female_attraction.lower() == "y":
                print("You are Bisexual")

            else:
                print("You are Uncertain about your sexuality")


    # Female Questions
    if ask_gender.lower() == "f":
        gender = "female"

        if (male_attraction.lower() == "y") and (female_attraction.lower() == "y") and (pan.lower() == "y"):
            print("You are Pansexual")

        elif (male_attraction.lower() == "y") and (female_attraction.lower() == "y"):
            print("You are Bisexual")

        elif male_attraction.lower() == "y":
            print("You are Straight")

        elif male_attraction.lower() == "n":
            print("You are Lesbian")

        elif pan.lower() == "y":
            print("You are Pansexual")

        elif pan.lower() == "n":
            if male_attraction.lower() == "y":
                print("Youa are Gay")

            elif female_attraction.lower() == "y":
                print("You are Lesbian")

            elif male_attraction.lower() == "y" and female_attraction.lower() == "y":
                print("You are Bisexual")

            else:
                print("You are Uncertain about your sexuality")

except Exception as e:
    print(f"Error {e}")
