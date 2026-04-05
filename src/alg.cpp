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

int countPairs3(int *arr, int len, int value) {
    int freq[101] = {0};

    for (int i = 0; i < len; i++) {
        freq[arr[i]]++;
    }

    int count = 0;

    for (int x = 0; x <= 50; x++) {
        int y = value - x;

        if (y < 0 || y > 100) continue;

        if (x < y) {
            count += freq[x] * freq[y];
        } else if (x == y) {
            count += freq[x] * (freq[x] - 1) / 2;
        }
    }

    return count;
}
