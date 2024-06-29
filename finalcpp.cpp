class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        int result;

        for (int i = log10(n); i >= 0; i--) {
            result = n / pow(10, (i))
                - (n / static_cast<int>(pow(10, i + 1)) * 10);
            product *= result;
        	sum += result;
        }
        return (product - sum);
    }
};
