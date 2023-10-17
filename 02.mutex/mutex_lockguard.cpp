#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

int main(void) {
    std::mutex mutex;

    std::vector<std::thread> threadList;
    for (int i = 0; i < 10; i++) {
        threadList.push_back(std::thread([&](){
            std::lock_guard<std::mutex> lock(mutex); // 소멸될때까지 lock
            std::cout << std::this_thread::get_id() << " Hello World@@@@@@@@@@" << std::endl;
            std::cout << std::this_thread::get_id() << " Hello World!!!!!!!!!!" << std::endl;
        }));
    }

    for (auto& iter : threadList) {
        iter.join();
    }

    return 0;
}