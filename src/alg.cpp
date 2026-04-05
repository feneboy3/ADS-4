// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int total = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                total += 1;
            }
        }
    }
    return total;
}

int countPairs2(int *arr, int len, int value) {
    int total = 0;
    int start = 0;
    int end = len - 1;

    while (start < end) {
        int sum = arr[start] + arr[end];
        if (sum == value) {
            if (arr[start] == arr[end]) {
                int n = end - start + 1;
                total += n * (n - 1) / 2;
                break;
            } else {
                int leftVal = arr[start];
                int rightVal = arr[end];
                int leftCount = 0, rightCount = 0;

                while (start <= end && arr[start] == leftVal) {
                    leftCount++;
                    start++;
                }
                while (start <= end && arr[end] == rightVal) {
                    rightCount++;
                    end--;
                }
                total += leftCount * rightCount;
            }
        } else if (sum < value) {
            start++;
        } else {
            end--;
        }
    }

    return total;
}

// Вспомогательные функции для бинарного поиска
int findFirstOccurrence(int *arr, int left, int right, int target) {
    int res = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            res = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return res;
}

int findLastOccurrence(int *arr, int left, int right, int target) {
    int res = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            res = mid;
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return res;
}

int countPairs3(int *arr, int len, int value) {
    int total = 0;
    int index = 0;

    while (index < len) {
        int currentVal = arr[index];
        int countCurrent = 1;

        while (index + countCurrent < len && arr[index + countCurrent] == currentVal) {
            countCurrent++;
        }

        int target = value - currentVal;

        if (target == currentVal) {
            total += countCurrent * (countCurrent - 1) / 2;
        } else if (target > currentVal) {
            int first = findFirstOccurrence(arr, index + countCurrent, len - 1, target);
            if (first != -1) {
                int last = findLastOccurrence(arr, first, len - 1, target);
                int countTarget = last - first + 1;
                total += countCurrent * countTarget;
            }
        }

        index += countCurrent;
    }

    return total;
}
