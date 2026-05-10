#include <cstdint>
#include <iostream>

int main(){
    uint64_t size = 1844674407370955164;
    std::cout<<"sizeOf void*: " << sizeof(void*) << "\n";
    std::cout<<"sizeOf $size: " << size << "\n";
    std::cout<<"sizeOf ~(sizeof(void*) - 1): " << ~(sizeof(void*) - 1) << "\n";
 // size delimiter
    size = (size + sizeof(void*) - 1) & ~(sizeof(void*) + 1);
    std::cout <<"sizeOf $size: " << size << "\n";
    return 0;
}
