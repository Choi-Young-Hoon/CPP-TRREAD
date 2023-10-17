#include <iostream>
#include <thread>

int main(void) {
    std::thread thread1([](){
        std::cout << "Thread hello" << std::endl;
    });

    thread1.join();
    return 0;
}