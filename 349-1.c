/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* rez = (int*) malloc(sizeof(int) * ((nums1Size < nums2Size) ? nums1Size : nums2Size));
   
    for (int i = 0; i < nums1Size - 1; i++){
        for (int j = 0; j < nums1Size - i - 1; j++){
            if (nums1[j] > nums1[j+1]){
                int aux = nums1[j];
                nums1[j] = nums1[j+1];
                nums1[j+1] = aux;
            }
        }
    }
    
    for (int i = 0; i < nums2Size - 1; i++){
        for (int j = 0; j < nums2Size - i - 1; j++){
            if (nums2[j] > nums2[j+1]){
                int aux = nums2[j];
                nums2[j] = nums2[j+1];
                nums2[j+1] = aux;
            }   
        }
    }

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