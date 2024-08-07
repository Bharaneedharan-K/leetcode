//leetcode 75

void sortColors(int* nums, int numsSize){
    int lo=0, hi=numsSize-1, i = 0, tmp;
    while (i <= hi) {
        if (nums[i] == 0) {
            tmp = nums[lo];
            nums[lo++] = nums[i];
            nums[i] = tmp;
        }
        if (nums[i] == 2) {
            tmp = nums[hi];
            nums[hi--] = nums[i];
            nums[i] = tmp;
            continue;
        }
        ++i;
    }
}