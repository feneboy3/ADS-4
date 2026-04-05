// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }

    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }

            int lval = arr[left];
            int rval = arr[right];

            int lcount = 0;
            int rcount = 0;

            while (left < len && arr[left] == lval) {
                lcount++;
                left++;
            }

            while (right >= 0 && arr[right] == rval) {
                rcount++;
                right--;
            }

            count += lcount * rcount;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }

    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len; ) {
        int x = arr[i];
        int countX = 0;

        while (i < len && arr[i] == x) {
            countX++;
            i++;
        }

        int target = value - x;

        int left = i;
        int right = len - 1;
        int first = -1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] == target) {
                first = mid;
                right = mid - 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (first != -1) {
            int countY = 0;
            int idx = first;

            while (idx < len && arr[idx] == target) {
                countY++;
                idx++;
            }

            if (x < target) {
                count += countX * countY;
            } else if (x == target) {
                count += countX * (countX - 1) / 2;
            }
        }
    }

    return count;
}
