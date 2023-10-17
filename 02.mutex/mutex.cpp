#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

int main(void) {
    std::mutex mutex;

    std::vector<std::thread> threadList;
    for (int i = 0; i < 10; i++) {
        threadList.push_back(std::thread([&](){
            mutex.lock(); // Lock@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@2
            std::cout << std::this_thread::get_id() << " Hello World@@@@@@@@@@" << std::endl;
            std::cout << std::this_thread::get_id() << " Hello World!!!!!!!!!!" << std::endl;
            mutex.unlock(); // Unlock@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
        }));
    }

    for (auto& iter : threadList) {
        iter.join();
    }

    return 0;
}