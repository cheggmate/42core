#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <sstream>
# include <cstdlib>
# include <ctime>
# include <algorithm>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int>  _deq;
    double           _vecTime;
    double           _deqTime;

    void sortVector(std::vector<int>& v);

    void sortDeque(std::deque<int>& d);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void parseInput(int argc, char** argv);
    void execute();
};

#endif