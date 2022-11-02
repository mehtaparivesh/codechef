    class Solution:
        def secondGreaterElement(self, nums: List[int]) -> List[int]:
            ARRAYTOBEUSEDLATER = []
            STACKOFTHEANSWER = []
            MYANSWEROFTHEPROBLEM = [-1 for i in nums]
            for INDEX, i in enumerate(nums):
                if not STACKOFTHEANSWER:
                    STACKOFTHEANSWER.append(INDEX)
                else:
                    while ARRAYTOBEUSEDLATER and nums[ARRAYTOBEUSEDLATER[-1]] < i:
                        val = ARRAYTOBEUSEDLATER.pop()
                        MYANSWEROFTHEPROBLEM[val] = i
                    ARRAYTTOBEUSEDCURRENTLY = []
                    while STACKOFTHEANSWER and i > nums[STACKOFTHEANSWER[-1]]:
                        ARRAYTTOBEUSEDCURRENTLY.append(STACKOFTHEANSWER.pop())
                    ARRAYTTOBEUSEDCURRENTLY = ARRAYTTOBEUSEDCURRENTLY[::-1]
                    ARRAYTOBEUSEDLATER.extend(ARRAYTTOBEUSEDCURRENTLY)
                    STACKOFTHEANSWER.append(INDEX)
            return MYANSWEROFTHEPROBLEM