class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        c = defaultdict(list)
        for path in paths:
            path = path.split()
            root = path[0]
            for f in path[1:]:
                file_name,_,content = f.partition("(")
                c[content].append(root+'/'+file_name)
        return [x for x in c.values() if len(x) >1]
        