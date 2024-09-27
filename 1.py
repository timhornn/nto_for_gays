timestamp = int(input())
speed = 0
acceleration = 0
pos = 0
acc_acceleration = 6

for i in range(timestamp):
    pos += speed
    speed += acceleration
    acceleration += acc_acceleration

print(pos)
