#insert, delete, traverse
tree=[[],[],[]]

tree[1].append(int(input()))
next_node=int(input())
if next_node>tree[1]:
	tree[2].append([[],[next_node],[]])
else:
	tree[0].append([[],[next_node],[]])