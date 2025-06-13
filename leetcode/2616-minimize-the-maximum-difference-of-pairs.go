// the biggest variable of CPU time is the golang self.
func minimizeMax(nums []int, p int) int {
    sort.Ints(nums)

    left := 0
    right := nums[len(nums) - 1] - nums[0]
    for left < right {
        mid := left + (right - left) / 2

        if isThresholdOnLeft(nums, mid, p) {
            right = mid
        } else {
            left = mid + 1
        }
    }

    return left
}

func isThresholdOnLeft(nums []int, threshold int, p int) bool {
    count := 0
    for i := 0; i < len(nums) - 1 && count < p; i++ {
        if nums[i + 1] - nums[i] <= threshold {
            count += 1
            i += 1 // the loop self will increase 1 for i
        }
    }

    return count >= p
}
