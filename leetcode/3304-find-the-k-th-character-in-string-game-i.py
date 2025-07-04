class Solution:
    # recursion:
    #
    # def kthCharacter(self, k: int) -> str:
    #     def getchar(idx: int) -> str:
    #         if idx == 0:
    #             return "a"

    #         p = 1
    #         while p * 2 <= idx:
    #             p *= 2

    #         prevIdx = idx - p
    #         if prevIdx <= 0:
    #             return "b"
    #         else:
    #             return chr(ord(getchar(prevIdx)) + 1)

    #     return getchar(k - 1)

    # binary magic:
    # https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/solutions/6912907/simple-explanation-for-why-o-1-1-liner-solution-works
    #
    def kthCharacter(self, k: int) -> str:
        return chr(ord("a") + (k - 1).bit_count())
