from collections import OrderedDict

def solution(survey, choices):
    score = [0, 0]
    n = len(survey)
    ch_dic = {}

    candidate = ["RT", "TR", "FC", "CF", "MJ", "JM", "AN", "NA"]
    candidate_str = set(list("".join(candidate)))
    for s in candidate_str:
        ch_dic[s] = 0
    for i in range(n):
        if choices[i] - 4 < 0:
            ch_dic[survey[i][0]] += (4 - choices[i])
        elif choices[i] - 4 > 0:
            ch_dic[survey[i][1]] += (choices[i] - 4)

    character = ""

    if ch_dic["R"] >= ch_dic["T"]:
        character += "R"
    else:
        character += "T"

    if ch_dic["C"] >= ch_dic["F"]:
        character += "C"
    else:
        character += "F"

    if ch_dic["J"] >= ch_dic["M"]:
        character += "J"
    else:
        character += "M"

    if ch_dic["A"] >= ch_dic["N"]:
        character += "A"
    else:
        character += "N"


    return character