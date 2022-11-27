// naive script 
void quickSort(vector<int> arr, int low, int high) {
      if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
      }
    }
        int partition(vector<int> array, int low, int high) {
            int pivot = array[high];
                int i = (low - 1);
                for (int j = low; j < high; j++) {
                    if (array[j] <= pivot) {
                    i++;
                    swap(array[i], array[j]);
                    }
                }
                swap(array[i + 1], array[high]);
                return (i + 1);
    }
