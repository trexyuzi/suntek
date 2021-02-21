/*There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.*/
#include<stdio.h>
int search(int* nums2, int numsSize, int target){
    for(int i=0;i<numsSize;i++){
        if(nums2[i]==target){
            return i;
        }
    }
    return -1;
}
int main(){
	int numsSize,target,k,temp;
	printf("Enter array size:");
	scanf("%d",&numsSize);
	int nums[numsSize];
	int nums2[numsSize];
	printf("\nEnter array elements:");
	for(int i=0;i<numsSize;i++){
		scanf("%d",&nums[i]);
	}
	printf("\nEnter pivot:");
	scanf("%d",&k);
	printf("\nEnter target:");
	scanf("%d",&target);
	for(int i=0;i<numsSize;i++){
		for(int j=0;j<numsSize;j++){
			if(nums[i]<nums[j]){
				temp=nums[i];
				nums[i]=nums[j];
				nums[j]=temp;
			}
		}
	}
	printf("\nAfter sorting:\n");
	for(int i=0;i<numsSize;i++){
		printf("%d ",nums[i]);
	}
	temp=k;
	for(int i=0;k<numsSize;i++,k++){
		nums2[i]=nums[k];
	}
	k=temp;
	int j=numsSize-k;
	for(int i=0;i<k;i++,j++){
		nums2[j]=nums[i];
	}
	printf("\nAfter rotating on pivot:\n");
	for(int i=0;i<numsSize;i++){
		printf("%d ",nums2[i]);
	}
	printf("\n%d",search(nums2,numsSize,target));
}
