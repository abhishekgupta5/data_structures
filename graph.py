#!/usr/bin/python3

#A directed graph
graph = {'A':['B','C'],
         'B':['C','D'],
         'C':['D'],
         'D':['C'],
         'E':['F'],
         'F':['C']}


#Use of backtracking to find a path from a node to other
def find_path(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        return path
    if start not in graph:
        return None
    for node in graph[start]:
        newpath = find_path(graph, node, end, path)
        if newpath:
            return newpath
    return None

#Find path b/w node 'A' and 'D'
print("A path from 'A' to 'D' is: ", find_path(graph, 'A', 'D'))

def find_all_paths(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        return [path]
    if start not in graph:
        return []
    paths = []
    for node in graph[start]:
        newpaths= find_all_paths(graph, node, end, path)
        for newpath in newpaths:
            paths.append(newpath)
    return paths

#Find all paths b/w node 'A' and 'D'
print("All paths from A and D are: ", find_all_paths(graph, 'A', 'D'))
