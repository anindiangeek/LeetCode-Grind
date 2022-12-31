class Solution:
    def allPathsSourceTarget(self, G):
        ans = []
        def dfs(path):
            if path[-1] == len(G)-1: ans.append(path)
            else:
                for child in G[path[-1]]:
                    dfs(path + [child])
        dfs([0])
        return ans