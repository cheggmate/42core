#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vecTime(0), _deqTime(0) {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->_vec = other._vec;
        this->_deq = other._deq;
        this->_vecTime = other._vecTime;
        this->_deqTime = other._deqTime;
    }
    return *this;
}

// generates Jacobsthal sequence values
static size_t getJacobsthal(size_t n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return getJacobsthal(n - 1) + 2 * getJacobsthal(n - 2);
}

void PmergeMe::parseInput(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.empty()) throw std::runtime_error("Error");
        
        for (size_t j = 0; j < arg.length(); ++j) {
            if (!std::isdigit(arg[j]) && !(j == 0 && arg[j] == '+'))
                throw std::runtime_error("Error");
        }
        
        long val = std::strtol(arg.c_str(), NULL, 10);
        if (val < 0 || val > 2147483647) 
            throw std::runtime_error("Error");
            
        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }
}

// vector ford-johnson
void PmergeMe::sortVector(std::vector<int>& v) {
    if (v.size() <= 1) return;

    bool hasStraggler = (v.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler) {
        straggler = v.back();
        v.pop_back();
    }

    // Create pairs and sort each pair so large element is first
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < v.size(); i += 2) {
        if (v[i] < v[i + 1])
            pairs.push_back(std::make_pair(v[i + 1], v[i]));
        else
            pairs.push_back(std::make_make_pair(v[i], v[i + 1]));
    }

    // Recursively sort pairs by their larger values (using a temporary vector)
    std::vector<int> largerElements;
    for (size_t i = 0; i < pairs.size(); ++i) {
        largerElements.push_back(pairs[i].first);
    }
    sortVector(largerElements);

    // Reorder our pairs map to match the sorted order of larger elements
    std::vector<std::pair<int, int> > sortedPairs;
    for (size_t i = 0; i < largerElements.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].first == largerElements[i]) {
                sortedPairs.push_back(pairs[j]);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    // Main chain initialization
    std::vector<int> mainChain;
    std::vector<int> pend;
    
    // First pend element always goes to the front of main chain
    if (!sortedPairs.empty()) {
        mainChain.push_back(sortedPairs[0].second);
    }
    for (size_t i = 0; i < sortedPairs.size(); ++i) {
        mainChain.push_back(sortedPairs[i].first);
        if (i > 0) pend.push_back(sortedPairs[i].second);
    }
    if (hasStraggler) pend.push_back(straggler);

    // Binary insertion using Jacobsthal index steps
    size_t inserted = 0;
    size_t jIndex = 3; 
    while (inserted < pend.size()) {
        size_t jacobNum = getJacobsthal(jIndex);
        size_t targetIndex = (jacobNum > pend.size()) ? pend.size() : jacobNum;
        
        // Insert backward from the target index down to the boundary
        for (size_t i = targetIndex; i > inserted; --i) {
            int item = pend[i - 1];
            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), item);
            mainChain.insert(pos, item);
        }
        inserted = targetIndex;
        jIndex++;
    }
    v = mainChain;
}

// ---------------- DEQUE FORD-JOHNSON ----------------
void PmergeMe::sortDeque(std::deque<int>& d) {
    if (d.size() <= 1) return;

    bool hasStraggler = (d.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler) {
        straggler = d.back();
        d.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < d.size(); i += 2) {
        if (d[i] < d[i + 1])
            pairs.push_back(std::make_pair(d[i + 1], d[i]));
        else
            pairs.push_back(std::make_pair(d[i], d[i + 1]));
    }

    std::deque<int> largerElements;
    for (size_t i = 0; i < pairs.size(); ++i) {
        largerElements.push_back(pairs[i].first);
    }
    sortDeque(largerElements);

    std::deque<std::pair<int, int> > sortedPairs;
    for (size_t i = 0; i < largerElements.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].first == largerElements[i]) {
                sortedPairs.push_back(pairs[j]);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    std::deque<int> mainChain;
    std::deque<int> pend;
    
    if (!sortedPairs.empty()) {
        mainChain.push_back(sortedPairs[0].second);
    }
    for (size_t i = 0; i < sortedPairs.size(); ++i) {
        mainChain.push_back(sortedPairs[i].first);
        if (i > 0) pend.push_back(sortedPairs[i].second);
    }
    if (hasStraggler) pend.push_back(straggler);

    size_t inserted = 0;
    size_t jIndex = 3;
    while (inserted < pend.size()) {
        size_t jacobNum = getJacobsthal(jIndex);
        size_t targetIndex = (jacobNum > pend.size()) ? pend.size() : jacobNum;
        
        for (size_t i = targetIndex; i > inserted; --i) {
            int item = pend[i - 1];
            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), item);
            mainChain.insert(pos, item);
        }
        inserted = targetIndex;
        jIndex++;
    }
    d = mainChain;
}

void PmergeMe::execute() {
    if (_vec.empty()) return;

    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); ++i) std::cout << _vec[i] << " ";
    std::cout << std::endl;

    std::clock_t start = std::clock();
    sortVector(_vec);
    std::clock_t end = std::clock();
    _vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6; // Microseconds

    start = std::clock();
    sortDeque(_deq);
    end = std::clock();
    _deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6; // Microseconds

    std::cout << "After:  ";
    for (size_t i = 0; i < _vec.size(); ++i) std::cout << _vec[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << _vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque  : " << _deqTime << " us" << std::endl;
}