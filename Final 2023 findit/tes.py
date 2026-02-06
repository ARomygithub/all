class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def add_node(root, node):
    if node.value < root.value:
        if root.left is None:
            root.left = node
        else:
            add_node(root.left, node)
    else:
        if root.right is None:
            root.right = node
        else:
            add_node(root.right, node)

def get_minimum_color_difference(root, color):
    if root is None:
        return float('inf')
    
    if root.value % 2 == color:
        left_difference = get_minimum_color_difference(root.left, 1 - color)
        right_difference = get_minimum_color_difference(root.right, 1 - color)
        return min(left_difference, right_difference)
    else:
        return min(root.value, get_minimum_color_difference(root.left, color), get_minimum_color_difference(root.right, color))

# Contoh penggunaan
N = int(input("Masukkan jumlah node: "))
root_value = 1
root = Node(root_value)

for i in range(2, N + 1):
    value = int(input("Masukkan nilai node ke-{}: ".format(i)))
    node = Node(value)
    add_node(root, node)

min_difference = get_minimum_color_difference(root, 0)
print("Perbedaan warna terkecil: ", min_difference)