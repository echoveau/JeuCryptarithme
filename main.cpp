#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    std::vector<string> mots;

    
    for(int i = 1; i<argc; i++){
        mots.push_back(argv[i]);
    }
    
    std::cout<<mots[0][0]<<std::endl;

 
    return 0;
}

