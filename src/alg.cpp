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

    for (int i = 0; i < len; i++) {
        int target = value - arr[i];

        int left = i + 1;
        int right = len - 1;
        int found = -1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] == target) {
                found = mid;
                break;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (found != -1) {
            int cnt = 1;

            int l = found - 1;
            while (l >= i + 1 && arr[l] == target) {
                cnt++;
                l--;
            }

            int r = found + 1;
            while (r < len && arr[r] == target) {
                cnt++;
                r++;
            }

            count += cnt;
        }
    }

    return count;
}
