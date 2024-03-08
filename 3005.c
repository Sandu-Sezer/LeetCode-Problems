int maxFrequencyElements(int* nums, int numsSize) {
    if (numsSize <= 0){
        return 0;
    }

    for (int i = 0; i < numsSize - 1; ++i){
        for (int j = 0; j < numsSize - i - 1; ++j){
            if (nums[j] < nums[j+1]){
                int aux = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = aux;
            }
        }
    }

    int finalCounter = 1;
    int frequency = 1;
    int maxFrequency = 1;

    for (int i = 1; i < numsSize; ++i){
        if (nums[i] == nums[i - 1]){
            frequency++;
        } else {
            if (frequency > maxFrequency){
                maxFrequency = frequency;
                finalCounter = 1;
            }
            if (frequency == maxFrequency){
                finalCounter++;
            }
            frequency = 1;
        }
    }

    return finalCounter * maxFrequency;
}