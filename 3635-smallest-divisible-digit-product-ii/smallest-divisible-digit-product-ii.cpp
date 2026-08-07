class Solution {
public:
    int countFactors(long long value) {
        int count = 0;
        for (int i = 9; i > 1; i--) {
            while (value % i == 0) {
                value /= i;
                count++;
            }
        }
        if (value > 1) return INT_MAX;
        return count;
    }

    string getLexicographicallySmallestString(long long target, int count) {
        string result(count, ' ');
        count--;
        for (int i = 9; i > 1; i--) {
            while (target % i == 0) {
                result[count--] = '0' + i;
                target /= i;
            }
        }
        return result;
    }

    bool canCreateGreaterWithRemaining(string &number, int index, long long value) {
        int count = 0, length = number.size();
        vector<int> temp(10);
        for (int i = 9; i > 1; i--) {
            while (value % i == 0) {
                temp[i]++;
                value /= i;
                count++;
            }
        }
        int extraSpaces = length - index - count;
        temp[8] += temp[2] + temp[4];
        temp[2] = 0;
        temp[4] = 0;
        temp[9] += temp[3] + extraSpaces;
        temp[3] = 0;

        for (int i = 9; i >= 1; i--) {
            while (index < length && temp[i] > 0) {
                if (i > number[index] - '0') return true;
                if (i < number[index] - '0') return false;
                index++;
                temp[i]--;
            }
        }
        return true;
    }

    string smallestNumber(string number, long long target) {
        int length = number.size();
        int factorCount = countFactors(target);
        if (factorCount == INT_MAX) return "-1";
        if (factorCount > number.length()) {
            return getLexicographicallySmallestString(target, factorCount);
        }
        long long low = 0, high = length, value = -1, answer = -1;
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long current = target;
            bool zeroEncountered = false;
            for (int i = 0; i < mid; i++) {
                if (number[i] == '0') {
                    high = i;
                    zeroEncountered = true;
                    break;
                }
                current /= gcd(current, number[i] - '0');
            }
            if (zeroEncountered) continue;
            bool possible = false;
            if (mid == length) {
                if (current == 1) return number;
            } else {
                for (int i = max(1, number[mid] - '0'); i < 10; i++) {
                    long long newTarget = current / gcd(current, i);
                    int positionsRequired = countFactors(newTarget);
                    if (positionsRequired <= length - mid - 1 && (i > number[mid] - '0' || canCreateGreaterWithRemaining(number, mid + 1, newTarget))) {
                        value = i;
                        possible = true;
                        break;
                    }
                }
            }
            if (possible) {
                low = mid + 1;
                answer = mid;
            } else {
                high = mid - 1;
            }
        }
        long long current = target;
        if (answer == -1) {
            number = '0' + number;
            int index = length;
            for (int j = 9; j > 0; j--) {
                while (index > answer && current % j == 0) {
                    number[index--] = '0' + j;
                    current /= j;
                }
            }
            return number;
        }
        number[answer] = '0' + value;
        for (int i = 0; i <= answer; i++) {
            if (number[i] == '0') continue;
            current /= gcd(current, number[i] - '0');
        }
        int index = length - 1;
        for (int j = 9; j > 0; j--) {
            while (index > answer && current % j == 0) {
                number[index--] = '0' + j;
                current /= j;
            }
        }
        return number;
    }
};