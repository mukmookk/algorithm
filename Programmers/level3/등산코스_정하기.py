# from collections import defaultdict
# import heapq
# def solution(n, paths, gates, summits):
    
#     summit_sets = set(sorted(summits))
#     graph = defaultdict(list)
#     for (i, j, w) in paths:
#         graph[i].append((j, w))
#         graph[j].append((i, w))
        
#     heap = []
#     max_node_value = max(graph.keys())
#     intensities = [float('inf')] * max(max_node_value + 1, n + 1)
        
#     for gate in gates:
#         heapq.heappush(heap, (0, gate))
#         intensities[gate] = 0
        
#     while heap:
#         cur_intensity, cur_node = heapq.heappop(heap)
#         if cur_node in summit_sets or cur_intensity > intensities[cur_node]:
#             continue
        
#         for n_intensity, neighbor in graph[cur_node]:
#             new_intensity = max(n_intensity, cur_intensity)
#             if new_intensity < intensities[neighbor]:
#                 intensities[neighbor] = new_intensity
#                 heapq.heappush(heap, (new_intensity, neighbor))
        
#     min_intensity = [0, float('inf')]
#     for summit in summits:
#         if intensities[summit] < min_intensity[1]:
#             min_intensity[0] = summit
#             min_intensity[1] = intensities[summit]

#     return min_intensity



from collections import defaultdict
import heapq


# n: 노드 수
# gates: 출입구, sumits: 산봉우리
def solution(n, paths, gates, summits):
    def get_min_intensity():
        heap = []
        visited = [10000001] * (n + 1)
        
        for gate in gates:
            heap.append((0, gate))
            visited[gate] = 0
            
        while heap:
            intensity, node = heapq.heappop(heap)
            
            if node in summit_set or intensity > visited[node]:
                continue
            
            for nei, new_intensity in graph[node]:
                new_intensity = max(intensity, new_intensity)
                if new_intensity < visited[nei]:
                    visited[nei] = new_intensity
                    heapq.heappush(heap, (new_intensity, nei))
        
        answer = [0, float('inf')]
        for summit in summits:
            print(summit, visited[summit])
            if visited[summit] < answer[1]:
                answer[0] = summit
                answer[1] = visited[summit]
        
        return answer
    
    summits.sort()
    summit_set = set(summits)
    
    graph = defaultdict(list)
    for (i, j, w) in paths:
        graph[i].append((j, w))
        graph[j].append((i, w))
    
    return get_min_intensity()