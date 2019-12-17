#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{

    std::cout<<argc<<std::endl;
    for(int i = 1; i<argc; i++){
        std::cout<<argv[i]<<std::endl;
    }
    

 
    return 0;
}

