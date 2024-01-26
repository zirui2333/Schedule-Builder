//Prompt user for a list of event
#include <iostream>
#include <fstream>

int main(int argc, const char * argv[]) {
    std::fstream file;
    openFile(file);
    
    Schedule::BuildVersion(file);
    //Make a new shcedule and store into vector<schedule*>;
    //Make another one, let's make 3 versions. Morning, afternoon, night;
    
    
    
    Schedule::Show();
    
    std::cout << "Choose the version you like to keep!\n";
    
    Schedule::Keep(std::cin.get());
    
    MySchedule m (Schedule::Get());
    
    std::cout << "Your schedule is successfully created, please stick with it! \n";
    return 0;
}


void openFile(std::fstream& file){
    std::cout << "Enter the name of your schdule: ";
    std::string file_name;
    std::cin >> file_name;
    
    file.open(file_name);
    
    while(file.fail()){
        std::cout << "Please enter a correct file name\n";
        std::cin >> file_name;
        file.open(file_name);
    }

}

