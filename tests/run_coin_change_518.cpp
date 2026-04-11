// Problem (short):
// Solve the run_coin_change_518 problem and return the required result.

#include <iostream>
#include <vector>
#include "../518. Coin Change II.cpp"

int main() {
    Solution sol;
    int amount = 5;
    std::vector<int> coins = {1,2,5};
    int res = sol.change(amount, coins);
    std::cout << "Result: " << res << std::endl;
    return 0;
}
