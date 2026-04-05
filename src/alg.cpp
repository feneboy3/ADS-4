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

            while (arr[left] == lval) {
                lcount++;
                left++;
            }

            while (arr[right] == rval) {
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

// бинарный поиск первого >= target
int lowerBound(int *arr, int left, int right, int target) {
    int res = right + 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] >= target) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}

// бинарный поиск первого > target
int upperBound(int *arr, int left, int right, int target) {
    int res = right + 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] > target) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len; i++) {
        int target = value - arr[i];

        int l = lowerBound(arr, i + 1, len - 1, target);
        int r = upperBound(arr, i + 1, len - 1, target);

        if (l < len && arr[l] == target) {
            count += (r - l);
        }
    }

    return count;
}
