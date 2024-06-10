#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <chrono>

using namespace std;

void solveWithArray(int N, int M, int S, int K, int L) {
    vector<char> mice;
    for (int i = 0; i < N; ++i) mice.push_back('G'); 
    for (int i = 0; i < M; ++i) mice.push_back('W'); 

    int current = 0;
    while (N > K || M > L) {
        current = (current + S - 1) % mice.size();
        if (mice[current] == 'G') --N;
        else --M;
        mice.erase(mice.begin() + current);
    }

    for (char mouse : mice)  cout << mouse << " ";
     cout << endl;
}

void solveWithLinkedList(int N, int M, int S, int K, int L) {
     list<char> mice;
    for (int i = 0; i < N; ++i) mice.push_back('G');
    for (int i = 0; i < M; ++i) mice.push_back('W');

    auto it = mice.begin();
    while (N > K || M > L) {
        for (int i = 0; i < S - 1; ++i) {
            ++it;
            if (it == mice.end()) it = mice.begin();
        }
        auto to_remove = it;
        if (++it == mice.end()) it = mice.begin();

        if (*to_remove == 'G') --N;
        else --M;

        mice.erase(to_remove);
    }

    for (char mouse : mice)  cout << mouse << " ";
     cout << endl;
}

void solveWithDeque(int N, int M, int S, int K, int L) {
    deque<char> mice;
    for (int i = 0; i < N; ++i) mice.push_back('G');
    for (int i = 0; i < M; ++i) mice.push_back('W');

    int current = 0;
    while (N > K || M > L) {
        current = (current + S - 1) % mice.size();
        if (mice[current] == 'G') --N;
        else --M;
        mice.erase(mice.begin() + current);
    }

    for (char mouse : mice) cout << mouse << " ";
    cout <<  endl;
}

int main() {

    system("chcp 1251");

    int N, M, S, K, L;
    cout << "Введите количество серых(G) мышей (N): ";
    cin >> N;
    cout << "Введите количество белых(W) мышей (M): ";
    cin >> M;
    cout << "Введите размер шага (S): ";
    cin >> S;
    cout << "Введите оставшееся количество серых мышей (K): ";
    cin >> K;
    cout << "Введите оставшееся количество белых мышей(L): ";
    cin >> L;

    auto start = std::chrono::high_resolution_clock::now();
    solveWithArray(N, M, S, K, L);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationArray = end - start;
    std::cout << "Array implementation took " << durationArray.count() << " seconds." << std::endl;

    start = std::chrono::high_resolution_clock::now();
    solveWithLinkedList(N, M, S, K, L);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationLinkedList = end - start;
    std::cout << "Linked List implementation took " << durationLinkedList.count() << " seconds." << std::endl;

    start = std::chrono::high_resolution_clock::now();
    solveWithDeque(N, M, S, K, L);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationDeque = end - start;
    std::cout << "Deque implementation took " << durationDeque.count() << " seconds." << std::endl;

    return 0;
}

