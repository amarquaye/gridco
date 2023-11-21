#include <iostream>
#include <string>

int main(){
    std::string ans1, ans2, ans3, ans4, ans5;
    bool isMale;

    std::cout << "==================== Welcome to the Sexuality Assessment Test ===================" << std::endl;
    std::cout << "Please answer a few of our questions to determine your Sexuality." << std::endl;
    std::cout << "Please answer with yes or no" << std::endl;
    std::cout << "Are you a male?" << std::endl;
    std::cin >> ans1; //Male or Female
    std::cout << "Are you attracted to males?" << std::endl;
    std::cin >> ans2; //Gay or straight
    std::cout << "Are you attracted to females?" << std::endl;
    std::cin >> ans3; //Gay or straight
    std::cout << "Are you attracted to both genders?" << std::endl;
    std::cin >> ans4; //Bisexual
    std::cout << "Are you attracted to anything?" << std::endl;
    std::cin >> ans5; //Pansexual

    if(ans1 == "yes"){
        //Male
        if(ans2 == "no" && ans3 == "yes" && ans4 == "no" && ans5 == "no"){
            //Straight
            std::cout << "You are a straight Male!!" << std::endl;
        }
        else if(ans2 == "yes" && ans3 == "no" && ans4 == "no" && ans5 == "no"){
            //Gay
            std::cout << "You are a Gay!!" << std::endl;
        }
        else if(ans2 == "yes" && ans3 == "yes" && ans4 == "yes" && ans5 == "no"){
            //Bisexual
            std::cout << "You are a Bisexual!!" << std::endl;
        }
        else if(ans2 == "yes" && ans3 == "yes" && ans4 == "yes" && ans5 == "yes"){
            //Pansexual
            std::cout << "You are a Pansexual!!" << std::endl;
        }
        else if(ans2 == "no" && ans3 == "no" && ans4 == "no" && ans5 == "no"){
            //Uncertain
            std::cout << "You are uncertain about your sexuality!!" << std::endl;
        }
    }
    else{
        //Female
        if(ans2 == "yes" && ans3 == "no" && ans4 == "no" && ans5 == "no"){
            //Straight
            std::cout << "You are a straight Female!!" << std::endl;
        }
        else if(ans2 == "no" && ans3 == "yes" && ans4 == "no" && ans5 == "no"){
            //Gay
            std::cout << "You are a Lesbian!!" << std::endl;
        }
        else if(ans2 == "yes" && ans3 == "yes" && ans4 == "yes" && ans5 == "no"){
            //Bisexual
            std::cout << "You are a Bisexual!!" << std::endl;
        }
        else if(ans2 == "yes" && ans3 == "yes" && ans4 == "yes" && ans5 == "yes"){
            //Pansexual
            std::cout << "You are a Pansexual!!" << std::endl;
        }
        else if(ans2 == "no" && ans3 == "no" && ans4 == "no" && ans5 == "no"){
            //Uncertain
            std::cout << "You are uncertain about your sexuality!!" << std::endl;
        }
    }

}
