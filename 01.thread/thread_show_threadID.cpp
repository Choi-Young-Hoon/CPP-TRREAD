#include <iostream>
#include <thread>

int main(void) {
    std::thread thread1([](){
        std::cout << "current thread id: " << std::this_thread::get_id() << std::endl;
    });
    thread1.join();
    
    std::cout << "main thread id: " << std::this_thread::get_id() << std::endl;
    return 0;
}