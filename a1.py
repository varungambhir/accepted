class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        
        l = version1.split(".")
        m = version2.split(".")
        
        xl = len(l)
        yl = len(m)
        
        k = min(xl,yl)
        
        for i in xrange(k):
            x = int(l[i])
            y = int(m[i])
            if x < y:
                return -1
            elif x > y:
                return 1
        ans = 0
        print xl," " ,yl , " " ,k 
        if xl > yl:
            for i in xrange(k, xl):
                x = int(l[i])
                print x
                if 0 == x:
                    continue
                else:
                    ans = 1
                    break
        else:
            for i in xrange(k, yl):
                print i
                x = int(m[i])
                if 0 == x:
                    continue
                else:
                    ans = -1
                    break
        return ans

x = Solution()
print x.compareVersion("1.1","1") , " Ans"
