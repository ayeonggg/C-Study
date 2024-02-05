#include <iostream>
#include <vector>


class Sort {
private:
    int left;
    int middel;
    int right;

public:  
    void merge(std::vector<int>& arr, int left, int middle, int right) {
        int n1 = middle - left + 1;
        int n2 = right - middle;

        std::vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i]; //array에 가운데 기준 왼쪽 값 복사
        for (int j = 0; j < n2; j++)
            R[j] = arr[middle + 1 + j];//array에 가운데 기준 오른쪽 값 복사

        
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        } //나누어준 숫자들 복사하며 병합

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }//오른쪽 남은 값들 복사
    }

    void partition(std::vector<int>& arr, int left, int right) {
        if (left < right) {
            int middle = left + (right - left) / 2;

            //합병 전 분할 과정
            partition(arr, left, middle);
            partition(arr, middle + 1, right);

            merge(arr, left, middle, right);
        }
    }

    void mergeSort(std::vector<int>& arr) {
        partition(arr, 0, arr.size() - 1);
    }
};
