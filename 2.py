a, b = map(int, input().split())
c, d = map(int, input().split())
s1 = min(a, b)
s2 = min(c, d)
s1_indian = max(a, b) / 2
s1_indian = s1_indian if s1_indian <= s1 else s1
s2_indian = max(c, d) / 2
s2_indian = s2_indian if s2_indian <= s2 else s2
print(max(min(s1, s2), s1_indian, s2_indian))