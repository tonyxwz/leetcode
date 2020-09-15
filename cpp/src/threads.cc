#include <iostream>
#include <thread>
#include <vector>

void thread_func() {
    std::cout << std::this_thread::get_id() << std::endl;
}

int main() {
    std::thread tr1(thread_func);
    std::cout << "main" << std::endl;
    tr1.join();
    return 0;
}