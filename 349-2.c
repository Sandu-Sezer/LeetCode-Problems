/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare (const void * a, const void * b) {
   return (*(int*)a - *(int*)b);
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* rez = (int*) malloc(sizeof(int) * ((nums1Size < nums2Size) ? nums1Size : nums2Size));
    
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;

    while (counter1 < nums1Size && counter2 < nums2Size){
        if (nums1[counter1] < nums2[counter2]){
            counter1++;
        } else if (nums1[counter1] > nums2[counter2]){
            counter2++;
        } else if (nums1[counter1] == nums2[counter2]){
            if (counter3 == 0 || rez[counter3 - 1] != nums1[counter1]){
                rez[counter3++] = nums1[counter1];
            }
            counter1++;
            counter2++;
        }
    }

    *returnSize = counter3;

    return rez;
}

