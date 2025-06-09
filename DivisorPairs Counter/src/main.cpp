#include <iostream>
#include <limits> 
#include "ProblemSolver.h"
#include "DivisorCountSieve.h" 

int main() {
   
    DivisorCountSieve::getInstance();

    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int TotalNumberOfTestCases;
    std::cin >> TotalNumberOfTestCases;

    
    if (TotalNumberOfTestCases < 1 || TotalNumberOfTestCases > 1000000) {
        std::cerr << "Error: Number of test cases must be between 1 and 10^6." << std::endl;
        return 1; 
    }

    for (int currentTestCase = 0; currentTestCase < TotalNumberOfTestCases; ++currentTestCase) {
        int range;
        std::cin >> range;

        try {
            int result = ProblemSolver::solve(range);
            std::cout << result << "\n";
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error for range=" << range << " (Test Case " << currentTestCase + 1 << "): " << e.what() << "\n";
            return 1; 
        } catch (const std::out_of_range& e) {
            std::cerr << "Error for range=" << range << " (Test Case " << currentTestCase + 1 << "): " << e.what() << "\n";
            return 1; 
        } catch (const std::exception& e) {
            std::cerr << "An unexpected error occurred for range=" << range << " (Test Case " << currentTestCase + 1 << "): " << e.what() << "\n";
            return 1; 
        }
    }

    return 0; 
}