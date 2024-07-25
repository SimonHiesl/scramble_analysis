# Generating Scramble

For the random state scrambles, the [min2phase](https://github.com/lilborgo/min2phaseCXX) algorithm was used.

### Usage:

```sh
git clone git@github.com:lilborgo/min2phaseCXX.git
cd min2phaseCXX
cmake CMakeLists.txt
make
g++ -I include/ gen.cpp -L. -lmin2phase -o scramble -Wl,-rpath,.
```

With `gen.cpp` as:
```cpp
#include <chrono>
#include <iostream>
#include <string>
#include <fstream>

#include <min2phase/min2phase.h>
#include <min2phase/tools.h>

int main(int argc, char *argv[]){
    uint8_t movesUsed;
    min2phase::tools::setRandomSeed(time(nullptr));
    std::ofstream outFile("output.txt");
    min2phase::loadFile("coords.m2pc");
    for (int i = 0; i < 1'000'000; ++i) {
        std::string str = min2phase::solve(min2phase::tools::randomCube(), 28, 100000, 0, min2phase::INVERSE_SOLUTION, &movesUsed);
        outFile << str << '\n';
    }
    outFile.close();
    return 0;
}
```
Each execution of `./scramble` generates one million random state scrambles.
With `./rm_trailing.sh` the 
To automate the generation, the `./generate.sh' script can be used.
