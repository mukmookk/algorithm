def diamond_and_iron_counts(seq):
    return seq[0], seq[1]

def diamond_and_iron_key(seq):
    return diamond_and_iron_counts(seq)

def solution(picks, minerals):
    answer = 0
    upper_bound = 0
    sequences = []
    
    if sum(picks) * 5 < len(minerals):
        minerals = minerals[0:sum(picks)*5]
        
    while upper_bound < len(minerals):
        upper_bound = upper_bound + 5 if upper_bound < len(minerals) else len(minerals)
        sublist = minerals[upper_bound - 5: upper_bound]
        dia = sublist.count("diamond")
        iron = sublist.count("iron")
        stone = sublist.count("stone")
        sequences.append([dia, iron, stone])
    
    sorted_sequences = sorted(sequences, key=diamond_and_iron_key)
    equipments = [[1, 1, 1], [5, 1, 1], [25, 5, 1]]
    for i in range(picks[0]):
        if sorted_sequences:
            answer += sum([x * y for x, y in zip(equipments[0], sorted_sequences.pop())])
        
    for i in range(picks[1]):
        if sorted_sequences:
            answer += sum([x * y for x, y in zip(equipments[1], sorted_sequences.pop())])
        
    for i in range(picks[2]):
        if sorted_sequences:
            answer += sum([x * y for x, y in zip(equipments[2], sorted_sequences.pop())])

    return answer