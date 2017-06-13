#include <iostream>
#include <fstream>                                                  // for file stream

const int MAX = 100000;
int buff[MAX];

int main() {
    for (int i = 0; i < MAX; i++) {
        buff[i] = i;
    }
        std::ofstream os("edata.dat", std::ios::binary);            //write file
        os.write(reinterpret_cast<char *>(buff), MAX * sizeof(int));

        os.close();                                                 // must close it

        for (int j = 0; j < MAX; j++) {                             // erase buffer
            buff[j] = 0;
        }
        std::ifstream is("edata.dat", std::ios::binary);            // create input stream
        is.read(reinterpret_cast<char*>(buff), MAX * sizeof(int));  // read from it

        for (int k = 0; k < MAX; k++) {
            if (buff[k] != k)
            {
                std::cerr << "Data is incorrect\n";
                return 1;
            }
        }
        std::cout << "Data is correct\n";


   std::cin.get();
    return 0;
}