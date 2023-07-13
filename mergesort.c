// Function to merge arrays

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int s1 = mid - left + 1;
    int s2 = right - mid;

    /* It will create two temporary arrays */
    int left_arr[s1], right_arr[s2];

    /* It will copy data from arr to temporary arrays */
    for (i = 0; i < s1; i++)
        left_arr[i] = arr[left + i];

    for (j = 0; j < s2; j++)
        right_arr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < s1 && j < s2) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        }
        else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < s1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < s2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

// Defining the merge sort function
void merge_sort(int arr[], int left, int right)
{
    // checking for the base condition
    if (left < right) {

        // finding the mid value of the array.
        int mid = left + (right - left) / 2;

        // Calling the merge sort for the first half
        merge_sort(arr, left, mid);

        // Calling the merge sort for the second half
        merge_sort(arr, mid + 1, right);

        // Calling the merge function
        merge(arr, left, mid, right);
    }
}

int main()
{
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, size - 1);

    printf("Sorted array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
