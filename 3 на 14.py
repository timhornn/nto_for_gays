planks = int(input())
lens = list(map(int, input().split()))
total_len = sum(lens) // planks
index_map = {}

for key, value in enumerate(lens):
    index_map.update({value: key})

print(total_len)
for idx, elem in enumerate(lens):
    plank_we_need = total_len - elem
    if index_map[plank_we_need] != None:
        print(idx+1, index_map[plank_we_need]+1)
        index_map[plank_we_need] = None
        index_map[elem] = None
